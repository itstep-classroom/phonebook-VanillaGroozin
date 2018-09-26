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
bool loaded = false;

void load() {
	ifstream fin(bookname);
	fin >> n;

	if (m != 0) delete[] book;

	m = n + 5;
	book = new Contact[m];

	for (int i = 0; i < n; i++) {
		fin >> book[i].name >> book[i].phone;
	}
	cout << bookname << " loaded\n" << endl;
	loaded = true;
	fin.close();
	cout << endl;
}

void save() {
	if (loaded) {
		ofstream fout(bookname);
		fout << n << endl;
		for (int i = 0; i < n; i++) {
			fout << book[i].name << " " << book[i].phone << endl;
		}
		cout << "saved as " << bookname << endl;
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
	cout << bookname << " was created." << endl;
	saved = false;
	cout << endl;
}

void show() {
	if (loaded) {
		for (int i = 0; i < n; i++)
		{
			cout  << i+1 << ". " << book[i].name << " " << book[i].phone << endl;
		}
	}
	else {
		cout << "You need to load the book first" << endl;
	}
	cout << endl << "----------------------------------\n"; 
}

void remove() {
	if (loaded == false) {
		cout << "\nEnter the book name : ";
		cin >> bookname;
		load();
	}
	show(); int x;
	cout << "\nEnter the number of contact you want to remove: \n";
	cin >> x; 
	cout << "Contact " << book[x-1].name << " was removed.";
	for (int i = x-1; i < n; i++) {
		swap(book[i].name, book[i + 1].name);
		swap(book[i].phone, book[i + 1].phone);
	}
	
	n--;
	cout << endl;
}

void add() {
	if (loaded == false) {
		cout << "\nEnter the book name : ";
		cin >> bookname;
		load();
	}
	cout << "\nEnter the name :";
	cin >> book[n].name;
	cout << "\nEnter th number :";
	cin >> book[n].phone;
	n++;
	saved = false;
	cout << endl;
}

int main() {
	char com[20];
	cout << "Welcome to PhoneBook Management System" << endl;
	cout << endl;
	if (loaded == false) {
		cout << endl << "-------------------\n";
		cout << "1. create" << endl;
		cout << "2. add" << endl;
		cout << "3. save" << endl;
		cout << "4. load" << endl;
		cout << "5. show" << endl;
		cout << "6. remove" << endl;
		cout << "7. exit" << endl;
		cout << "--------------------\n";
	}
	cout << "\nEnter your command: ";


	while (cin >> com) {
		if (strcmp(com, "remove") == 0) {
			remove();
		}
		if (strcmp(com, "create") == 0) {
			create();
		}
		if (strcmp(com, "load") == 0) {
			cin >> bookname;
			load();
		}
		if (strcmp(com, "exit") == 0) {
			if (saved == false) {
				cout << "\nDo you want to save before leaving? Y/N" << endl;
				char YN;
				cin >> YN;
				if (YN == 'Y' || YN == 'y') {
					save(); break;
				}
				else if (YN == 'N' || YN == 'n') {
					break;
				}
				else cout << "\nTry again or learn to read" << endl;
			}
			else break;
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
		cout << "1. create" << endl;
		cout << "2. add" << endl;
		cout << "3. save" << endl;
		cout << "4. load" << endl;
		cout << "5. show" << endl;
		cout << "6. remove" << endl;
		cout << "7. exit" << endl;
	
		cout << "\nEnter your command: ";
	}

}
