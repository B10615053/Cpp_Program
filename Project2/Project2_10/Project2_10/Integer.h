#pragma once

#include "Number.h"

class Integer : public Number
{
public:
	Integer();
	Integer(string);
	~Integer();

	Number& operator=(Number&);
	Number& operator=(double);
	Number& operator=(string);
};

