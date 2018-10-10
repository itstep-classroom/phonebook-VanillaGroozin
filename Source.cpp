#include "phonebook.h"

int main() {
	char com[20];
	cout << "Welcome to PhoneBook Management System" << endl;
	cout << endl;
	if (started == false) {
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
		started = true;
	}
	cout << "\nEnter your command: ";


	while (cin >> com) {
		if (strcmp(com, "help") == 0) {
			help();
		}
		if (strcmp(com, "update") == 0) {
			update();
		}
		if (strcmp(com, "sort") == 0) {
			sort();
		}
		if (strcmp(com, "search") == 0) {
			search();
		}
		if (strcmp(com, "remove") == 0) {
			remove();
		}
		if (strcmp(com, "create") == 0) {
			create();
		}
		if (strcmp(com, "saveas") == 0) {
			cin >> bookname;
			save();
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
		if (strcmp(com, "show") == 0) {
			show();
		}
		if (strcmp(com, "add") == 0) {
			add();
		}
		cout << "\nEnter your command: ";
	}
}
