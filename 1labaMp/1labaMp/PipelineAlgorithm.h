/*Лаболаторная работа 1 по дисциплине МРЗвИс
 * Выполнена студентом группы 921702 БГУИР
 * Середов Андрей Сергеевич
 * Файл описывает описывает логику и архитектуру класса PipelineAlgorithm
 * 12.04.2021 Добавлено авторство
 * 12.04.2021 Добавлена логика класса
 * 12.04.2021 Добавлено отображение промежуточного результата
 * "Алгоритм деления с востановлением" https://drive.google.com/drive/folders/0B3Bkrx-aVpkSQTVwd3hvbFlfOG8
 * Алгоритм деления со сдвигом влево
 * Разработано консольное приложение с имитацией конвейрной архиектуры для деления заданного множества пар двоичных чисел
 * */

#pragma once

#include <vector>
#include "DivisionElements.h"
#include "RestoringDivision.h"

class PipelineAlgorithm
{
public:
	void algorithm(vector<DivisionElements>& elements);
};

void PipelineAlgorithm::algorithm(vector<DivisionElements>& elements)
{
	Division divisionAlgorithm;
	int controlElements = 1,counter=1;
	cout << "-----------------------------" << endl;
	while (elements[elements.size()-1].step!=8)
	{
		cout << "_______TIME_______: " << counter << endl;
		for (int j = 0; j < controlElements; j++)
		{
			if (elements[j].step!=8)
			{
				divisionAlgorithm.step(elements[j]);
			}
		}
		if (controlElements<elements.size())
		{
			controlElements++;
		}
		counter ++ ;
	}
}