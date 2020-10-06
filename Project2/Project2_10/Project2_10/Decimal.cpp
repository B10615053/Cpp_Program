#include "Decimal.h"



Decimal::Decimal() {
	this->setNumerator(DEFAULT_VALUE_0);
	this->setDenominator(DEFAULT_VALUE_1);
	this->setType(DECIMAL);
	this->setFraction(fractionDivision(DEFAULT_VALUE_0, DEFAULT_VALUE_1));
	this->setIsNegative(false);
}


Decimal::~Decimal() {}

Number& Decimal::operator=(Number& rSide) {
	/* Type of DECIMAL might not be changed */

	this->setNumerator(rSide.getNumerator());
	this->setDenominator(rSide.getDenominator());
	this->setIsNegative(rSide.getIsNegative());
	this->setFraction(rSide.getFraction());

	return (*this);
}

Number& Decimal::operator=(double rSide) {

	string base = "1";

	if (fabs(rSide) <= EPS) {
		this->setNumerator(DEFAULT_VALUE_0);
		this->setDenominator(DEFAULT_VALUE_1);
		this->setFraction(fractionDivision(DEFAULT_VALUE_0, DEFAULT_VALUE_1));
		this->setType(DECIMAL);
		this->setIsNegative(false);

		return (*this);
	}

	while ((int)rSide != rSide) {
		rSide *= 10;
		base = multiple(base, "10");
	}

	int up = (int)rSide;

	string newNumerator = int2String(up);
	string newDenominator = base;

	// negative
	if (newNumerator.at(0) == '-') {
		this->setIsNegative(true);
		newNumerator = newNumerator.substr(1);
	}
	// positive
	else
		this->setIsNegative(false);

	string gcd = getGCD(newNumerator, newDenominator);
	if (!isZero(gcd)) {
		newNumerator = division(newNumerator, gcd);
		newDenominator = division(newDenominator, gcd);
	}

	this->setNumerator(newNumerator);
	this->setDenominator(newDenominator);
	this->setFraction(fractionDivision(newNumerator, newDenominator));
	this->setType(DECIMAL);

	//cout << (getIsNegative() ? "-" : "") << getNumerator() << " / " << getDenominator() << endl;

	return (*this);
}

Number& Decimal::operator=(string express) {
	/**/
	Number a;
	return a;
}