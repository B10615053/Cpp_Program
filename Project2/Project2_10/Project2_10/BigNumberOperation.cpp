#include "BigNumberOperation.h"

namespace BigMethod {

#pragma region String operations
	// convert int to string
	string int2String(int& integ) {
		if (integ == 0)
			return "0";

		string tmp = "", res = "";
		int k;
		bool isNeg = (integ < 0) ? true : false;
		integ = abs(integ);

		while (integ > 0) {
			tmp += (char)((integ % 10) + 48);
			integ /= 10;
		}

		if (isNeg)
			res += "-";

		for (k = tmp.length() - 1; k >= 0; k--)
			res += tmp[k];

		return res;
	}

	// GCD
	string getGCD(string a, string b) {
		a = deletePreZero(a);
		b = deletePreZero(b);

		string remain = "0";

		if (isZero(b)) {
			puts("Error! Dividing by 0 happens in mod operation!");
			return ERROR_SYMBOL;
		}

		if (isZero(a))
			return remain;

		while (1) {
			remain = mod(a, b);

			if (isZero(remain))
				break;

			a = b;
			b = remain;
		}

		return b;
	}

	// LCM
	string getLCM(string a, string b) {
		/* LCM x GCD = a x b */
		/* LCM = (a x b) / GCD */
		a = deletePreZero(a);
		b = deletePreZero(b);

		string product = multiple(a, b);
		string gcd = getGCD(a, b);
		string lcm = division(product, gcd);

		return lcm;
	}

	// string / string (Integer division, ex: 6/5 = 1)
	string division(string a, string b) {
		a = deletePreZero(a);
		b = deletePreZero(b);

		string quot = "0";

		if (isZero(b)) {
			puts("Error! Dividing by 0 happens in division operation!");
			return ERROR_SYMBOL;
		}

		string sub = "0";
		int cursor, cnt, k, i;

		cursor = 0;
		while (1) {
			sub += a[cursor++];
			sub = deletePreZero(sub);

			cnt = 0;

			// if sub >= b
			while (compare(sub, b) != -1) {
				cnt++;
				sub = minuz(sub, b);
			}

			quot += (char)(cnt + 48);

			if (cursor >= a.length())
				break;
		}

		quot = deletePreZero(quot);
		return quot;
	}

	// string / string (Fraction division, ex: 6/5 = 1.2)
	fractionString fractionDivision(string a, string b) {
		a = deletePreZero(a);
		b = deletePreZero(b);

		fractionString quot = "0";

		if (isZero(b)) {
			puts("Error! Dividing by 0 happens in division operation!");
			return ERROR_SYMBOL;
		}

		string sub = "0";
		int cursor, cnt, k, i, fractionLenCount;
		bool inFraction;

		cursor = 0;
		inFraction = false; fractionLenCount = 0;

		while (1) {

			sub += ((inFraction == false) ? a[cursor++] : '0');
			sub = deletePreZero(sub);

			cnt = 0;

			// if sub >= b
			while (compare(sub, b) != -1) {
				cnt++;
				sub = minuz(sub, b);
			}

			quot += (char)(cnt + 48);

			if (cursor >= a.length() && !inFraction) {
				inFraction = true;
				quot += ".";
				fractionLenCount = 0;
			}

			if (inFraction) {
				fractionLenCount++;

				if (fractionLenCount >= FRACTION_LENGTH)
					break;
			}
		}
		quot = fractionDeletePreZero(quot);

		return quot;
	}

	// string % string
	string mod(string a, string b) {
		a = deletePreZero(a);
		b = deletePreZero(b);

		if (isZero(b)) {
			puts("Error! Divide by zero!");
			return "Error";
		}

		string sub = "0";
		int cursor, cnt, k, i;

		cursor = 0;
		while (1) {
			sub += a[cursor++];
			sub = deletePreZero(sub);

			cnt = 0;

			// if sub >= b
			while (compare(sub, b) != -1) {
				cnt++;
				sub = minuz(sub, b);
			}

			if (cursor >= a.length())
				break;
		}

		sub = deletePreZero(sub);
		return sub;
	}

	// string - string
	string minuz(string a, string b) {
		a = deletePreZero(a);
		b = deletePreZero(b);

		bool isNeg = false;
		int k, j, lenA, lenB, ia, ib, i;
		vector<int> tmpi;
		vector<int>::iterator it_v;

		// if a < b
		if (compare(a, b) == -1) {
			isNeg = true;
			string tmp4Swap = a;
			a = b;
			b = tmp4Swap;
		}

		lenA = a.length();
		lenB = b.length();
		tmpi.resize(lenA + lenB + 15);

		for (it_v = tmpi.begin(); it_v != tmpi.end(); it_v++)
			(*it_v) = 0;

		i = 0;
		for (k = lenA - 1, j = lenB - 1; k >= 0 || j >= 0; k--, j--) {
			ia = (k < 0) ? 0 : (int)(a[k] - 48);
			ib = (j < 0) ? 0 : (int)(b[j] - 48);

			tmpi[i++] = ia - ib;
		}

		for (k = 0; k < i; k++) {
			if (tmpi[k] < 0) {
				tmpi[k + 1]--;
				tmpi[k] += 10;
			}
		}

		for (k += 5; k >= 0; k--) {
			if (tmpi[k] != 0)
				break;
		}
		if (k < 0)
			return "0";

		string res = "";

		if (isNeg)
			res += "-";

		for (; k >= 0; k--)
			res += (char)(tmpi[k] + 48);
		res = deletePreZero(res);

		return res;
	}

	// string + string
	string add(string a, string b) {
		a = deletePreZero(a);
		b = deletePreZero(b);

		bool isNeg = false;
		int k, j, lenA, lenB, ia, ib, i;
		vector<int> tmpi;
		vector<int>::iterator it_v;

		// if a < b
		/*if (compare(a, b) == -1) {
			isNeg = true;
			string tmp4Swap = a;
			a = b;
			b = tmp4Swap;
		}*/

		lenA = a.length();
		lenB = b.length();
		tmpi.resize(lenA + lenB + 15);

		for (it_v = tmpi.begin(); it_v != tmpi.end(); it_v++)
			(*it_v) = 0;

		i = 0;
		for (k = lenA - 1, j = lenB - 1; k >= 0 || j >= 0; k--, j--) {
			ia = (k < 0) ? 0 : (int)(a[k] - 48);
			ib = (j < 0) ? 0 : (int)(b[j] - 48);

			tmpi[i++] = ia + ib;
		}

		for (k = 0; k < i; k++) {
			if (tmpi[k] >= 10) {
				tmpi[k + 1]++;
				tmpi[k] -= 10;
			}
		}

		for (k += 5; k >= 0; k--) {
			if (tmpi[k] != 0)
				break;
		}
		if (k < 0)
			return "0";

		string res = "";
		for (; k >= 0; k--)
			res += (char)(tmpi[k] + 48);
		res = deletePreZero(res);

		return res;
	}

	// string * string
	string multiple(string a, string b) {
		a = deletePreZero(a);
		b = deletePreZero(b);

		if (isZero(a) || isZero(b))
			return "0";

		int k, j, lenA, lenB, h, i;
		vector<int> tmpi;
		vector<int>::iterator it_v;
		string res;

		lenA = a.length(); lenB = b.length();
		tmpi.resize(lenA + lenB + 15);

		for (it_v = tmpi.begin(); it_v != tmpi.end(); it_v++)
			(*it_v) = 0;

		for (k = lenA - 1, i = 0; k >= 0; k--, i++) {
			for (j = lenB - 1, h = i; j >= 0; j--, h++)
				tmpi[h] += (int)(a[k] - 48) * (int)(b[j] - 48);
		}

		for (k = 0; k < h; k++) {
			if (tmpi[k] >= 10) {
				tmpi[k + 1] += tmpi[k] / 10;
				tmpi[k] %= 10;
			}
		}

		for (k += 5; k >= 0; k--) {
			if (tmpi[k] != 0)
				break;
		}

		res = "";
		for (; k >= 0; k--)
			res += (char)(tmpi[k] + 48);
		res = deletePreZero(res);

		return res;
	}

	// delete all prefix zeros, ex: "00129" -> "129"
	string deletePreZero(string str) {
		if (str[0] != '0')
			return str;

		int k, len;
		string res;

		len = str.length();
		for (k = 0; k < len; k++) {
			if (str[k] != '0')
				break;
		}

		if (k >= len)
			return "0";

		res = "";
		for (; k < len; k++)
			res += str[k];

		return res;
	}

	// delete prefix 0 for fraction
	fractionString fractionDeletePreZero(fractionString fstr) {
		int k, len = fstr.length(), dotLoc;
		fractionString res;

		for (dotLoc = 0; dotLoc < len; dotLoc++) {
			if (fstr[dotLoc] == '.')
				break;
		}

		for (k = 0; k < dotLoc; k++) {
			if (fstr[k] != '0')
				break;
		}

		if (k >= dotLoc)
			res = "0.";
		else {
			res = "";
			for (; k < dotLoc; k++)
				res += fstr[k];
			res += ".";
		}

		res += fstr.substr(dotLoc + 1);
		return res;
	}

	// (a < b : -1), (a > b : 1), (a = b : 0)
	int compare(string a, string b) {
		int lenA = a.length();
		int lenB = b.length();

		if (lenA < lenB)
			return (-1);

		if (lenA > lenB)
			return 1;

		int k;

		for (k = 0; k < lenA; k++) {
			if (a[k] < b[k])
				return (-1);

			if (a[k] > b[k])
				return 1;
		}

		return 0;
	}

	// is 0 or not
	bool isZero(string str) {
		int k, len = str.length();

		for (k = 0; k < len; k++) {
			if (str[k] != '0')
				return false;
		}

		return true;
	}
	
	// is odd number or not
	bool isOdd(string str) {
		int len = str.length();
		int lastDigit = ((int)(str[len - 1])) - 48;

		return ((lastDigit & 1) ? true : false);
	}

	// square root
	fractionString squareRoot(fractionString f_str) {
		/**/
		string divisor, dividend, tmps, guessed;
		fractionString ans, fstr = f_str;
		int k, len = fstr.length(), cursor, disorLen, dendLen, guess, ansLen;
		bool inFraction;
		int fractionLenCount;

		if ((len & 1)) {
			fstr = "0" + fstr;
			len++;
		}

		divisor = dividend = "0";
		cursor = 0;
		inFraction = false;
		fractionLenCount = 0;

		while (1) {
			if (cursor < len && fstr[cursor] == '.') {

				if (inFraction == false)
					ans += ".";
				inFraction = true;

				cursor++;
			}

			if (cursor >= len)
				divisor += "00";
			else {
				divisor += fstr[cursor]; cursor++;
				divisor += fstr[cursor]; cursor++;
			}
			divisor = deletePreZero(divisor);
			
			string originDividend = dividend;
			for (guess = 9; guess >= 0; guess--) {
				dividend += (char)(guess + 48);
				dividend = deletePreZero(dividend);

				tmps = ""; tmps += (char)(guess + 48);

				guessed = multiple(dividend, tmps);

				if (compare(guessed, divisor) <= 0)
					break;

				dividend = originDividend;
			}

			dividend = add(dividend, tmps);
			divisor = minuz(divisor, guessed);

			ans += (char)(guess + 48);

			if (inFraction) {
				fractionLenCount++;

				if (fractionLenCount >= FRACTION_LENGTH)
					break;
			}
		}

		ans = fractionDeletePreZero(ans);

		return ans;
	}
#pragma endregion
}