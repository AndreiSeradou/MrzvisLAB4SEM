/*Лаболаторная работа 1 по дисциплине МРЗвИс
 * Выполнена студентом группы 921702 БГУИР
 * Середов Андрей Сергеевич
 * Файл описывает описывает логику добавление пар в конвеер
 * 12.04.2021 Добавлено авторство
 * 12.04.2021 Добавлена логика класса
 * 12.04.2021 Добавлено отображение промежуточного результата
 * "Алгоритм деления с востановлением" https://drive.google.com/drive/folders/0B3Bkrx-aVpkSQTVwd3hvbFlfOG8
 * Алгоритм деления со сдвигом влево
 * Разработано консольное приложение с имитацией конвейрной архиектуры для деления заданного множества пар двоичных чисел
 * */

#include <iostream>
#include <vector>
#include "RestoringDivision.h"
#include "DivisionElements.h"
#include "PipelineAlgorithm.h"
#include "Converter.h"
using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	int A, B,numberPair=0,numberOfPairs;
	DivisionElements elementsForDivision;
	Converter converter;
	PipelineAlgorithm pipelineAlgorithm;
	Division divisionAlgorithm;
	vector<DivisionElements> elementsForPipelineAlgorithm;
	vector<DivisionElements> initialElements;

	cout << "Введите количество пар: ";
	cin >> numberOfPairs;
	for (int i = 0; i < numberOfPairs; i++)
	{
		numberPair++;
		link:
		cout << "Введите число A для " << numberPair << " пары: ";
		cin >> A;
		if (A>255){
			cout << "Число должно быть меньше 256" << endl;
			goto link;
		}
		elementsForDivision.A = converter.toBinary(A);
		link1:
		cout << "Введите число B для " << numberPair << " пары: ";
		cin >> B;
		if (B > 255) 
		{ 
			cout << "Число должно быть меньше 256" << endl;
			goto link1; 
		}
		elementsForDivision.B = converter.toBinary(B);
		elementsForDivision.numberOfElements = i;
		elementsForPipelineAlgorithm.push_back(elementsForDivision);
		initialElements.push_back(elementsForDivision);
	}
	cout << "/////////////////////////////////////////////////////" << endl;
	cout << "Elements for Division: " << endl;
	for (int i = 0; i < elementsForPipelineAlgorithm.size(); i++)
	{
		elementsForPipelineAlgorithm[i].printElements();
		cout << endl;
	}
	cout << "/////////////////////////////////////////////////////" << endl;
	pipelineAlgorithm.algorithm(elementsForPipelineAlgorithm);

	cout << "RESULTS"<<endl;

	for (int i = 0; i < elementsForPipelineAlgorithm.size(); i++)
	{
		cout << "----------" << endl;
		cout << converter.toInt(initialElements[i].A);
		cout << "  /  ";
		cout << converter.toInt(initialElements[i].B);
		cout << endl;
		elementsForPipelineAlgorithm[i].printElementsToInt();
		cout << "----------" << endl;
	}

}

