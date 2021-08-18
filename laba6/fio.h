#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
class fio
{
	friend class prepod;
	friend class Common;
	friend std::istream& operator>> (istream& is, fio& ob);
public:
	fio(char* fam, char* name, char* father);
	fio();
	~fio();
	char* getFam();
	char* getName();
	char* getFath();
	void setFam(char* f);
	void setName(char* n);
	void setFath(char* o);
	void setSur(char* surname);
	void setNam(char* name);
	void setFather(char* father);
private:
	char* fam;
	char* name;
	char* father;
};
