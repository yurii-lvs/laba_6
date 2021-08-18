#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;
#include "leaner.h"

leaner::leaner(man student, char* faculty, int group) {
	setStu(student);
	setFac(faculty);
	setGr(group);
}

leaner::leaner()
{

}

leaner::~leaner() {
}
man leaner::getStu() {
	return student;
}

char* leaner::getFac() {
	return faculty;
}
int leaner::getGr() {
	return group;
}
void leaner::setStu(man d) {
	student = d;
}
void leaner::setFac(char* f) {
	faculty = f;
}
void leaner::setGr(int s) {
	group = s;
}

void leaner::printTable()
{
	cout << endl;
	cout << "Список всех студентов" << endl;
	cout << "Фамилия";
	cout << setw(18) << "Имя";
	cout << setw(19) << "Курс";
	cout << setw(24) << "Факультет";
	cout << setw(21) << "Группа" << endl;
	for (int i = 0; i < 140; i++) {
		cout << "-";
	}
	cout << endl;
}

std::ostream& operator<< (std::ostream& os, leaner& temp)
{
	cout << temp.student.getFam();
	for (int j = 0; j < 15 - strlen(temp.student.getFam()) + 7; j++) cout << " ";
	cout << temp.student.getName();
	for (int j = 0; j < 15 - strlen(temp.student.getName()) + 3; j++) cout << " ";
	cout << temp.student.getYear();
	for (int j = 0; j < 18; j++) cout << " ";
	cout << temp.faculty;
	for (int j = 0; j < 15 - strlen(temp.faculty) + 9; j++) cout << " ";
	cout << temp.group << endl;
	return os;
}

void leaner::AddLeaner(leaner** l, int k) {
	*l = (leaner*)realloc(*l, (k + 1) * sizeof(leaner));
	cout << endl;
	cout << "Добаваление нового студента" << endl;
	char buff[100];
	bool check = 1;
	while (check) {
		try {
			while (getchar() != '\n');
			cout << "Введите фамилию: ";
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!isalpha(buff[i])) throw 0; //если не буквы
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только буквы! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
		check = 1;
		while (check) {
			try {
				cout << "Введите имя: ";
				cin >> buff;
				for (int i = 0; i < strlen(buff); i++) {
					if (!isalpha(buff[i])) throw 0; //если не буквы
				}
				check = false;
			}
			catch (int error) {
				cout << endl << "Допустимы только буквы! Попробуйте еще!" << endl;
				cin.clear();
				cin.ignore(4096, '\n');
				check = true;
			}
		}
	}

	l[0][k].student.fam = (char*)malloc(strlen(buff) + 1);
	strcpy(l[0][k].student.fam, buff);
	l[0][k].student.name = (char*)malloc(strlen(buff) + 1);
	strcpy(l[0][k].student.name, buff);
	check = 1;
	while (check) {
		try {
			cout << "Введите курс: ";
			cin >> (l[0][k].student.year);
			if (!cin) throw 0; //если не цифра
			if (l[0][k].student.year > 5 || l[0][k].student.year < 1) throw - 1;
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только цифры 1-5! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	check = 1;
	while (check) {
		try {
			cout << "Введите факультет: ";
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!isalpha(buff[i])) throw 0; //если не буквы
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только буквы! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	l[0][k].faculty = (char*)malloc(strlen(buff) + 1);
	strcpy(l[0][k].faculty, buff);
	check = 1;
	while (check) {
		try {
			cout << "Введите группу: ";
			cin >> l[0][k].group;
			if (!cin) throw 0; //если не цифра
			if (l[0][k].student.year > 5 || l[0][k].student.year < 1) throw - 1;
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только числа! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
}

void leaner::sortLeaner(leaner* l, int k)
{
	for (int j = 0; j < k - 1; j++)
	{
		for (int i = j + 1; i < k; i++)
		{
			if (strcmp(l[j].student.getFam(), l[i].student.getFam()) > 0)
			{
				char* p = l[j].student.getFam();
				l[j].student.setFam(l[i].student.getFam());
				l[i].student.setFam(p);
				p = l[j].student.getName();
				l[j].student.setName(l[i].student.getName());
				l[i].student.setName(p);
				swap(l[j].student.year, l[i].student.year);
				p = l[j].faculty;
				strcpy(l[i].faculty, p);
				l[i].faculty = p;
				swap(l[j].group, l[i].group);
			}
		}
	}
	cout << endl << "Сортировка выполнена";
}

void leaner::searchGr(leaner* l, int k)
{
	int g;
	cout << endl;
	cout << "Поиск по группе" << endl;
	bool check = 1;
	while (check) {
		try {
			cout << "Введите группу: ";
			cin >> g;
			if (!cin) throw 0; //если не цифра
			if (g > 5 || g < 1) throw - 1;
			check = false;
		}
		catch (int error) {
			cout << endl << "Допустимы только числа! Попробуйте еще!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	printTable();
	for (int i = 0; i < k; i++) {
		if (g == l[i].group) cout << l[i];
	}
	for (int i = 0; i < 140; i++) {
		cout << "-";
	}
	cout << endl;
}

void leaner::loadLeaner(const char* fileName, leaner** l, int& k) {
	FILE* f;
	char buff[100];
	if ((fopen(fileName, "r+")) == NULL) {
		cout << "Файла нет создание" << endl;
		f = fopen(fileName, "w+");
		fclose(f);
	}
	f = fopen(fileName, "r");
	for (int i = 0; !feof(f); i++) {
		*l = (leaner*)realloc(*l, (k + 1) * sizeof(leaner));
		fscanf(f, "%s", buff);
		l[0][i].faculty = (char*)malloc(strlen(buff) + 1);
		strcpy(l[0][i].faculty, buff);
		fscanf(f, "%s", buff);
		l[0][i].student.fam = (char*)malloc(strlen(buff) + 1);
		strcpy(l[0][i].student.fam, buff);
		fscanf(f, "%s", buff);
		l[0][i].student.name = (char*)malloc(strlen(buff) + 1);
		strcpy(l[0][i].student.name, buff);
		fscanf(f, "%s", buff);
		l[0][i].student.year = atof(buff);
		fscanf(f, "%s", buff);
		l[0][i].group = atof(buff);
		k++;
	}
	fclose(f);
}

void leaner::saveLeaner(const char* fileName, leaner* l, int k) {
	FILE* f;
	f = fopen(fileName, "w");
	for (int i = 0; i < k; i++)
	{
		fprintf(f, "%s ", l[i].faculty);
		fprintf(f, "%s ", l[i].student.fam);
		fprintf(f, "%s ", l[i].student.name);
		fprintf(f, "%d ", l[i].student.year);
		fprintf(f, "%d ", l[i].group);
	}
	fclose(f);
}
