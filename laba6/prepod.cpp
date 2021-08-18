#define _CRT_SECURE_NO_WARNINGS
#include "fio.h"
#include <iostream>
#include <iomanip>
using namespace std;
#include "prepod.h"

int prepod::count = 0;

void prepod::printTable()
{
	cout << endl;
	cout << "������ ���� ��������������" << endl;
	cout << "�������";
	cout << setw(18) << "���";
	cout << setw(23) << "��������";
	cout << setw(22) << "�������";
	cout << setw(28) << "������ ������";
	cout << setw(22) << "�������" << endl;
	for (int i = 0; i < 140; i++) {
		cout << "-";
	}
	cout << endl;
}
prepod::prepod() {

}

std::ostream& operator<< (ostream& os, prepod& temp)
{
	cout << temp.getFIO().getFam();
	for (int j = 0; j < 15 - strlen(temp.getFIO().getFam()) + 7; j++) cout << " ";
	cout << temp.getFIO().getName();
	for (int j = 0; j < 15 - strlen(temp.getFIO().getName()) + 3; j++) cout << " ";
	cout << temp.getFIO().getFath();
	int s = 0;
	for (int j = 0; j < 15 - strlen(temp.getFIO().getFath()) + 8; j++) cout << " ";
	if (temp.departament == 1) cout << "�����";
	if (temp.departament == 2) cout << "��";
	if (temp.departament == 3) cout << "��";
	if (temp.departament == 1) s = 5;
	if (temp.departament == 2) s = 2;
	if (temp.departament == 3) s = 2;
	for (int j = 0; j < 15 - s + 7; j++) cout << " ";
	if (temp.status == 1) cout << "�������������";
	if (temp.status == 2) cout << "������";
	if (temp.status == 3) cout << "������ ����";
	if (temp.status == 1) s = 13;
	if (temp.status == 2) s = 6;
	if (temp.status == 3) s = 11;
	for (int j = 0; j < 15 - s + 13; j++) cout << " ";
	cout << temp.subj << endl;
	return os;
}


int operator==(fio& a, prepod& b) {
	if ((strcmp(a.getFam(), b.getFIO().getFam()) || strcmp(a.getName(), b.getFIO().getName()) || strcmp(a.getFath(), b.getFIO().getFath())) == 0)
		return 0;
	else
		return 1;
}

prepod& prepod::operator=(prepod& temp)
{
	*this = temp.getFIO();
	this->setDep(temp.getDep());
	this->setSt(temp.getSt());
	this->setSubj(temp.getSubj());
	return *this;
}

prepod& prepod::operator=(fio& ob)
{
	this->getFIO().setFam(ob.getFam());
	this->getFIO().setName(ob.getName());
	this->getFIO().setFather(ob.getFath());
	return *this;
}

void prepod::setSubj(char* s)
{
	delete[] this->subj;
	this->subj = new char[strlen(s) + 1];
	strcpy(this->subj, s);
}


prepod::prepod(int departament, fio fi, int status) {
	setDep(departament);
	setFio(fi);
	setSt(status);
}

std::istream& operator>> (istream& is, prepod& t)
{
	bool check = 1;
	while (check) {
		try {
			cout << "������� ������� (1-�����, 2-��, 3-��): ";
			cin >> t.departament;
			if (!cin) throw 0; //���� �� �����
			if (!(t.departament == 1 || t.departament == 2 || t.departament == 3)) throw - 1;
			check = false;
		}
		catch (int error) {
			cout << endl << "��������� ������ ����� 1-3! ���������� ���!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	cin >> t.getFIO();
	check = 1;
	while (check) {
		try {
			cout << "������� ������ ������ (1- �������������, 2- ������,3-������ ����): ";
			cin >> t.status;
			if (!cin) throw 0; //���� �� �����
			if (!(t.status == 1 || t.status == 2 || t.status == 3)) throw -1;
			check = false;
		}
		catch (int error) {
			cout << endl << "��������� ������ ����� 1-3! ���������� ���!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	char buff[100];
	check = 1;
	while (check) {
		try {
			cout << "������� �������: ";
			while (getchar() != '\n');
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!((buff[i] >= 'A' && buff[i] <= 'Z') || (buff[i] >= 'a' && buff[i] <= 'z'))) throw 0; //���� �� �����
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "��������� ������ ���������� �����! ���������� ���!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	t.subj = (char*)malloc(strlen(buff) + 1);
	strcpy(t.subj, buff);
}

std::istream& operator>> (istream& is, fio& ob)
{
	bool check = 1;
	char buff[100];
	while (check) {
		try {
			cout << "������� �������: ";
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!((buff[i]>='A' && buff[i]<='Z') || (buff[i] >= 'a' && buff[i] <= 'z'))) throw 0;
				/*if (!((int(unsigned char(buff[i]))>=128 && int(unsigned char(buff[i]))<=175) || (int(unsigned char(buff[i]))>=224 && int(unsigned char(buff[i]))<=241))) throw 0;*/
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "��������� ������ ���������� �����! ���������� ���!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	ob.setSur(buff);
	check = 1;
	while (check) {
		try {
			cout << "������� ���: ";
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!((buff[i] >= 'A' && buff[i] <= 'Z') || (buff[i] >= 'a' && buff[i] <= 'z'))) throw 0; //���� �� �����
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "��������� ������ ���������� �����! ���������� ���!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	ob.setNam(buff);
	check = 1;
	while (check) {
		try {
			cout << "������� ��������: ";
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!((buff[i] >= 'A' && buff[i] <= 'Z') || (buff[i] >= 'a' && buff[i] <= 'z'))) throw 0; //���� �� �����
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "��������� ������ ���������� �����! ���������� ���!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	ob.setFather(buff);
	return is;
}

void prepod::Addprepod(prepod** t, int n) {
	*t = (prepod*)realloc(*t, (n + 1) * sizeof(prepod));
	cout << endl;
	cout << "����������� ������ �������������" << endl;
	cin >> t[0][n];
}
prepod::~prepod() {
}
int prepod::getDep() {
	return departament;
}

char* prepod::getSubj()
{
	return subj;
}

fio prepod::getFio() {
	return getFIO();
}
int prepod::getSt() {
	return status;
}
void prepod::setDep(int d) {
	departament = d;
}
void prepod::setFio(fio f) {
	setFIO(f);
}
void prepod::setSt(int s) {
	status = s;
}



void prepod::loadTeacher(const char* fileName, prepod** t, int& n) {
	FILE* f;
	char buff[100];
	if ((fopen(fileName, "r+")) == NULL) {
		cout << "����� ��� ��������" << endl;
		f = fopen(fileName, "w+");
		fclose(f);
	}
	f = fopen(fileName, "r");
	for (int i = 0; !feof(f); i++) {
		*t = (prepod*)realloc(*t, (n + 1) * sizeof(prepod));
		fscanf(f, "%s", buff);
		t[0][i].departament = atof(buff);
		fscanf(f, "%s", buff);
		t[0][i].getFIO().fam = (char*)malloc(strlen(buff) + 1);
		strcpy(t[0][i].getFIO().fam, buff);
		fscanf(f, "%s", buff);
		t[0][i].getFIO().name = (char*)malloc(strlen(buff) + 1);
		strcpy(t[0][i].getFIO().name, buff);
		fscanf(f, "%s", buff);
		t[0][i].getFIO().father = (char*)malloc(strlen(buff) + 1);
		strcpy(t[0][i].getFIO().father, buff);
		fscanf(f, "%s", buff);
		t[0][i].status = atof(buff);
		fscanf(f, "%s", buff);
		t[0][i].subj = (char*)malloc(strlen(buff) + 1);
		strcpy(t[0][i].subj, buff);
		n++;
	}
	fclose(f);
}

void prepod::saveTeacher(const char* fileName, prepod* t, int n) {
	FILE* f;
	f = fopen(fileName, "w");
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "%d ", t[i].departament);
		fprintf(f, "%s ", t[i].getFIO().fam);
		fprintf(f, "%s ", t[i].getFIO().name);
		fprintf(f, "%s ", t[i].getFIO().father);
		fprintf(f, "%d ", t[i].status);
		fprintf(f, "%s ", t[i].subj);
	}
	fclose(f);
}

void prepod::searchDep(prepod* t, int n)
{
	bool check = 1;
	cout << endl;
	cout << "����� �� �������" << endl;
	int temp;
	while (check) {
		try {
			cout << "������� ������� (1-�����, 2-��, 3-��): ";
			cin >> temp;
			if (!cin) throw 0; //���� �� �����
			if (!(temp == 1 || temp == 2 || temp == 3)) throw - 1;
			check = false;
		}
		catch (int error) {
			cout << endl << "��������� ������ ����� 1-3! ���������� ���!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	printTable();
	for (int i = 0; i < n; i++) {
		if (t[i].departament == temp) cout << t[i];
	}
	for (int i = 0; i < 140; i++) {
		cout << "-";
	}
	cout << endl;
}

void prepod::sortPrepod(prepod* t, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = j + 1; i < n; i++)
		{
			if (strcmp(t[j].getFIO().getFam(), t[i].getFIO().getFam()) > 0)
			{
				char* p = t[j].getFIO().getFam();
				t[j].getFIO().setFam(t[i].getFIO().getFam());
				t[i].getFIO().setFam(p);
				p = t[j].getFIO().getName();
				t[j].getFIO().setName(t[i].getFIO().getName());
				t[i].getFIO().setName(p);
				p = t[j].getFIO().getFath();
				t[j].getFIO().setFather(t[i].getFIO().getFath());
				t[i].getFIO().setFather(p);
				swap(t[j].status, t[i].status);
				swap(t[j].departament, t[i].departament);
				p = t[j].subj;
				strcpy(t[i].subj, p);
				t[i].subj = p;
			}
		}
	}
	cout << endl << "���������� ���������";
}

void prepod::searchSubject(prepod* t, int n)
{
	cout << endl;
	cout << "����� �� ��������" << endl;
	char buff[100];
	char* temp;
	bool check = 1;
	while (check) {
		try {
			cout << "������� �������: ";
			cin >> buff;
			for (int i = 0; i < strlen(buff); i++) {
				if (!isalpha(buff[i])) throw 0; //���� �� �����
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "��������� ������ �����! ���������� ���!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	temp = (char*)malloc(strlen(buff) + 1);
	strcpy(temp, buff);
	printTable();
	for (int i = 0; i < n; i++) {
		if (strcmp(t[i].subj, temp) == 0) cout << t[i];
	}
	for (int i = 0; i < 140; i++) {
		cout << "-";
	}
	cout << endl;
}

void prepod::searchFio(prepod* t, int n)
{
	fio a;
	bool flag = 0;
	cout << endl;
	cout << "����� ������������� �� ���" << endl;
	char sur[100]; char im[100]; char ot[100];
	bool check = 1;
	while (check) {
		try {
			cout << "������� �������: ";
			while (getchar() != '\n');
			cin >> sur;
			for (int i = 0; i < strlen(sur); i++) {
				if (!isalpha(sur[i])) throw 0; //���� �� �����
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "��������� ������ �����! ���������� ���!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	check = 1;
	while (check) {
		try {
			cout << "������� ���: ";
			cin >> im;
			for (int i = 0; i < strlen(im); i++) {
				if (!isalpha(im[i])) throw 0; //���� �� �����
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "��������� ������ �����! ���������� ���!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	check = 1;
	while (check) {
		try {
			cout << "������� ��������: ";
			cin >> ot;
			for (int i = 0; i < strlen(ot); i++) {
				if (!isalpha(ot[i])) throw 0; //���� �� �����
			}
			check = false;
		}
		catch (int error) {
			cout << endl << "��������� ������ �����! ���������� ���!" << endl;
			cin.clear();
			cin.ignore(4096, '\n');
			check = true;
		}
	}
	/*prepod* mas = (prepod*)malloc(sizeof(prepod));*/
	a = fio(sur, im, ot);
	for (int i = 0; i < n; i++)
	{
		if (!(a == t[i]))
		{
			cout << endl << "������������� ������! " << endl;
			flag = 1;
			/*mas[0] = t[i];*/
			prepod::printTable();
			cout << t[i];
			for (int i = 0; i < 140; i++) {
				cout << "-";
			}
			cout << endl;
			break;
		}
	}
	if (flag == 0)
		cout << "������ ������������� ���!" << endl;
	flag = 0;
}

