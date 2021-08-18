#pragma once
#include "man.h"
#include "Common.h"
#include <iostream>
#include <iomanip>
using namespace std;
class leaner : public Common
{
private:
	man student;
	char* faculty;
	int group;
public:
	friend std::ostream& operator<<(std::ostream& os, leaner& temp);
	leaner(man student, char* faculty, int group);
	leaner();
	~leaner();
	man getStu();
	char* getFac();
	int getGr();
	void setStu(man s);
	void setFac(char* f);
	void setGr(int s);
	friend int operator==(man& a, leaner& b);
	static int count;
	leaner(int departament, man fi, int status);
	static void AddLeaner(leaner** t, int n);
	static void searchGr(leaner* l, int k);
	static void loadLeaner(const char* fileName, leaner** l, int& k);
	static void saveLeaner(const char* fileName, leaner* l, int k);
	static void sortLeaner(leaner* l, int k);
	static void printTable();
};




