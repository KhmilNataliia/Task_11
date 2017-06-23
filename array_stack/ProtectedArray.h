#ifndef PROTECTED_ARRAY
#define PROTECTED_ARRAY

#include <iostream>
#include <exception>

using namespace std;

template <class Elem>
class ProtectedArray 
{
public:
	
	ProtectedArray (int sz = defaultProtectedArraySize):_size(sz) 
	{
		It = new Elem[sz];	
	}

	ProtectedArray (const ProtectedArray& src) 
	{
		init(src.size(), src.It);
	}

	~ProtectedArray() 
	{
		delete []It;
	}

	bool operator== (const ProtectedArray& another) const 
	{
		if (_size != another._size) return false;
		for (int i = 0; i < _size; i++) 
		{
			if (It[i] != another.It[i]) return false;
		}

		return true;
	}
	bool operator!= (const ProtectedArray& another) const 
	{
		return !(operator==(another));
	}

	ProtectedArray& operator= (const ProtectedArray& src) 
	{
		init(src.size(), src.It);
		return *this;
	}
	
	Elem& operator[] (int index) 
	{
		if (index >= _size || index < 0) throw (out_of_range);
		return It[index];
	}
	Elem& operator[] (int index) const 
	{
		if (index >= _size || index < 0) throw (out_of_range);
		return It[index];
	}

	int size() const
	{
		return _size;	
	};
	
protected:
	Elem *It;	

private:
	int _size;		
	void init(int sz, Elem* sourceArray) 
	{
		delete []It;
		It = new Elem[sz];
		_size = sz;

		for (int i = 0; i < sz; i++) 
		{
			It[i] = sourceArray[i];
		}
	}

	static const int defaultProtectedArraySize;
};

template <class Elem>
const int ProtectedArray<Elem>::defaultProtectedArraySize = 256;

#endif