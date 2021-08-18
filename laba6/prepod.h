#pragma once
#include "Common.h"
#include"fio.h"
#include <iostream>
#include <iomanip>
using namespace std;

class prepod : public Common
{
private:
	int departament;
	int status;
	char* subj;
public:
	friend std::ostream& operator<<(std::ostream& os, prepod& temp);
	friend std::istream& operator>> (istream& is, prepod& temp);
	friend int operator==(fio& a, prepod& b);
	prepod& operator=(prepod& temp);
	prepod& operator=(fio& fi);
	static int count;
	prepod();
	prepod(int departament, fio fi, int status);
	static void Addprepod(prepod** t, int n);
	~prepod();
	int getDep();
	fio getFio();
	int getSt();
	char* getSubj();
	void setDep(int d);
	void setFio(fio f);
	void setSt(int s);
	void setSubj(char* s);
	static void searchDep(prepod* t, int n);
	static void searchSubject(prepod* t, int n);
	static void loadTeacher(const char* fileName, prepod** t, int& n);
	static void saveTeacher(const char* fileName, prepod* t, int n);
	static void printTable();
	static void sortPrepod(prepod* t, int n);
	static void searchFio(prepod* t, int n);
};



