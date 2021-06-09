/*Лаболаторная работа 1 по дисциплине МРЗвИс
 * Выполнена студентом группы 921702 БГУИР
 * Середов Андрей Сергеевич
 * Файл описывает описывает логику и архитектуру класса RestoringDivision
 * 12.04.2021 Добавлено авторство
 * 12.04.2021 Добавлена логика класса
 * 12.04.2021 Добавлено отображение промежуточного результата
 * "Алгоритм деления с востановлением" https://drive.google.com/drive/folders/0B3Bkrx-aVpkSQTVwd3hvbFlfOG8
 * Алгоритм деления со сдвигом влево
 * Разработано консольное приложение с имитацией конвейрной архиектуры для деления заданного множества пар двоичных чисел
 * */

#pragma once
#include <iostream>
#include "Converter.h"
#include "DivisionElements.h"
using namespace std;
class Division
{
public:
	void step(DivisionElements &elementsForDivision);
};

void Division::step(DivisionElements &elementsForDivision)
{
	Converter converter;
	elementsForDivision.step++;
	bool cheak = true;
	for (int i = 6; i >= 0; i--) { elementsForDivision.P[i + 1] = elementsForDivision.P[i]; }
	elementsForDivision.P[0] = elementsForDivision.A[7];
	for (int i = 6; i >= 0; i--) { elementsForDivision.A[i + 1] = elementsForDivision.A[i]; }
	elementsForDivision.A[0] = 0;
	cout << "-----------------------------" << endl;
	cout << "STAGE: " << elementsForDivision.step << endl;
	cout << "NUMBER OF ELEMENTS: " <<elementsForDivision.numberOfElements << endl;
	cout <<"SHIFT"<< endl;
	elementsForDivision.printElements();



	for (int i = 7; i >= 0; i--)
	{
		if (elementsForDivision.P[i] < elementsForDivision.B[i]) {
			cheak = false;
			break;
		}
		else if (elementsForDivision.P[i] > elementsForDivision.B[i])
		{
			break;
		}
	}

	cout << "SUBTRACT" << endl;
	elementsForDivision.printElementsSubtract();

	if (cheak)
	{
		elementsForDivision.A[0] = 1;
		for (int i = 0; i < 8; i++)
		{
			if (elementsForDivision.P[i] == 0 && elementsForDivision.B[i] == 1) {
				elementsForDivision.P[i] = 10;
				for (int j = i + 1; j < 8; j++)
				{
					if (elementsForDivision.P[j] == 1) {
						elementsForDivision.P[j] = 0;
						break;
					}
					else
					{
						elementsForDivision.P[j] = 1;
					}
				}
			}
		}
		for (int i = 0; i < 8; i++)
		{
			if (elementsForDivision.P[i] == 0 && elementsForDivision.B[i] == 0) {
				elementsForDivision.P[i] = 0;
			}
			if (elementsForDivision.P[i] == 1 && elementsForDivision.B[i] == 0) {
				elementsForDivision.P[i] = 1;
			}
			if (elementsForDivision.P[i] == 1 && elementsForDivision.B[i] == 1) {
				elementsForDivision.P[i] = 0;
			}
			if (elementsForDivision.P[i] == 10 && elementsForDivision.B[i] == 1)
			{
				elementsForDivision.P[i] = 1;
			}
		}
	}
	else
	{
		elementsForDivision.A[0] = 0;
	}
	cout << "SET BIT" << endl;
	elementsForDivision.printElements();
	cout << "-----------------------------"<<endl;
}

