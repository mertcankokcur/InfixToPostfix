#pragma once
#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;
class InfixToPostfix
{

private:
	string infix;
	string postfix;

public:
	InfixToPostfix();
	string getInfix();
	void showInfix(string);
	void showPostfix(string);
	string convertToPostfix(string);
	bool precedence(char,char);
	int orderOfOperator(char);
	bool isOperator(char);
	bool isOperand(char);

	
};

