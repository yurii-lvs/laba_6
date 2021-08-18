#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "prepod.h"
#include "fio.h"
#include "leaner.h"
#include "man.h"

using namespace std;

void printMenu()
{
	cout << endl;
	cout << "Меню" << endl;
	cout << "1 - Добавить преподавателя" << endl;
	cout << "2 - Распечатать информацию о всех преподавателях" << endl;
	cout << "3 - Поиск преподавателя по кафедре" << endl;
	cout << "4 - Поиск преподавателя по предмету" << endl;
	cout << "5 - Поиск преподавателя по фио" << endl;
	cout << "6 - Сортировка по фио преподователей" << endl;
	cout << "7 - Добавить студента" << endl;
	cout << "8 - Распечатать информацию о всех студентах" << endl;
	cout << "9 - Поиск студента по группе" << endl;
	cout << "10 - Сортировка по фио студентов" << endl;
	cout << "0 - Выход " << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	prepod* t;
	leaner* l;
	int n = 0, k = 0, menu;
	t = (prepod*)malloc(n * sizeof(prepod));
	l = (leaner*)malloc(k * sizeof(leaner));
	prepod::loadTeacher("data.txt", &t, n);
	leaner::loadLeaner("datal.txt", &l, k);
	n--;
	k--;
	bool check = true;
	while (1) {
		check = 1;
		printMenu();
		while (check)
		{
		TryAgain:
			try {
				cout << "Пункт меню: ";
				cin >> menu;
				if (!cin) throw - 1; //если menu не типа int выбрасывается исключение 
				if (menu > 10 || menu < 0) throw - 1;
				check = false;
			}
			catch (int error) {
				cout << endl << "Допустимы только цифры 1-10 и 0! Попробуйте еще!" << endl;
				cin.clear();
				cin.ignore(4096, '\n');
				check = true;
			}
		}
		switch (menu) {

		case 1:
			prepod::Addprepod(&t, n);
			prepod::count++;
			n++;
			break;

		case 2: prepod::printTable();
			for (int i = 0; i < n; i++) cout << t[i];
			for (int i = 0; i < 140; i++) {
				cout << "-";
			}
			cout << endl;
			break;

		case 3: prepod::searchDep(t, n);

			break;


		case 4: prepod::searchSubject(t, n);

			break;

		case 5:
			prepod::searchFio(t, n);
			break;

		case 6:
			prepod::sortPrepod(t, n);
			break;

		case 7:
			leaner::AddLeaner(&l, k);
			k++;
			break;

		case 8:
			leaner::printTable();
			for (int i = 0; i < k; i++) cout << l[i];
			for (int i = 0; i < 140; i++) {
				cout << "-";
			}
			cout << endl;
			break;

		case 9:
			leaner::searchGr(l, k);
			break;

		case 10:
			leaner::sortLeaner(l, k);
			break;

		case 0: prepod::saveTeacher("data.txt", t, n);
			leaner::saveLeaner("datal.txt", l, k);
			free(t);
			free(l);
			return 0;
			break;

		default:cout << "Введите нужную цифру!" << endl;
			goto TryAgain;
			break;
		}
	}
}