#include <iostream>
#include <fstream>
#include "list1.h"

using namespace std;

/// <summary>
/// Читает текстовый файл и заполняет список значениями из этого файла. Файл должен иметь формат:
/// Каждое значение находится в отдельной строке.
/// В строке может присутствовать два числа: значение и позиция, на которую его следует добавить.
/// </summary>
/// <param name="list">Формируемый список</param>
/// <param name="filename">Имя файла с данными для списка</param>
/// <returns>
/// Признак успешности (true) или неуспешности (false) формирования списка значениями из файла.
/// </returns>
bool fill_list(list1& list, const char* filename);

/// <summary>
/// Отображение списка на экране
/// </summary>
/// <param name="list">Список, содержимое которого следует вывести</param>
void show_list(list1 list);

/// <summary>
/// Вывод элементов списка с нечетными номерами
/// </summary>
/// <param name="list">Список, элементы которого следует вывести</param>
void show_odd(list1 list);

void main()
{
	setlocale(LC_ALL, "Rus");
	list1 list;
	if (fill_list(list, "data.txt") && list.first)
	{
		show_list(list); // 300 -10 -1 30 1 10 100 200
		remove(list, 0);
		show_list(list); // -10 -1 30 1 10 100 200
		remove(list, 1);
		show_list(list); // -10 30 1 10 100 200
		remove(list, 100);
		show_list(list); // -10 30 1 10 100 200
		remove(list, -10);
		show_list(list); // -10 30 1 10 100 200
		show_odd(list); // 30, 10, 200
		clear(list);
		show_list(list);
	} else
	{
		cout << "Не удалось сформировать список из указанного файла. :(";
	}
	system("pause");
}

bool fill_list(list1& list, const char* filename)
{
	// Открываем файл
	ifstream f(filename);
	// Проверяем успешность открытия
	if (f.is_open())
	{
		// Читаем файл до конца
		char* data = new char[30];
		while (!f.eof())
		{
			// Считываем целую строку
			f.getline(data, 30);
			if (f.fail())
			{
				// Если что-то не удалось прочитать, очищаем список, и прекращаем работу с файлом
				f.close();
				clear(list);
				return false;
			}
			int v, p;
			//Переводим значения из строки в числовой формат
			auto cnt = sscanf_s(data, "%d %d", &v, &p);
			//и узнаем количество полученных значений
			switch (cnt)
			{
				//Если в строке было одно значение, добавляем его в список
			case 1:
				add(list, v);
				break;
				// Если получены два значения, то размещаем значение v в позиции p.
			case 2:
				insert(list, v, p);
			}
		}
		delete[] data;
		f.close();
		return true;
	}
	return false;
}

void show_list(list1 list)
{
	l1_elem* curr = list.first;
	if (!curr) cout << "Список пуст!" << endl;
	else while (curr)
	{
		cout << curr->a << (curr->next ? " " : "\n");
		curr = curr->next;
	}
}

void show_odd(list1 list)
{
	int i = 1;
	while (true)
	{
		int val;
		if (get(list, val, i))
		{
			if (i > 1) cout << " ";
			cout << val;
			i += 2;
		}
		else break;
	}
	cout << endl;
}