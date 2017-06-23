#ifndef BOUNDED_STACK_DERIVED_FROM_ARRAY
#define BOUNDED_STACK_DERIVED_FROM_ARRAY

#include "ProtectedArray.h"
#include "Stack.h"
#include <exception>

using namespace std;

template <class Elem>
class BoundedStackDerivedFromArray: protected ProtectedArray<Elem>, public IStack<Elem> 
{

	static const int bot = -1; 

protected:
	int _top=0;

public:
	explicit BoundedStackDerivedFromArray(int size): ProtectedArray(size), _top(bot){}

	bool empty() const 
	{
		return (_top == bot);
	}

	bool full() const 
	{
		return (_top == size() - 1);
	}

	const Elem& top() const 
	{
		if (empty()) throw BadStack();
		return It[_top-1];
	}
	
	void pop()
	{
		if (empty()) throw BadStack();
		_top--;
	}
	
	void push(const Elem& value) 
	{
		if (full()) throw BadStack();
		It[_top++] = value;
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
