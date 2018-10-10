#pragma once
#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "contact.h"
void load() {
	ifstream fin(bookname);
	fin >> n;
	if (fin.is_open()) {
		if (m != 0) delete[] book;

		m = n + x;
		book = new Contact[m];

		for (int i = 0; i < n; i++) {
			fin >> book[i].name >> book[i].phone;
		}

		cout << bookname << " loaded\n" << endl << "-------------------\n";
		loaded = true;

		fin.close();
		cout << endl;
	}
	else {
		cout << bookname << " doesn't exist\n" << endl << "-------------------\n";
		fin.close();
		cout << endl;
	}
}

void save() {
	if (loaded) {
		ofstream fout(bookname);
		fout << n << endl;
		for (int i = 0; i < n; i++) {
			fout << book[i].name << "," << book[i].phone << endl;
		}
		cout << "saved as " << bookname << endl << "-------------------\n";
		fout.close();
	}
	else {
		cout << "You need to load the book first" << endl;
	}
	cout << endl;
}

void create() {
	m = 10;
	n = 0;
	book = new Contact[m];
	cout << endl << "\nEnter the book name: ";
	cin >> bookname;
	cout << bookname << " was created." << endl << "-------------------\n";;
	saved = false;
	cout << endl;
}

void show() {
	cout << endl << "-------------------\n";
	if (loaded) {
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << ". " << book[i].name << " " << book[i].phone << endl;
		}
	}
	else {
		cout << "\n-------------------\nFirst you have to load a book. \n\nEnter the book name : ";
		cin >> bookname;
		load();
	}
	cout << endl << "-------------------\n" << m;

}

void remove() {
	if (loaded == false) {
		cout << "\n-------------------\nFirst you have to load a book. \n\nEnter the book name : ";
		cin >> bookname;
		load();
	}
	show(); int x;
	cout << "\nEnter the number of contact you want to remove: \n";
	cin >> x;
	cout << "Contact " << book[x - 1].name << " was removed.\n" << "-------------------\n";

	for (int i = x - 1; i < n; i++) {
		swap(book[i].name, book[i + 1].name);
		swap(book[i].phone, book[i + 1].phone);
	}

	n--;
	cout << endl;
	saved = false;
}

void search() {
	if (loaded == false) {
		cout << "\n-------------------\nFirst you have to load a book. \n\nEnter the book name : ";
		cin >> bookname;
		load();
	}
	char cont[20];
	cout << "Wacha lookin for?\n";
	cin >> cont;
	int x = 0;
	cout << "\n";
	for (int i = 0; i < n; i++) {
		if (strstr(book[i].name, cont) != nullptr || strstr(book[i].phone, cont) != nullptr) {
			cout << i + 1 << ". " << book[i].name << " " << book[i].phone << endl;
			x++;
		}
	}
	cout << "\n" << x << " contacts found.\n";

}

void sort() {
	if (loaded == false) {
		cout << "\n-------------------\nFirst you have to load a book. \n\nEnter the book name : ";
		cin >> bookname;
		load();
	}
	cout << "Sort by name(0) or number(1)?\n";
	int option; cin >> option;
	if (option == 0) {
	sortName:
		bool sorted = true;
		for (int i = 0; i < n - 1; i++) {
			if (tolower(book[i].name[0]) > tolower(book[i + 1].name[0])) {
				swap(book[i].name, book[i + 1].name);
				swap(book[i].phone, book[i + 1].phone);
				sorted = false;
			}
		}
		if (sorted == false) goto sortName;
	}
	else if (option == 1) {
	sortNum:
		bool sorted = true;
		for (int i = 0; i < n - 1; i++) {
			if ((book[i].phone[0]) >(book[i + 1].phone[0])) {
				swap(book[i].name, book[i + 1].name);
				swap(book[i].phone, book[i + 1].phone);
				sorted = false;
			}
		}
		if (sorted == false) goto sortNum;

	}
	saved = false;
	show();
	cout << endl << endl << bookname << " was sorted\n" << endl << "-------------------\n";
}

void update() {
	if (loaded == false) {
		cout << "\n-------------------\nFirst you have to load a book. \n\nEnter the book name : ";
		cin >> bookname;
		load();
	}
	cout << "\nEnter the number of contact you want to update: \n";
	int x; cin >> x;
	cout << "\nEnter the name :";
	cin >> book[x - 1].name;
	cout << "\nEnter the number :";
	cin >> book[x - 1].phone;
	saved = false;
}
void add() {
add:
	char YN;
	if (loaded == false) {
		cout << "\n-------------------\nFirst you have to load a book. \n\nEnter the book name : ";
		cin >> bookname;
		load();
	}
	cout << "\nEnter the name :";
	cin >> book[n].name;
	cout << "\nEnter the number :";
	cin >> book[n].phone;
	n++; x++;
	cout << endl << "Do you want to finish? Y/N\n";
	cout << endl << "-------------------\n";  cin >> YN;
	if (YN == 'N' || YN == 'n') goto add;
	saved = false;
}
void help() {
	cout << endl << "-------------------\n";
	cout << "-create" << endl;
	cout << "-add" << endl;
	cout << "-save / saveas" << endl;
	cout << "-load" << endl;
	cout << "-show" << endl;
	cout << "-search" << endl;
	cout << "-sort" << endl;
	cout << "-update" << endl;
	cout << "-remove" << endl;
	cout << "-exit" << endl;
	cout << "-------------------\n";
}
#endif
