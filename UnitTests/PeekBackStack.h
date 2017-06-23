#ifndef PEEKBACK_STACK
#define PEEKBACK_STACK

#include "BoundedStackDerivedFromArray.h"

template <class Elem>
class PeekbackStack : public BoundedStackDerivedFromArray<Elem> 
{
public:
	PeekbackStack(int size):BoundedStackDerivedFromArray (size){};

	bool PeekbackStack::peekback(int index, const Elem& what) const 
	{
		if (index > _top) 
			throw out_of_range("Out of range at stack");

		return (It[index] == what);
	}
};

#endif