#pragma once
class man
{
	friend class leaner;
public:
	man(char* fam, char* name, int year);
	man();
	~man();
	char* getFam();
	char* getName();
	int getYear();
	void setFam(char* s);
	void setName(char* f);
	void setYear(int s);
private:
	char* fam;
	char* name;
	int year;
};

