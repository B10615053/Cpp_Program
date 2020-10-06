#include <iostream>
#include <vector>
#include <string>
#include "Number.h"
#include "Decimal.h"
#include "Integer.h"
#include "Expression.h"
using namespace std;

int main()
{
	Expression inpExpress;

	Decimal d1, d2, d3, d;
	Integer i1, i2, i3;

	string inpCmd;

	d = -0.0000000001;

	d1 = 123.7777;
	d2 = 4.555;

	i1 = 123.777;
	i2 = 4.555;
	//cout << "i1 = " << i1;
	//cout << "i2 = " << i2;

	i3 = i2 + d1; // (Integer)4.555 + (Decimal)123.7777
	//cout << "i3 (Integer 4.000 + Decimal 123.7777) = " << i3;

	i3 = d1 + d2; // (Decimal)4.555 + (Decimal)123.7777
	cout << "i3 (Decimal 4.555 + Decimal 123.7777) = " << i3;

	//cout << "d = " << d;
	//cout << "d1 = " << d1;
	//cout << "d2 = " << d2;
	//cout << "d3 = " << d3;

	d1 = -2.125;
	//cout << d1;
	d2 = -3.8;
	//cout << d2;
	d3 = d1 / (d2 + i1);
	//cout << d3;

	//vector<Number> variables;
	//variables.clear();

	puts("Input expression: ");
	while (getline(cin, inpCmd)) {
		inpExpress.setInputString(inpCmd);
		inpExpress.analyzeInputString();

		cout << inpExpress.calculate() << endl;
		puts("Input expression: ");
	}
	
	return 0;
}