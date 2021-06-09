// MRZiIS.cpp : Лабораторная работа 2 по МРЗвИС вариант №17
//Автор: Яценко Ярослав, гр.721701

// Лабораторная работа 2 по дисциплине МРЗвИС
// Выполнена студентом группы 721701
// БГУИР Яценко Ярослав Сергеевич
// Версия 1.0, 25.05.2019

#include <iostream>
#include <math.h>
#include <conio.h>
#include <algorithm>
#include "Matrix.h"

using namespace std;
double aArrowB(int i, int j, int k);
double bArrowA(int i, int j, int k);
double c(int i, int j);
double mountainF(int i, int j);
double slopeD(int i, int j);
double moutainFslopeD(int i, int j);
double f(int i, int j, int k);
double aMountainB(int i, int j, int k);

Matrix a; // pxm
Matrix b; // mxq
Matrix e; // 1xm
Matrix g; // pxq

int n;
int totalCounter;

int sumCounter = 0;
int diffirenceCounter = 0;
int multiplicationCounter = 0;
int comparingCounter = 0;

int aPointBCounter = 0;
int bPointACounter = 0;

int conjunctionOfFCounter = 0;
int disjunctionOfDCounter = 0;

int aConjunctionBCounter = 0;
int multiplyConjuctionOfFAndDisjunctionOfDCounter = 0;

int elementCCounter = 0;
int elementFCounter = 0;

int main()
{
	a.setMatrixVector(vector<vector<double>> { {0.7}, { -0.3 } });
	b.setMatrixVector(vector<vector<double>> { {-0.4, 1} });
	e.setMatrixVector(vector<vector<double>> { {0.4} });
	g.setMatrixVector(vector<vector<double>> { {-0.2, -0.3}, { 0.8, 0.9 } });
	vector<vector<double>> vec;
	/*int p, m, q;
	* 
	cout << "Enter sizes p, m, q: ";
	cin >> p >> m >> q;
	cout << endl << "Enter matrix A: ";
	for (int i = 0; i < p; i++) {
		vec.push_back({});
		for (int j = 0; j < m; j++) {
			double value;
			cin >> value;
			vec[i].push_back(value);
		}
	}
	a.setMatrixVector(vec);
	vec.clear();
	cout << endl << "Enter matrix B: ";
	for (int i = 0; i < m; i++) {
		vec.push_back({});
		for (int j = 0; j < q; j++) {
			double value;
			cin >> value;
			vec[i].push_back(value);
		}
	}
	b.setMatrixVector(vec);
	vec.clear();
	cout << endl << "Enter matrix E: ";
	for (int i = 0; i < 1; i++) {
		vec.push_back({});
		for (int j = 0; j < m; j++) {
			double value;
			cin >> value;
			vec[i].push_back(value);
		}
	}
	e.setMatrixVector(vec);
	vec.clear();
	cout << endl << "Enter matrix G: ";
	for (int i = 0; i < p; i++) {
		vec.push_back({});
		for (int j = 0; j < q; j++) {
			double value;
			cin >> value;
			vec[i].push_back(value);
		}
	}
	g.setMatrixVector(vec);
	vec.clear();*/
	for (int i = 0; i < a.getMatrixVector().size(); i++) {
		vec.push_back({});
		for (int j = 0; j < b.getMatrixVector()[0].size(); j++) {
			vec[i].push_back(c(i, j));
		}
	}
	Matrix C;
	C.setMatrixVector(vec);
	for (int i = 0; i < C.getMatrixVector().size(); i++) {
		for (int j = 0; j < C.getMatrixVector()[i].size(); j++) {
			cout << C.getMatrixVector()[i][j] << " ";
		}
		cout << endl;
	}
}

double c(int i, int j) {
	totalCounter += 12;
	elementCCounter++;

	sumCounter += 2;
	multiplicationCounter += 7;
	diffirenceCounter += 3;

	//cout << "mountainF " << mountainF(i, j) << endl << "slopedD " << slopeD(i, j) << endl << "moutainFslopeD " << moutainFslopeD(i, j) << endl << "g.getMatrixVector " << g.getMatrixVector()[i][j] << endl;
	return mountainF(i, j) * (3 * g.getMatrixVector()[i][j] - 2) * g.getMatrixVector()[i][j] + (slopeD(i, j) + (4 * moutainFslopeD(i, j) - 3 * slopeD(i, j)) * g.getMatrixVector()[i][j]) * (1 - g.getMatrixVector()[i][j]);
}

double mountainF(int i, int j) {
	totalCounter += 12;
	elementFCounter++;

	multiplicationCounter += 7;
	diffirenceCounter += 3;
	sumCounter += 2;
	
	double rez = 1.0;
	for (int k = 0; k < b.getMatrixVector().size(); k++) {
		rez *= f(i, j, k);
	}
	return rez;
}

double slopeD(int i, int j) {
	double rez = 1.0;
	for (int k = 0; k < b.getMatrixVector().size(); k++) {
		rez *= 1 - aArrowB(i, j, k);
	}
	return 1 - rez;
}

double moutainFslopeD(int i, int j) {
	vector<double> rez{ 0 };
	rez.push_back(mountainF(i, j) + slopeD(i, j) - 1);
	return rez[distance(rez.begin(), max_element(rez.begin(), rez.end()))];
}

double f(int i, int j, int k) {
	return aArrowB(i, j, k) * (2 * e.getMatrixVector()[0][k] - 1) * e.getMatrixVector()[0][k] + bArrowA(i, j, k) * (1 + (4 * aArrowB(i, j, k) - 2) * e.getMatrixVector()[0][k]) * (1 - e.getMatrixVector()[0][k]);
}

double aArrowB(int i, int j, int k) {
	vector<double> rez{ 1 };
	rez.push_back(1 - a.getMatrixVector()[i][k] + b.getMatrixVector()[k][j]);
	return rez[distance(rez.begin(), min_element(rez.begin(), rez.end()))];
}

double bArrowA(int i, int j, int k) {
	vector<double> rez{ 1 };
	rez.push_back(1 + a.getMatrixVector()[i][k] - b.getMatrixVector()[k][j]);
	return rez[distance(rez.begin(), min_element(rez.begin(), rez.end()))];
}

double aMountainB(int i, int j, int k) {
	vector<double> rez{ 0 };
	rez.push_back(a.getMatrixVector()[i][k] + b.getMatrixVector()[k][j] - 1);
	return rez[distance(rez.begin(), max_element(rez.begin(), rez.end()))];
}
