#pragma once

#include "Number.h"

class Decimal : public Number
{
public:
	Decimal();
	~Decimal();

	Number& operator=(Number&);
	Number& operator=(double);
	Number& operator=(string);
};

