#pragma once

#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <string>
#include "Number.h"
#define OP_NUM 12
using namespace std;

const string opSymbol[OP_NUM] = {"(", ")", "!", "^", "p", "n", "*", "/", "+", "-"};
const int opPriority[OP_NUM][OP_NUM] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 0, 0, -1, -1, 1, 1, 1, 1, 1, 1 },
	{ 0, 0, -1, -1, -1, -1, 1, 1, 1, 1 },
	{ 0, 0, -1, -1, -1, -1, 1, 1, 1, 1 },
	{ 0, 0, -1, -1, -1, -1, 1, 1, 1, 1 },
	{ 0, 0, -1, -1, -1, -1, 1, 1, 1, 1 },
	{ 0, 0, -1, -1, -1, -1, -1, -1, 1, 1 },
	{ 0, 0, -1, -1, -1, -1, -1, -1, 1, 1 },
};
enum Operator { LEFT_PARENTHESE, RIGHT_PARENTHESE, FACTORIAL, POWER, POSITIVE, NEGATIVE, MULTIPLE, DIVISION, ADD, MINUS };
enum ElementType { OPERATOR_TYPE, NUMBER_TYPE };

struct Element {
	ElementType type;

	//union {
	Number num;
	Operator op;
	//};
};

class Expression
{
public:
	Expression();
	Expression(string);
	~Expression();

	void setInputString(string);
	string getInputString();

	void analyzeInputString();
	void showExpress(vector<Element>&);

	Number& calculate();

	vector<Element> infix; // ex: 9 / 3 * ( 1 + 2 )
	vector<Element> postfix; // ex: 9 3 / 1 2 + *

private:
	int expressSize;

	static int varSize;
	//static map<string, Number> var;

	string inputString;
	string expString;

	void insertNewNumber(string, string, vector<Element>&);
	void insertNewNumber(string, vector<Element>&);
	void insertNewOperator(Operator, vector<Element>&);

	void fixFunctionStyle(string);
	string fixFunctionStyleRekkursion(int, const int, Operator);

	void analyzeExpString();
	void infix2postfix();

	int compareOperatorPriority(Operator, Operator);
};

