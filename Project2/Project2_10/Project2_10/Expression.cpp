#include "Expression.h"




int Expression::varSize = 0;

Expression::Expression() {
	inputString = "";
	expressSize = 0;
}

Expression::Expression(string inputExpression) {
	inputString = inputExpression;
}

Expression::~Expression() {
	infix.clear();
	postfix.clear();
}

void Expression::setInputString(string newInputString) {
	inputString = newInputString;
	return;
}

string Expression::getInputString() {
	return inputString;
}

void Expression::analyzeInputString() {
	inputString += "|";

	int k, len = inputString.length();

	for (k = 0; k < len; k++) {
		if (inputString[k] != ' ')
			break;
	}

	// Set (Do not output)
	if (inputString[k] == 'S' && k + 1 < len && inputString[k + 1] == 'e' && k + 2 < len && inputString[k + 2] == 't') {
		/**/
	}

	// Expression (Need to output)
	else {
		fixFunctionStyle(inputString);
		analyzeExpString();
		infix2postfix();

		//cout << "After input string fixed: " << expString << endl;
		//showExpress(infix);
		//showExpress(postfix);
	}


	return;
}

void Expression::analyzeExpString() {

	int k, len = expString.length();
	bool nowFrac = false;
	string inp = expString, num, frac;

	Element newElement;
	Number newNumber;

	num = "NULL"; frac = "NULL";
	infix.clear();

	for (k = 0; k < len; k++) {

		if (inp[k] >= 48 && inp[k] <= 57) {
			// num
			if (nowFrac == false) {
				if (num == "NULL")
					num = inp[k];
				else
					num += inp[k];
			}
			// frac
			else {
				if (frac == "NULL")
					frac = inp[k];
				else
					frac += inp[k];
			}
		}
		else if (inp[k] == '.') {
			nowFrac = true;
		}
		// Left parenthese
		else if (inp[k] == '(') {
			insertNewOperator(LEFT_PARENTHESE, infix);
			nowFrac = false;
		}
		// Right parenthese
		else if (inp[k] == ')') {

			if (num != "NULL" && num != "ANOTHER")
				insertNewNumber(num, frac, infix);

			insertNewOperator(RIGHT_PARENTHESE, infix);
			nowFrac = false;
			num = "ANOTHER"; frac = "NULL";
		}
		// Add or positive
		else if (inp[k] == '+') {

			// positive
			if (num == "NULL")
				insertNewOperator(POSITIVE, infix);

			// add
			else {
				if (num != "ANOTHER")
					insertNewNumber(num, frac, infix);

				insertNewOperator(ADD, infix);
				num = frac = "NULL";
			}

			nowFrac = false;
		}
		// Minus or negative
		else if (inp[k] == '-') {

			// negative
			if (num == "NULL")
				insertNewOperator(NEGATIVE, infix);

			// minus
			else {
				if (num != "ANOTHER")
					insertNewNumber(num, frac, infix);

				insertNewOperator(MINUS, infix);
				num = frac = "NULL";
			}

			nowFrac = false;
		}
		// Multiple
		else if (inp[k] == '*') {
			if (num != "ANOTHER" && num != "NULL")
				insertNewNumber(num, frac, infix);

			insertNewOperator(MULTIPLE, infix);
			nowFrac = false;
			num = frac = "NULL";
		}
		// Division
		else if (inp[k] == '/') {
			if (num != "ANOTHER" && num != "NULL")
				insertNewNumber(num, frac, infix);

			insertNewOperator(DIVISION, infix);
			nowFrac = false;
			num = frac = "NULL";
		}
		// Factorial
		else if (inp[k] == '!') {
			if (num != "ANOTHER" && num != "NULL")
				insertNewNumber(num, frac, infix);

			insertNewOperator(FACTORIAL, infix);
			nowFrac = false;
			num = "ANOTHER"; frac = "NULL";
		}
		// Power
		else if (inp[k] == '^') {
			if (num != "ANOTHER" && num != "NULL")
				insertNewNumber(num, frac, infix);

			insertNewOperator(POWER, infix);
			nowFrac = false;
			num = frac = "NULL";
		}
		else if (inp[k] == ' ') {
			nowFrac = false;
		}
		else if (inp[k] == ',') {
			num = "NULL"; frac = "NULL";
			nowFrac = false;
		}
		// End symbol
		else if (inp[k] == '|') {
			if (num != "NULL" && num != "ANOTHER") {
				if (frac != "NULL")
					insertNewNumber(num, frac, infix);
				else
					insertNewNumber(num, infix);
			}
		}
	}

	return;
}

void Expression::infix2postfix() {
	/**/

	vector<Element>::iterator it_v;
	stack<Operator> operatorStack;

	postfix.clear();
	for (it_v = infix.begin(); it_v != infix.end(); it_v++) {

		// Operator
		if (it_v->type == OPERATOR_TYPE) {

			// (
			if (it_v->op == LEFT_PARENTHESE)
				operatorStack.push(LEFT_PARENTHESE);

			// )
			else if (it_v->op == RIGHT_PARENTHESE) {

				while (!operatorStack.empty() && operatorStack.top() != LEFT_PARENTHESE) {
					insertNewOperator(operatorStack.top(), postfix);
					operatorStack.pop();
				}

				if(!operatorStack.empty())
					operatorStack.pop();
			}

			// Others
			else {
				while (!operatorStack.empty() && compareOperatorPriority(operatorStack.top(), it_v->op) > 0) {
					insertNewOperator(operatorStack.top(), postfix);
					operatorStack.pop();
				}

				operatorStack.push(it_v->op);
			}
		}

		// Number (Integer or Decimal)
		else if (it_v->type == NUMBER_TYPE)
			postfix.push_back((*it_v));
	}

	while (!operatorStack.empty()) {
		if (operatorStack.top() != LEFT_PARENTHESE && operatorStack.top() != RIGHT_PARENTHESE)
			insertNewOperator(operatorStack.top(), postfix);

		operatorStack.pop();
	}

	return;
}

int Expression::compareOperatorPriority(Operator op1, Operator op2) {
	//enum Operator { LEFT_PARENTHESE, RIGHT_PARENTHESE, FACTORIAL, POWER, POSITIVE, NEGATIVE, MULTIPLE, DIVISION, ADD, MINUS };
	return opPriority[op1][op2];
}

void Expression::fixFunctionStyle(string inp) {
	int k, i, len = inp.length();
	string exp = "";
	stack<char> parentheseStk;

	for (k = 0; k < len; k++) {
		if (inp[k] == 'P' && k + 1 < len && inp[k + 1] == 'o' && k + 2 < len && inp[k + 2] == 'w' && k + 3 < len && inp[k + 3] == 'e' && k + 4 < len && inp[k + 4] == 'r') {
			for (; k < len; k++) {
				if (inp[k] == '(')
					break;
			}
			
			for (i = k + 1; i < len; i++) {

				if (inp[i] == '(')
					parentheseStk.push('(');

				else if (inp[i] == ')') {
					if (parentheseStk.empty())
						break;
					else {
						parentheseStk.pop();
					}
				}
			}

			exp += "(" + fixFunctionStyleRekkursion(k + 1, i + 1, POWER) + ")";
			k = i;
		}

		else {
			if(inp[k] != ' ')
				exp += inp[k];
		}
	}

	expString = exp;

	return;
}

string Expression::fixFunctionStyleRekkursion(int idx, const int LEN, Operator thisOp) {
	string inp = inputString, exp = "(";
	stack<char> parentheseStk;
	int k, i;

	for (k = idx; k < LEN; k++) {
		if (inp[k] == 'P' && k + 1 < LEN && inp[k + 1] == 'o' && k + 2 < LEN && inp[k + 2] == 'w' && k + 3 < LEN && inp[k + 3] == 'e' && k + 4 < LEN && inp[k + 4] == 'r') {
			for (; k < LEN; k++) {
				if (inp[k] == '(')
					break;
			}

			for (i = k + 1; i < LEN; i++) {

				if (inp[i] == '(')
					parentheseStk.push('(');

				else if (inp[i] == ')') {
					if (parentheseStk.empty())
						break;
					else {
						parentheseStk.pop();
					}
				}
			}

			exp += "(" + fixFunctionStyleRekkursion(k + 1, i + 1, POWER) + ")";
			k = i;
		}

		else if (inp[k] == ',') {
			exp += ")";
			exp += opSymbol[thisOp];
			exp += "(";
		}

		else if (k == LEN - 1) {
			exp += ")";
			return exp;
		}

		else {
			if(inp[k] != ' ')
				exp += inp[k];
		}
	}

	return exp;
}

void Expression::insertNewNumber(string num, string frac, vector<Element>& exp) {
	Element newElement;
	Number newNumber;

	newElement.type = NUMBER_TYPE;

	// DECIMAL
	if (frac != "NULL") {
		newNumber.setType(DECIMAL);
		newNumber.fractionString2String(num, frac);
	}

	// INTEGER
	else {
		newNumber.setType(INTEGER);
		newNumber.setNumerator(num);
		newNumber.setDenominator(DEFAULT_VALUE_1);
	}

	newNumber.setIsNegative(false);
	newNumber.setFraction(fractionDivision(newNumber.getNumerator(), newNumber.getDenominator()));

	newElement.num = newNumber;
	exp.push_back(newElement);

	return;
}

void Expression::insertNewNumber(string str, vector<Element>& exp) {
	Element newElement;
	Number newNumber;

	newElement.type = NUMBER_TYPE;

	// DECIMAL
	if (str.find(".") != str.npos) {
		newNumber.setType(DECIMAL);
		newNumber.fractionString2String(str);
	}

	// INTEGER
	else {
		newNumber.setType(INTEGER);
		newNumber.setNumerator(str);
		newNumber.setDenominator(DEFAULT_VALUE_1);
	}

	newNumber.setIsNegative(false);
	newNumber.setFraction(fractionDivision(newNumber.getNumerator(), newNumber.getDenominator()));

	newElement.num = newNumber;
	exp.push_back(newElement);

	return;
}

void Expression::insertNewOperator(Operator newOp, vector<Element>& exp) {
	Element newElement;
	newElement.type = OPERATOR_TYPE;
	newElement.op = newOp;

	exp.push_back(newElement);
	return;
}

void Expression::showExpress(vector<Element>& exp) {
	vector<Element>::iterator it_v;

	for (it_v = exp.begin(); it_v != exp.end(); it_v++) {
		if (it_v->type == OPERATOR_TYPE)
			cout << opSymbol[it_v->op];
		else
			cout << it_v->num;

		cout << " ";
	}
	cout << endl;

	return;
}

Number& Expression::calculate() {
	stack<Number> numberStack;
	vector<Element>::iterator it_v;
	Number *a = new Number, *b = new Number, *res = new Number;

	for (it_v = postfix.begin(); it_v != postfix.end(); it_v++) {

		// Number
		if (it_v->type == NUMBER_TYPE)
			numberStack.push(it_v->num);

		// Operator
		else if (it_v->type == OPERATOR_TYPE) {
			switch (it_v->op) {
			case FACTORIAL:
				*a = numberStack.top(); numberStack.pop();
				*res = factorial(*a);
				numberStack.push(*res);
				break;

			case POWER:
				*b = numberStack.top(); numberStack.pop();
				*a = numberStack.top(); numberStack.pop();
				*res = (*a) ^ (*b);
				numberStack.push(*res);

				break;

			case POSITIVE: break;
			case NEGATIVE:
				*a = numberStack.top(); numberStack.pop();
				*res = -(*a);
				numberStack.push(*res);
				break;

			case MULTIPLE:
				*b = numberStack.top(); numberStack.pop();
				*a = numberStack.top(); numberStack.pop();
				*res = (*a) * (*b);
				numberStack.push(*res);
				break;

			case DIVISION:
				*b = numberStack.top(); numberStack.pop();
				*a = numberStack.top(); numberStack.pop();
				*res = (*a) / (*b);
				numberStack.push(*res);
				break;

			case ADD:
				*b = numberStack.top(); numberStack.pop();
				*a = numberStack.top(); numberStack.pop();
				*res = (*a) + (*b);
				numberStack.push(*res);
				break;

			case MINUS:
				*b = numberStack.top(); numberStack.pop();
				*a = numberStack.top(); numberStack.pop();
				*res = (*a) - (*b);
				numberStack.push(*res);
				break;
			}
		}
	}

	if(!numberStack.empty())
		*res = numberStack.top();

	return (*res);
}