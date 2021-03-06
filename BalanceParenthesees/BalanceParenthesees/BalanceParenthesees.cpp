// BalanceParenthesees.cpp : Defines the entry point for the console application.
// bool check pulled from https://github.com/VikramjitRoy/Balancing-Parenthesis
// Modified by Rami Lukata on 12/09

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(string s) {

	// declare stack where input is stored
	vector <char> stack;

	for (int i = 0; s[i] != '\0'; i++) {

		if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
			stack.push_back(s[i]);
		}

		else {
			if (s[i] == ')'&&stack[stack.size() - 1] != '(') {
				return 0;
			}
			else if (s[i] == '}'&&stack[stack.size() - 1] != '{') {
				return 0;
			}
			else if (s[i] == ']'&&stack[stack.size() - 1] != '[') {
				return 0;
			}
			stack.pop_back();
		}
	}
	if (stack.empty()) return 1;
	else return 0;
}

// this is just a main
int main() {
	bool stop = false;
	do {
		bool res;
		string str;
		cout << "Please type in some parenthesees: ";
		cin >> str;
		res = check(str);
		if (res) printf("Balanced\n");
		else printf("Unbalanced\n");
		cout << "Again? Yy / Nn: ";
		if ((getchar() == 'N') | (getchar() == 'n')) stop = true;
	} while (stop == false);
	return 0;
}
