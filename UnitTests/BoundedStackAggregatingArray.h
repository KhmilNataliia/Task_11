#ifndef BOUNDED_STACK_AGGREGATING_ARRAY
#define BOUNDED_STACK_AGGREGATING_ARRAY

#include "Array.h"
#include "Stack.h"

#include <exception>

using namespace std;

template <class Elem>
class BoundedStackAgregatingArray: public IStack<Elem> 
{

	static const int bot = -1; 
	int _top=0;
	Array<Elem> stackArray;

public:
	
	explicit BoundedStackAgregatingArray(int size):stackArray(size), _top(bot){};
	
	
	bool empty() const 
	{
		return (_top == bot);
	}

	bool full() const 
	{
		return (_top == stackArray.size() - 1);
	}
	
	const Elem& top() const 
	{
		if (empty()) throw BadStack();
		return stackArray[_top];
	}
	
	
	void pop() 
	{
		if (empty()) throw BadStack();
		_top--;
	}

	
	void push(const Elem& value)
	{
		if (full()==true) throw BadStack();

		stackArray[++_top] = value;
	}
	
	int size() const 
	{
		return stackArray.size();
	}

	
	class BadStack:public exception
	{
	public:
		void msg() 
		{
			cout << what();
		}
	};
};

#endif