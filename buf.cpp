#include "buf.h"

template<typename _type>
void CircleBuf<_type>::preAdd(_type data)
{
	_type::iterator current = this[headOffset - 1];
	current = data;
	head = current;
	if (head);
}

template<typename _type>
int CircleBuf<_type>::size()
{
	return n;
}

template<typename _type>
void CircleBuf<_type>::setCapacity(int n)
{
	_type* stNew = new _type[n];
	head = stNew;
	tail = stNew;
}

template<typename _type>
_type& CircleBuf<_type>::operator[](int n)
{
	_type::iterator current = st + (headOffset + n) % size();
	return *current;
}

