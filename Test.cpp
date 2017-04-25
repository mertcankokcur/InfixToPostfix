#include "Stack.h"
#include "InfixToPostfix.h"
#include <iostream>
#include <string>

using namespace std;

void main()
{
	InfixToPostfix expression;
	string infix,postfix;

	char selection = 'y';

	do
	{
	infix = expression.getInfix();
	postfix = expression.convertToPostfix(infix);
	expression.showInfix(infix);
	expression.showPostfix(postfix);

	cout<<"Do you want to continue? (Enter 'y' for yes, enter something for no)"<<endl;
	cin>>selection;
	}while(selection == 'y' || selection == 'Y');

	cout <<"Bye bye!"<<endl;

}