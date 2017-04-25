#include "InfixToPostfix.h"


InfixToPostfix::InfixToPostfix()
{
	infix   = "";
	postfix = "";
}

string InfixToPostfix::getInfix()
{

	cout<<"Enter an infix expression :  ";
	getline(cin,this->infix);
	return this->infix;
}
void InfixToPostfix:: showInfix(string infix)
{

    cout<<"Your infix expression is: "<<infix<<endl;
}
void InfixToPostfix:: showPostfix(string postfix)
{

		cout<<"The postfix expression is:  "<<postfix<<endl;
}
string InfixToPostfix:: convertToPostfix(string infix)
{

	Stack<char> operatorStack;
	string postfix;

	for(int i = 0; i < infix.length(); i++)
	{
		if(infix[i]==' ') continue;
		if(isOperand(infix[i])) 
		{
			postfix.push_back(infix[i]);
		}

		else if(isOperator(infix[i]))
		{
			if(operatorStack.isEmpty()) operatorStack.push(infix[i]);
			else if(!operatorStack.isEmpty())
			{
				if(infix[i]=='(') operatorStack.push(infix[i]);
				else if(infix[i]==')')
				{
					while(operatorStack.peek()!='(')
					{
						postfix.push_back(operatorStack.pop());
					}
					operatorStack.pop();
				}
				else
				{
					while(!operatorStack.isEmpty() && precedence(operatorStack.peek(),infix[i]))
					{
						postfix.push_back(operatorStack.pop());
					
					}
					if(!operatorStack.isEmpty())
					{
						if(!precedence(operatorStack.peek(),infix[i])) operatorStack.push(infix[i]);
					}
					else
						operatorStack.push(infix[i]);

				}
			}
		}

	}
	while(!operatorStack.isEmpty()) postfix.push_back(operatorStack.pop());
	return postfix;
}
bool InfixToPostfix:: precedence(char a,char b)
{
	if(orderOfOperator(a) >= orderOfOperator(b) ) return true;
	else										  return false;
}

int InfixToPostfix:: orderOfOperator(char a)
{
	if     (a == '+' || a == '-') return 1;
	else if(a == '*' || a == '/') return 2;
	else return 0;
}
bool InfixToPostfix:: isOperand(char a)
{
	if(a >= '0' && a<='9' ) return true;
	if(a >='a' && a <='z' ) return true;
	if(a >='A' && a <= 'Z' ) return true;
	else					return false;
}
bool InfixToPostfix:: isOperator(char a)
{
	if(a == '+' || a == '-' || a == '*' || a == '/' || a == '(' || a==')') return true;
	return false;
}
