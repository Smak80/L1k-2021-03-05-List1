#include <iostream>
#include <fstream>
#include "list1.h"

using namespace std;

/// <summary>
/// ������ ��������� ���� � ��������� ������ ���������� �� ����� �����. ���� ������ ����� ������:
/// ������ �������� ��������� � ��������� ������.
/// � ������ ����� �������������� ��� �����: �������� � �������, �� ������� ��� ������� ��������.
/// </summary>
/// <param name="list">����������� ������</param>
/// <param name="filename">��� ����� � ������� ��� ������</param>
/// <returns>
/// ������� ���������� (true) ��� ������������ (false) ������������ ������ ���������� �� �����.
/// </returns>
bool fill_list(list1& list, const char* filename);

/// <summary>
/// ����������� ������ �� ������
/// </summary>
/// <param name="list">������, ���������� �������� ������� �������</param>
void show_list(list1 list);

/// <summary>
/// ����� ��������� ������ � ��������� ��������
/// </summary>
/// <param name="list">������, �������� �������� ������� �������</param>
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
		cout << "�� ������� ������������ ������ �� ���������� �����. :(";
	}
	system("pause");
}

bool fill_list(list1& list, const char* filename)
{
	// ��������� ����
	ifstream f(filename);
	// ��������� ���������� ��������
	if (f.is_open())
	{
		// ������ ���� �� �����
		char* data = new char[30];
		while (!f.eof())
		{
			// ��������� ����� ������
			f.getline(data, 30);
			if (f.fail())
			{
				// ���� ���-�� �� ������� ���������, ������� ������, � ���������� ������ � ������
				f.close();
				clear(list);
				return false;
			}
			int v, p;
			//��������� �������� �� ������ � �������� ������
			auto cnt = sscanf_s(data, "%d %d", &v, &p);
			//� ������ ���������� ���������� ��������
			switch (cnt)
			{
				//���� � ������ ���� ���� ��������, ��������� ��� � ������
			case 1:
				add(list, v);
				break;
				// ���� �������� ��� ��������, �� ��������� �������� v � ������� p.
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
	if (!curr) cout << "������ ����!" << endl;
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