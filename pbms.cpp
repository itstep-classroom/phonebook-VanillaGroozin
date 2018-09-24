// + load
// + save
// + create
// + exit
// add
// remove
// search
// sort

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

void load() {
	ifstream fin(bookname);
	fin >> n;

	if (m != 0) delete[] book;

	m = n + 5;
	book = new Contact[m];

	for (int i = 0; i < n; i++) {
		fin >> book[i].name >> book[i].phone;
	}
	cout << bookname << " loaded" << endl;
	fin.close();
}

void save() {
	ofstream fout(bookname);
	fout << n << endl;
	for (int i = 0; i < n; i++) {
		fout << book[i].name << " " << book[i].phone << endl;
	}
	cout << "saved as " << bookname << endl;
	fout.close();
}

void create() {
	m = 10;
	n = 0;
	book = new Contact[m];
	cout << bookname << " was created." << endl;
}

void show() {
	cout << bookname << (saved ? " saved" : " not saved") << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i+1 << ". " << book[i].name << " " << book[i].phone << endl;
	}
}

void del() {
	cout << "enter the book" << endl;
	cin >> bookname;
	load();
	int x;
	cout << "enter the number of contact u want to delete" << endl;
	cin >> x;

}

void add() {
	cout << "enter the book" << endl;
	cin >> bookname;
	load();
	cout << "Name :" << endl;
	cin >> book[n].name;
	cout << "Num :" << endl;
	cin >> book[n].phone;
	n++;
	save();
}

int main() {
	char com[20];
	cout << "Welcome to PhoneBook Management System" << endl;
	cout << "\nEnter your command: ";
	while (cin >> com) {
		if (strcmp(com, "create") == 0) {
			strcpy_s(bookname, "noname_book.txt");
			create();
		}
		if (strcmp(com, "load") == 0) {
			cin >> bookname;
			load();
		}
		if (strcmp(com, "exit") == 0) {
			break;
		}
		if (strcmp(com, "save") == 0) {
			save();
		}
		if (strcmp(com, "saveas") == 0) {
			cin >> bookname;
			save();
		}
		if (strcmp(com, "show") == 0) {
			show();
		}
		if (strcmp(com, "add") == 0) {
			add();
		}
		if (strcmp(com, "delete") == 0) {
			delete();
		}
		cout << "\nEnter your command: ";
	}

}
