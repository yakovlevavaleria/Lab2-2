#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
class Book
{
	char Athor[64]; // �����
	char name[128]; // ��������
	int count;
public:
	Book(char Ath[], char nam[], int page) // ����������� ��� ������������� �����
	{
		strcpy_s(Athor, Ath); // �������� ������
		strcpy_s(name, nam); // �������� ������
		this->count = count;
	}
	Book()
	{
		Athor[0] = name[0] = count = 0;
	}

	void set(char Ath[], char nam[], int count) // ����� ��� ������������� ����� � "������" �������
	{
		strcpy_s(Athor, Ath); // �������� ������
		strcpy_s(name, nam); // �������� ������
		this->count = count;
	}

	void print()
	{
		cout << endl << Athor << " " << name << " Count=" << count;
	}
	// ����� ��� ��������� ����� ������� (��������� � ��������� ���� ������)
	int getcount()
	{
		return count;
	}
};

void main()
{
	cout << "Start program";
	int n;
	cout << endl << "n="; cin >> n;
	
	// ������ ������ ��� �������� ������� �������� ������������ ����������� ��� ����������
	// � ����� set ��� ������������� �������
	Book *pBook;
	pBook = new Book[n]; // ������� ������ ��������, ���������� ����������� ��� ����������
	char Author[64]; char name[128]; // �������� ������� ��� ����� ������ � ����������
	int count; // ��� ����� ����� �������
	for (int i = 0; i<n; i++) // ������ ��� ����� ��������
	{
		cout << "Book N=" << (i + 1);
		cout << endl << "Author: "; //cin>>Author;
		cin.ignore(2, '\n');
		cin.getline(Author, 64); // ���� ������ � ���������
		cout << "name: "; // cin>>Title;
		cin.ignore(2, '\n');
		cin.getline(name, 128); // ���� ������ � ���������
		cout << "count="; cin >> count;
		pBook[i].set(Author, name, count); // �������������� ������
	}
	// ������ ��� �������� �����
	for (int i = 0; i<n; i++) pBook[i].print();
	// ����� ����� � ������������ ������ �������
	int max = pBook[0].getcount(),
		imax = 0; // ������ ������� �����
	for (int i = 1; i<n; i++)
		if (pBook[i].getcount()>max)
		{
			max = pBook[i].getcount();
			imax = i;
		}
	// ������ ����� � ������ ������ �������
	cout << endl << "max book:";
	pBook[imax].print();
	system("pause");
}
