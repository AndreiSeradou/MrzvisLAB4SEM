/*Лаболаторная работа 1 по дисциплине МРЗвИс
 * Выполнена студентом группы 921702 БГУИР
 * Середов Андрей Сергеевич
 * Файл описывает описывает логику и архитектуру класса Converter
 * 12.04.2021 Добавлено авторство
 * 12.04.2021 Добавлена логика класса
 * 12.04.2021 Добавлено отображение промежуточного результата
 * "Алгоритм деления с востановлением" https://drive.google.com/drive/folders/0B3Bkrx-aVpkSQTVwd3hvbFlfOG8
 * Алгоритм деления со сдвигом влево
 * Разработано консольное приложение с имитацией конвейрной архиектуры для деления заданного множества пар двоичных чисел
 * */

#pragma once
#include <vector>

class Converter
{
public:
	std::vector<int> toBinary(int number);
	int toInt(std::vector<int> number);
};


std::vector<int> Converter::toBinary(int number)
{
	std::vector<int> result;

	while (number) {
		result.insert(result.cend(), number % 2);
		number /= 2;
	}

	while (result.size() != 8)
		result.insert(result.cend(), false);

	return result;
}

inline int Converter::toInt(std::vector<int> number)
{
	int result=0,coefficient=1;
	for (int i = 0; i < 8; i++)
	{
		result += number[i] * coefficient;
		coefficient *= 2;
	}
	return result;
}