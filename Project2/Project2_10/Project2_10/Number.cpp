#include "Number.h"
#include "Expression.h"



#pragma region Constructors and destructors
Number::Number() {
	type = INTEGER;
	numerator = DEFAULT_VALUE_0;
	denominator = DEFAULT_VALUE_1;
	fraction = fractionDivision(numerator, denominator);
	isNegative = false;
}

Number::~Number() {}
#pragma endregion

#pragma region Getters and setters
string Number::getNumerator() {
	return numerator;
}

void Number::setNumerator(string newNumerator) {
	numerator = newNumerator;
	return;
}

string Number::getDenominator() {
	return denominator;
}

void Number::setDenominator(string newDenominator) {
	denominator = newDenominator;
	return;
}

NumberType Number::getType() {
	return type;
}

void Number::setType(NumberType newType) {
	type = newType;
	return;
}

bool Number::getIsNegative() {
	return isNegative;
}

void Number::setIsNegative(bool newIsNegative) {
	isNegative = newIsNegative;
	return;
}

fractionString Number::getFraction() {
	return fraction;
}

void Number::setFraction(fractionString newFraction) {
	fraction = newFraction;
	return;
}
#pragma endregion

void Number::string2FractionString(string nume, string deno) {
	/**/
	fraction = fractionDivision(nume, deno);
	cout << "Fraction style = " << fraction << endl;
	return;
}

void Number::string2FractionString(Number num) {
	string nume = num.getNumerator();
	string deno = num.getDenominator();

	string2FractionString(nume, deno);
	return;
}

void Number::fractionString2String(string num, string frac) {
	int k;
	string base = "1";

	for (k = 0; k < frac.length(); k++)
		base += "0";
	
	string newNumerator = num + frac; newNumerator = deletePreZero(newNumerator);
	string newDenominator = base;

	if (isZero(newNumerator))
		newDenominator = DEFAULT_VALUE_1;

	string gcd = getGCD(newNumerator, newDenominator);
	if (!isZero(gcd)) {
		newNumerator = division(newNumerator, gcd);
		newDenominator = division(newDenominator, gcd);
	}

	this->setNumerator(newNumerator);
	this->setDenominator(newDenominator);

	return;
}

void Number::fractionString2String(fractionString fstr) {
	int k, len = fstr.length(), dotLoc = 0;

	for (k = 0; k < len; k++) {
		if (fstr[k] == '.') {
			dotLoc = k;
			break;
		}
	}

	string num = fstr.substr(0, dotLoc);
	string frac = fstr.substr(dotLoc + 1);

	cout << "|" << num << "|" << frac << "|" << endl;

	fractionString2String(num, frac);
	return;
}

Number fractionString2Number(fractionString fstr) {
	Number* res = new Number;

	int k, len = fstr.length(), dotLoc = 0;

	for (k = 0; k < len; k++) {
		if (fstr[k] == '.') {
			dotLoc = k;
			break;
		}
	}

	string num = fstr.substr(0, dotLoc);
	string frac = fstr.substr(dotLoc + 1);
	string base = "1";

	for (k = 0; k < frac.length(); k++)
		base += "0";

	string newNumerator = num + frac; newNumerator = deletePreZero(newNumerator);
	string newDenominator = base;

	if (isZero(newNumerator))
		newDenominator = DEFAULT_VALUE_1;

	string gcd = getGCD(newNumerator, newDenominator);
	if (!isZero(gcd)) {
		newNumerator = division(newNumerator, gcd);
		newDenominator = division(newDenominator, gcd);
	}

	res->setNumerator(newNumerator);
	res->setDenominator(newDenominator);
	res->setType(DECIMAL);
	res->setIsNegative(false);

	return (*res);
}

ostream& operator<<(ostream& outStream, Number& rSide) {
	switch (rSide.type) {
		case INTEGER: 
			//cout << "Integer: ";
			cout << (rSide.getIsNegative() ? "-" : "") << rSide.numerator; break;
		case DECIMAL: 
			//cout << "Decimal: ";
			//cout << "(" << (rSide.getIsNegative() ? "-" : "") << rSide.numerator << "/" << rSide.denominator << ")";
			rSide.setFraction(fractionDivision(rSide.getNumerator(), rSide.getDenominator()));
			cout << (rSide.getIsNegative() ? "-" : "") << rSide.fraction;

			break;
	}

	return outStream;
}

istream& operator>>(istream& inStream, Number& rSide) {
	string inp;

	cin >> inp;

	/**/

	return inStream;
}

//Number& Number::operator=(Number& rSide) {
//	this->type = rSide.type;
//	this->numerator = rSide.numerator;
//	this->denominator = rSide.denominator;
//	this->isNegative = rSide.isNegative;
//
//	return (*this);
//}

// Add
Number& operator+(Number& lSide, Number& rSide) {
	Number* res = new Number;
	string newNumerator;
	string newDenominator;

	// INTEGER + INTEGER
	if (lSide.getType() == INTEGER && rSide.getType() == INTEGER) {
		res->setType(INTEGER);

		// pos + pos
		if (!lSide.getIsNegative() && !rSide.getIsNegative())
			newNumerator = add(lSide.getNumerator(), rSide.getNumerator());
	 
		// pos + neg
		else if (!lSide.getIsNegative() && rSide.getIsNegative())
			newNumerator = minuz(lSide.getNumerator(), rSide.getNumerator());

		// neg + pos
		else if (lSide.getIsNegative() && !rSide.getIsNegative())
			newNumerator = minuz(rSide.getNumerator(), lSide.getNumerator());

		// neg + neg
		else if (lSide.getIsNegative() && rSide.getIsNegative()) {
			string tmps = add(lSide.getNumerator(), rSide.getNumerator());

			if (isZero(tmps))
				newNumerator = "0";
			else
				newNumerator = "-" + tmps;
		}

		newDenominator = DEFAULT_VALUE_1;

		if (newNumerator.at(0) == '-') {
			res->setIsNegative(true);
			newNumerator = newNumerator.substr(1);
		}
		else
			res->setIsNegative(false);

		res->setNumerator(newNumerator);
		res->setDenominator(newDenominator);

		//cout << res->getIsNegative() << " | " << res->getNumerator() << "/" << res->getDenominator();
	}

	// DECIMAL + DECIMAL
	else {
		res->setType(DECIMAL);

		string lcm = getLCM(lSide.getDenominator(), rSide.getDenominator());
		string ia = multiple(division(lcm, lSide.getDenominator()), lSide.getNumerator());
		string ib = multiple(division(lcm, rSide.getDenominator()), rSide.getNumerator());

		// pos + pos
		if (!lSide.getIsNegative() && !rSide.getIsNegative())
			newNumerator = add(ia, ib);

		// pos + neg
		else if (!lSide.getIsNegative() && rSide.getIsNegative())
			newNumerator = minuz(ia, ib);

		// neg + pos
		else if (lSide.getIsNegative() && !rSide.getIsNegative())
			newNumerator = minuz(ib, ia);

		// neg + neg
		else if (lSide.getIsNegative() && rSide.getIsNegative()) {
			string tmps = add(ia, ib);

			if (isZero(tmps))
				newNumerator = "0";
			else
				newNumerator = "-" + tmps;
		}

		newDenominator = lcm;

		if (newNumerator.at(0) == '-') {
			res->setIsNegative(true);
			newNumerator = newNumerator.substr(1);
		}
		else
			res->setIsNegative(false);

		string gcd = getGCD(newNumerator, newDenominator);
		if (!isZero(gcd)) {
			newNumerator = division(newNumerator, gcd);
			newDenominator = division(newDenominator, gcd);
		}

		res->setNumerator(newNumerator);
		res->setDenominator(newDenominator);
	}

	return (*res);
}

// Minus
Number& operator-(Number& number) {

	// 0
	if (isZero(number.getNumerator())) {
		number.setIsNegative(false);
		return number;
	}

	number.setIsNegative(!number.getIsNegative());
	return number;
}

// Negative
Number& operator-(Number& lSide, Number& rSide) {
	Number* res = new Number;
	string newNumerator, newDenominator, gcd;
	string lcm = getLCM(lSide.getDenominator(), rSide.getDenominator());
	string ia = multiple(division(lcm, lSide.getDenominator()), lSide.getNumerator());
	string ib = multiple(division(lcm, rSide.getDenominator()), rSide.getNumerator());

	// neg - neg
	if (lSide.getIsNegative() == true && rSide.getIsNegative() == true)
		newNumerator = minuz(ib, ia);

	// neg - pos
	else if (lSide.getIsNegative() == true && rSide.getIsNegative() == false) {
		newNumerator = add(ia, ib);

		// not zero
		if (!isZero(newNumerator))
			newNumerator = "-" + newNumerator;
	}

	// pos - neg
	else if (lSide.getIsNegative() == false && rSide.getIsNegative() == true)
		newNumerator = add(ia, ib);

	// pos - pos
	else if (lSide.getIsNegative() == false && rSide.getIsNegative() == false)
		newNumerator = minuz(ia, ib);

	if (newNumerator[0] == '-') {
		res->setIsNegative(true);
		newNumerator = newNumerator.substr(1);
	}
	else
		res->setIsNegative(false);

	newDenominator = lcm;

	gcd = getGCD(newNumerator, newDenominator);
	if (!isZero(gcd)) {
		newNumerator = division(newNumerator, gcd);
		newDenominator = division(newDenominator, gcd);
	}

	res->setNumerator(newNumerator);
	res->setDenominator(newDenominator);
	res->setType((lSide.getType() == DECIMAL || rSide.getType() == DECIMAL) ? DECIMAL : INTEGER);

	return (*res);
}

// Division
Number& operator/(Number& lSide, Number& rSide) {
	Number* res = new Number;
	string newNumerator;
	string newDenominator;
	bool isNeg;

	if ((lSide.getIsNegative() && rSide.getIsNegative()) || (!lSide.getIsNegative() && !rSide.getIsNegative()))
		isNeg = false;
	else
		isNeg = true;

	// INTEGER / INTEGER
	if (lSide.getType() == INTEGER && rSide.getType() == INTEGER) {
		res->setType(INTEGER);

		newNumerator = division(lSide.numerator, rSide.numerator);
		newDenominator = "1";

		if (newNumerator == "0")
			isNeg = false;

		res->setNumerator(newNumerator);
		res->setDenominator(newDenominator);
		res->setIsNegative(isNeg);

		//cout << res->getIsNegative() << " | " << res->getNumerator() << "/" << res->getDenominator();
	}

	// DECIMAL / DECIMAL
	else {
		res->setType(DECIMAL);

		newNumerator = multiple(lSide.getNumerator(), rSide.getDenominator());
		newDenominator = multiple(lSide.getDenominator(), rSide.getNumerator());

		string gcd = getGCD(newNumerator, newDenominator);
		if (!isZero(gcd)) {
			newNumerator = division(newNumerator, gcd);
			newDenominator = division(newDenominator, gcd);
		}

		if (isZero(newNumerator))
			isNeg = false;

		res->setNumerator(newNumerator);
		res->setDenominator(newDenominator);
		res->setIsNegative(isNeg);
	}

	return (*res);
}

// Multiple
Number& operator*(Number& lSide, Number& rSide) {
	Number* res = new Number;
	string newNumerator, newDenominator, gcd;
	bool isNeg;

	if ((lSide.getIsNegative() && rSide.getIsNegative()) || (!lSide.getIsNegative() && !rSide.getIsNegative()))
		isNeg = false;
	else
		isNeg = true;

	newNumerator = multiple(lSide.numerator, rSide.numerator);
	newDenominator = multiple(lSide.denominator, rSide.denominator);

	gcd = getGCD(newNumerator, newDenominator);
	if (!isZero(gcd)) {
		newNumerator = division(newNumerator, gcd);
		newDenominator = division(newDenominator, gcd);
	}

	if (isZero(newNumerator))
		isNeg = false;

	res->setNumerator(newNumerator);
	res->setDenominator(newDenominator);
	res->setIsNegative(isNeg);
	res->setType((lSide.getType() == DECIMAL || rSide.getType() == DECIMAL) ? DECIMAL : INTEGER);

	return *res;
}

// Power
Number& operator^(Number& lSide, Number& rSide) {
	Number* res = new Number;
	bool needSqrt = false;
	string newNumerator, newDenominator;

	// anything ^0 is 1
	if (isZero(rSide.getNumerator())) {
		res->setIsNegative(false);
		res->setNumerator(DEFAULT_VALUE_1);
		res->setDenominator(DEFAULT_VALUE_1);
		res->setType((lSide.getType() == DECIMAL || rSide.getType() == DECIMAL) ? DECIMAL : INTEGER);

		return (*res);
	}

	// DECIMAL
	if (rSide.getType() == DECIMAL) {

		// not Integer neither square root
		if (rSide.getDenominator() != "1" && rSide.getDenominator() != "2") {
			puts("Error! Only support integer and square root.");
			*res = lSide;
			return (*res);
		}

		// Square root
		if (rSide.getDenominator() == "2") {

			// Error: Square root cannot be negative value, ex: (-3)^(0.5) = ?
			if (lSide.getIsNegative() == true) {
				puts("Error! Square root cannot be negative value.");
				*res = lSide;
				return (*res);
			}

			needSqrt = true;
		}
	}

	// general integer style a^b
	string k = "1", b = rSide.getNumerator(), aNume = lSide.getNumerator(), aDeno = lSide.getDenominator();
	newNumerator = newDenominator = DEFAULT_VALUE_1;

	while (compare(k, b) <= 0) {
		newNumerator = multiple(newNumerator, aNume);
		newDenominator = multiple(newDenominator, aDeno);

		k = add(k, DEFAULT_VALUE_1);
	}

	// ex: (2/3)^(-3) = (8/27)^(-1) = (27/8)
	if (rSide.getIsNegative()) {
		b = newNumerator;
		newNumerator = newDenominator;
		newDenominator = b;
	}

	if (needSqrt) {
		/**/ /* Square root */
		fractionString fracStyle;

		fracStyle = fractionDivision(newNumerator, newDenominator);
		//cout << "FracStyle = " << fracStyle << endl;
		fracStyle = squareRoot(fracStyle);

		*res = fractionString2Number(fracStyle);

		// square root might not be negative
		res->setIsNegative(false);

		if (lSide.getType() == DECIMAL)
			res->setType(DECIMAL);
		else {
			if (res->getDenominator() == DEFAULT_VALUE_1)
				res->setType(INTEGER);
			else
				res->setType(DECIMAL);
		}
	}

	else {
		if (lSide.getIsNegative() == true && isOdd(rSide.getNumerator()) == true)
			res->setIsNegative(true);
		else
			res->setIsNegative(false);

		res->setType((lSide.getType() == DECIMAL || rSide.getType() == DECIMAL) ? DECIMAL : INTEGER);
		res->setNumerator(newNumerator);
		res->setDenominator(newDenominator);
	}

	return (*res);
}

// Factorial
Number& operator!(Number& number) {
	Number* res = new Number;
	(*res) = factorial(number);

	return (*res);
}

// Factorial
Number& factorial(Number& number) {
	Number* res = new Number;

	res->setIsNegative(false);
	res->setType(number.getType());

	// Error: negative factorial undefined, ex: (-23)! = ?
	if (number.getIsNegative() == true) {
		puts("Error, factorial cannot be negative value.");
		*res = number;
		return (*res);
	}

	// 0! = 1
	if (isZero(number.getNumerator())) {
		res->setNumerator(DEFAULT_VALUE_1);
		res->setDenominator(DEFAULT_VALUE_1);
		return (*res);
	}

	// DECIMAL
	if (number.getType() == DECIMAL) {
		// DECIMAL and has fractions, ex: (0.6)! = ?
		if (number.getDenominator() != "1") {
			puts("Error, factorial cannot be fractions.");
			*res = number;
			return (*res);
		}
	}

	string ans = DEFAULT_VALUE_1, now = DEFAULT_VALUE_1;

	while (1) {
		if (compare(now, number.getNumerator()) > 0)
			break;

		ans = multiple(ans, now);
		now = add(now, DEFAULT_VALUE_1);
	}

	res->setNumerator(ans);
	res->setDenominator(DEFAULT_VALUE_1);

	return (*res);
}

//Number& squareRoot(Number& )