#include "Integer.h"



Integer::Integer() : Number() {}

Integer::Integer(string newInt) {
	this->setNumerator(newInt);
	this->setDenominator(DEFAULT_VALUE_1);
	this->setFraction(fractionDivision(newInt, DEFAULT_VALUE_1));
	this->setType(INTEGER);
	this->setIsNegative(false);
}

Integer::~Integer() {}

Number& Integer::operator=(Number& rSide) {
	/* Type of DECIMAL might not be changed */

	// If the type of an Integer has changed to DECIMAL due to operations, change it back to INTEGER
	if(this->getType() == DECIMAL)
		this->setType(INTEGER);
	this->setIsNegative(rSide.getIsNegative());

	string newNumerator = division(rSide.getNumerator(), rSide.getDenominator());
	string newDenominator = "1";

	this->setFraction(fractionDivision(newNumerator, newDenominator));
	this->setNumerator(newNumerator);
	this->setDenominator(newDenominator);

	return (*this);
}

Number& Integer::operator=(double rSide) {

	int int_rSide = (int)rSide;
	string str_rSide = int2String(int_rSide);

	// negative
	if (str_rSide.at(0) == '-') {
		this->setIsNegative(true);
		str_rSide = str_rSide.substr(1);
	}
	// positive
	else
		this->setIsNegative(false);

	this->setNumerator(str_rSide);
	this->setDenominator(DEFAULT_VALUE_1);
	this->setFraction(fractionDivision(str_rSide, DEFAULT_VALUE_1));
	this->setType(INTEGER);

	return (*this);
}

Number& Integer::operator=(string express) {
	Number b;
	return b;
	/**/
}