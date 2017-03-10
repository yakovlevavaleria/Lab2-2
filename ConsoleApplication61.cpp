#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
class Book
{
	char Athor[64]; // Автор
	char name[128]; // Название
	int count;
public:
	Book(char Ath[], char nam[], int page) // Конструктор для инициализации полей
	{
		strcpy_s(Athor, Ath); // Копируем строки
		strcpy_s(name, nam); // Копируем строки
		this->count = count;
	}
	Book()
	{
		Athor[0] = name[0] = count = 0;
	}

	void set(char Ath[], char nam[], int count) // Метод для инициализации полей в "пустом" объекте
	{
		strcpy_s(Athor, Ath); // Копируем строки
		strcpy_s(name, nam); // Копируем строки
		this->count = count;
	}

	void print()
	{
		cout << endl << Athor << " " << name << " Count=" << count;
	}
	// Метод для получения числа страниц (обращение к закрытому полю класса)
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
	
	// Второй подход при создании массива объектов используется конструктор без параметров
	// и метод set для инициализации объекта
	Book *pBook;
	pBook = new Book[n]; // Создаем массив объектов, вызывается конструктор без параметров
	char Author[64]; char name[128]; // Буферные массивы для ввода данных с клавиатуры
	int count; // Для ввода числа страниц
	for (int i = 0; i<n; i++) // Массив для ввода объектов
	{
		cout << "Book N=" << (i + 1);
		cout << endl << "Author: "; //cin>>Author;
		cin.ignore(2, '\n');
		cin.getline(Author, 64); // Ввод строки с пробелами
		cout << "name: "; // cin>>Title;
		cin.ignore(2, '\n');
		cin.getline(name, 128); // Ввод строки с пробелами
		cout << "count="; cin >> count;
		pBook[i].set(Author, name, count); // Инициализируем объект
	}
	// Печать для контроля ввода
	for (int i = 0; i<n; i++) pBook[i].print();
	// Поиск книги с максимальным числом страниц
	int max = pBook[0].getcount(),
		imax = 0; // Индекс искомой книги
	for (int i = 1; i<n; i++)
		if (pBook[i].getcount()>max)
		{
			max = pBook[i].getcount();
			imax = i;
		}
	// Печать книги с максим числом страниц
	cout << endl << "max book:";
	pBook[imax].print();
	system("pause");
}
