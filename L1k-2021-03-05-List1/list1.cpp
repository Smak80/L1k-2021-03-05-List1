#include "list1.h"

void add(list1& list, int val)
{
	// �������� ������ ��������
	auto new_el = new l1_elem;
	new_el->a = val;

	// ���������� ������� ������
	if (!list.first)
	{
		// ������ �� ����. ������� ���������� ������ � ���� ������
		list.first = new_el;
	} else
	{
		// ������ ���, ��������� � ��� ���������� ��������
		auto curr = list.first;
		while (curr->next) curr = curr->next;
		// ���������� ������� ������ �������� � ������
		curr->next = new_el;
	}
}

void insert(list1& list, int val, int pos)
{
	// �������� ������ ��������
	auto new_el = new l1_elem;
	new_el->a = val;

	if (list.first && pos > 0)
	{
		// ��������� �� ������� ������� � ������
		l1_elem* curr = list.first;
		// ������� ���������
		int p = 0;
		// �������� �� ��������� ������ �� �������, �������������� ������� �������
		// ���� �� ���������� �������� ������.
		while (curr->next && p < pos - 1)
		{
			curr = curr->next;
			p++;
		}
		// ���������� ������ �������� � ������.
		new_el->next = curr->next;
		curr->next = new_el;
	} else
	{
		// ������ ��� ���, ��� ������� ������� = 0
		new_el->next = list.first;
		list.first = new_el;
	}
}

bool get(const list1& list, int& val, int pos)
{
	// ���� ������ ��� ��� ������� ������������� �������.
	if (!list.first || pos < 0) return false;

	int p = 0; // ������� ���������
	l1_elem* curr = list.first; // ��������� �� ������� ������� ������
	// ������� ��������� ������� � ������
	while (curr && p < pos)
	{
		curr = curr->next;
		p++;
	}
	// ����� ����� ��������� curr ����� ��������� ����� �������� ��������,
	// ���� ���� ������ nullptr, ���� ����������� ������� ��������� ����� ��������� ������.
	if (curr)
	{
		// ���������� ��������� ��������
		val = curr->a;
		return true;
	}
	return false;
}

bool remove(list1& list, int pos)
{
	// ���������, ��� ������ �� ���� � ������� �������� ���������������
	if (pos < 0 || !list.first) return false;
	// ���� ��������� ������ �������
	if (pos == 0)
	{
		l1_elem* del = list.first;
		list.first = list.first->next;
		delete del;
		return true;
	}
	// ���� ��������� ������� �� ��������
	int p = 0;
	l1_elem* curr = list.first;
	// ����� ��������, ��������������� ����������
	while (curr->next && p < pos - 1)
	{
		curr = curr->next;
		p++;
	}
	// ���� �� ������� ��������� ���� ��� ����, ������
	// �� ����� ��������� ��������
	if (curr->next)
	{
		// ��������� ��������
		l1_elem* del = curr->next;
		curr->next = curr->next->next;
		delete del;
		return true;
	}
	// ������� ������.
	return false;
}

void clear(list1& list)
{
	while (list.first)
	{
		l1_elem* del = list.first;
		list.first = list.first->next;
		delete del;
	}
}

