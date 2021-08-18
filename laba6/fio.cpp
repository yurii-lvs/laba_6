#define _CRT_SECURE_NO_WARNINGS
#include "fio.h"
#include <iostream>
using namespace std;

fio::fio() {

}
fio::fio(char* fam, char* name, char* father)
{
	setFam(fam); setName(name); setFath(father);
}
fio:: ~fio() {
}
char* fio::getFam() {
	return fam;
}
char* fio::getName() {
	return name;
}
char* fio::getFath() {
	return father;
}

void fio::setFam(char* f) {
	fam = f;
}
void fio::setName(char* n) {
	name = n;
}
void fio::setFath(char* o) {
	father = o;
}

void fio::setSur(char* surname) {
	/*delete[] this->fam;*/
	this->fam = new char[strlen(surname) + 1];
	strcpy(this->fam, surname);
}

void fio::setNam(char* name) {
	/*delete[] this->name;*/
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void fio::setFather(char* father) {
	/*delete[] this->father;*/
	this->father = new char[strlen(father) + 1];
	strcpy(this->father, father);
}
