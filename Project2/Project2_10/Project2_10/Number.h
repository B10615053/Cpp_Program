#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "BigNumberOperation.h"

#define DEFAULT_VALUE_1 ("1")
#define DEFAULT_VALUE_0 ("0")
#define EPS 0.0000000000000007
#define pause system("PAUSE")

using namespace std;
using namespace BigMethod;

enum NumberType { INTEGER, DECIMAL };

class Number
{
public:
	Number();
	~Number();

	// Getter & Setter =================
	string getNumerator();
	void setNumerator(string);

	string getDenominator();
	void setDenominator(string);

	NumberType getType();
	void setType(NumberType);

	bool getIsNegative();
	void setIsNegative(bool);

	fractionString getFraction();
	void setFraction(fractionString);
	// =================================

	void string2FractionString(string, string);
	void string2FractionString(Number);

	// ex: 1.2 -> 6 / 5 -> setNumerator(6), setDenominator(5)
	void fractionString2String(fractionString);
	void fractionString2String(string, string);
	friend Number fractionString2Number(fractionString);

	friend ostream& operator<<(ostream&, Number&);
	friend istream& operator>>(istream&, Number&);

	friend Number& operator+(Number&, Number&);
	friend Number& operator-(Number&);
	friend Number& operator-(Number&, Number&);
	friend Number& operator*(Number&, Number&);
	friend Number& operator/(Number&, Number&);
	friend Number& operator^(Number&, Number&);
	friend Number& operator!(Number&);

	friend Number& factorial(Number&);

	//Number& operator=(Number&);

private:
	string numerator; // ¤À¤l
	string denominator; // ¤À¥À
	NumberType type; // Integer or Decimal
	bool isNegative; // positive or negative

	string fraction; // ex: 23.4432, 0.002921

protected:
};
