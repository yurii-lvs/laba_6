#include "man.h"
man::man(char* fam, char* name, int year) {
	setFam(fam);
	setName(name);
	setYear(year);
}

man::man() {

}

man::~man() {
}
char* man::getFam() {
	return fam;
}

char* man::getName() {
	return name;
}
int man::getYear() {
	return year;
}
void man::setFam(char* d) {
	fam = d;
}
void man::setName(char* f) {
	name = f;
}
void man::setYear(int s) {
	year = s;
}
