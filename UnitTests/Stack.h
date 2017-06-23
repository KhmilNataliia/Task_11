#ifndef STACK
#define STACK

template <class Elem>
class IStack 
{

public:
	virtual bool empty() const = 0;
	virtual const Elem& top() const = 0;
	virtual void pop() = 0;
	virtual void push(const Elem& value) = 0;
};


#endif