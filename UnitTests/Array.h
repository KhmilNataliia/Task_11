#ifndef ARRAY
#define ARRAY

#include <iostream>
#include <exception>

using namespace std;

template <class Elem>
class Array 
{
public:
	Array (int sz = defaultArraySize):_size(sz) 
	{
		It = new Elem[sz];	
	}

	Array (const Array& src)
	{
		init(src.size(), src.It);
	}

	
	~Array()
	{
		delete []It;
	}

	
	bool operator== (const Array& another) const 
	{
		if (_size != another._size) return false;
		for (int i = 0; i < _size; i++) 
		{
			if (It[i] != another.It[i]) 
				return false;
		}

		return true;
	}
	bool operator!= (const Array& another) const 
	{
		return !(operator==(another));
	}

	Array& operator= (const Array& src) 
	{
		init(src.size(), src.It);
	}
	
	Elem& operator[] (int index) 
	{
		if (index >= _size || index < 0) throw out_of_range("");
		return It[index];
	}

	Elem& operator[] (int index) const 
	{
		if (index >= _size || index < 0) throw out_of_range("");
		return It[index];
	}

	int size() const 
	{
		return _size;	
	}
	
private:
	int _size;		
	Elem *It;		

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

	static const int defaultArraySize;
};

template <class Elem>
const int Array<Elem>::defaultArraySize = 256;

#endif;