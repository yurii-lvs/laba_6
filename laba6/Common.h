#pragma once
#include "fio.h"
class Common
{
private:
	fio fi;
public:
	fio& getFIO();
	void setFIO(fio f);
};

