#pragma once
#ifndef CONTACT_H
#define CONTACT_H
#include <fstream>
#include <iostream>
using namespace std;

struct Contact { // структура контакта
	char name[30];
	char phone[15];
};

Contact* book; // динамический массив контактов
int n = 0;  // кол-во контактов в памяти
int m = 0;
char bookname[30]; // текущее имя файла
bool saved = true;
bool loaded = false;
bool started = false;
int x = 1;
#endif
