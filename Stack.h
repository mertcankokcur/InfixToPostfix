#ifndef _STACK_
#define _STACK_
#include <iostream>
using namespace std;

const int MAX_STACK_SIZE=100;

template<class ElemType>
class Stack
{
private:
	int top;
	ElemType items[MAX_STACK_SIZE];
public:
	Stack()
	{
		top=-1;
	}
	bool isEmpty()const
	{
		return top==-1;
	}
	bool isFull()const
	{
		return top>=MAX_STACK_SIZE-1;
	}
	void push(ElemType e)
	{
		if(isFull() )
		{
			cout<<"Error(push): Stack overflow\n";
			exit(0);
		}
		top++;
		items[top]=e;
	}
	ElemType pop()
	{
		if(isEmpty() )
		{
			cout<<"Error(pop):Stack underflow\n";
			exit(0);
		}
		ElemType e=items[top];
		top--;
		return e;
	}
	ElemType peek()const
	{
		if(isEmpty() )
		{
			cout<<"Error(pop):Stack underflow\n";
			exit(0);
		}
		ElemType e=items[top];
		return e;
	}
};
#endif