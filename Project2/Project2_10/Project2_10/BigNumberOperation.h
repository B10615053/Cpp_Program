#pragma once

#include <string>
#include <cmath>
#include <vector>
#define ERROR_SYMBOL ("Error")
#define FRACTION_LENGTH 100
typedef std::string fractionString;
using namespace std;

namespace BigMethod {

#pragma region String operations
	// convert int to string
	string int2String(int&);
	// GCD
	string getGCD(string, string);
	// LCM
	string getLCM(string, string);
	// / (Integer division, ex: 6/5 = 1)
	string division(string, string);
	// / (Fraction division, ex: 6/5 = 1.2)
	fractionString fractionDivision(string, string);
	// %
	string mod(string, string);
	// -
	string minuz(string, string);
	// +
	string add(string, string);
	// *
	string multiple(string, string);
	// delete prefix 0, ex: 00129 -> 129
	string deletePreZero(string);
	// delete prefix 0 for fraction
	fractionString fractionDeletePreZero(fractionString);
	// compare which is bigger
	int compare(string, string);
	// judge is 0 or not
	bool isZero(string);
	// judge is odd or not
	bool isOdd(string);
	// square root
	fractionString squareRoot(fractionString);
#pragma endregion
}