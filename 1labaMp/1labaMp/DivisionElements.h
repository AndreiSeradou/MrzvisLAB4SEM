/*������������ ������ 1 �� ���������� ������
 * ��������� ��������� ������ 921702 �����
 * ������� ������ ���������
 * ���� ��������� ��������� ������ � ����������� ������ DivisionElements 
 * 12.04.2021 ��������� ���������
 * 12.04.2021 ��������� ������ ������
 * 12.04.2021 ��������� ����������� �������������� ����������
 * "�������� ������� � ��������������" https://drive.google.com/drive/folders/0B3Bkrx-aVpkSQTVwd3hvbFlfOG8
 * �������� ������� �� ������� �����
 * ����������� ���������� ���������� � ��������� ���������� ���������� ��� ������� ��������� ��������� ��� �������� �����
 * */

#pragma once
#include <vector>
#include "Converter.h"
using namespace std;

class DivisionElements
{
public:
	DivisionElements();
	void printElementsSubtract();
	void printElements();
	void printElementsToInt();
	int step = 0;
	int numberOfElements;
	vector<int> A;
	vector<int> B;
	vector<int> P;
};

DivisionElements::DivisionElements()
{
	for (int i = 0; i < 8; i++)
	{
		this->P.push_back(0);
	}
}

inline void DivisionElements::printElements()
{
	cout << "***********************" << endl;
	cout << "A: ";
	for (int i = 7; i >= 0; i--){ cout << A[i]; }
	cout <<"  ";
	cout << "B: ";
	for (int i = 7; i >= 0; i--) { cout << B[i]; }
	cout << endl;
	cout << "P: ";
	for (int i = 7; i >= 0; i--) { cout << P[i]; }
	cout << endl;
	cout << "***********************" << endl;
}

inline void DivisionElements::printElementsToInt()
{
	Converter converter1;
	cout << "NUMBER OF ELEMENTS ANSWER: " << numberOfElements << endl;
	cout << "Answer: "<<converter1.toInt(A)<<endl;
	cout << "Remainder: " << converter1.toInt(P) << endl;
}

inline void DivisionElements::printElementsSubtract()
{
	Converter converter1;
	cout << "***********************" << endl;
	cout << "P: ";
	for (int i = 7; i >= 0; i--) { cout << P[i]; }
	cout <<" - ";
	cout << "B: ";
	for (int i = 7; i >= 0; i--) { cout << B[i]; }
	cout << " = ";
	vector<int> result;
	if (converter1.toInt(P)-converter1.toInt(B)<0)
	{
		cout << "-";
		result=converter1.toBinary((-(converter1.toInt(P) - converter1.toInt(B))));
		for (int i = 7; i >= 0; i--) { cout << result[i]; }
	}
	else
	{
		result = converter1.toBinary((converter1.toInt(P) - converter1.toInt(B)));
		for (int i = 7; i >= 0; i--) { cout << result[i]; }
	}
	cout << endl;
	cout << "***********************" << endl;
}