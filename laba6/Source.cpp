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
	cout << "����" << endl;
	cout << "1 - �������� �������������" << endl;
	cout << "2 - ����������� ���������� � ���� ��������������" << endl;
	cout << "3 - ����� ������������� �� �������" << endl;
	cout << "4 - ����� ������������� �� ��������" << endl;
	cout << "5 - ����� ������������� �� ���" << endl;
	cout << "6 - ���������� �� ��� ��������������" << endl;
	cout << "7 - �������� ��������" << endl;
	cout << "8 - ����������� ���������� � ���� ���������" << endl;
	cout << "9 - ����� �������� �� ������" << endl;
	cout << "10 - ���������� �� ��� ���������" << endl;
	cout << "0 - ����� " << endl;
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
				cout << "����� ����: ";
				cin >> menu;
				if (!cin) throw - 1; //���� menu �� ���� int ������������� ���������� 
				if (menu > 10 || menu < 0) throw - 1;
				check = false;
			}
			catch (int error) {
				cout << endl << "��������� ������ ����� 1-10 � 0! ���������� ���!" << endl;
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

		default:cout << "������� ������ �����!" << endl;
			goto TryAgain;
			break;
		}
	}
}