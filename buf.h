#pragma once
#include <iostream>

template<typename _type>
class CircleBuf {
	int Csize = 0;
	_type* st = nullptr;
	bool is_empty = true;
	int elem = 0;
public:
	class iterator : public std::iterator<std::random_access_iterator_tag, _type> {
		int& sizeBuf;
		_type*& st;
	public:
		_type* ref = nullptr;
		int number = 0;
		iterator(int& n, _type*& st):
			sizeBuf(n), st(st), ref(st)
		{
		}
		iterator operator=(const iterator other) {
			number = other.number;
			ref = other.ref;
			return *this;
		}
		_type& operator*() const {
			return *ref;
		}
		iterator operator++() {
			number = (number + 1);
			ref = st + (ref - st + 1) % sizeBuf;
			return *this;
		}
		iterator operator--() {
			number = (number - 1);
			ref = st + (ref - st - 1 + sizeBuf) % sizeBuf;
			return *this;
		}
		iterator operator-(int k) const {
			iterator refNew(sizeBuf, st);
			refNew.ref = st + (ref - st - k + sizeBuf) % sizeBuf;
			refNew.number = (number - k);
			return refNew;
		}
		iterator operator+(int k) const {
			iterator refNew(sizeBuf, st);
			refNew.ref = st + (ref - st + k + sizeBuf) % sizeBuf;
			refNew.number = (number + k);
			return refNew;
		}
		int operator-(const iterator& other) const {
			return (ref - other.ref + sizeBuf) % sizeBuf;
		}
		bool operator>(const iterator& other) const {
			return (ref > other.ref);
		}
		bool operator<(const iterator& other) const {
			return (ref < other.ref);
		}
		bool operator==(const iterator& other) const {
			return (number == other.number);
		}
		bool operator!=(const iterator& other) const {
			return (number != other.number);
		}
	};
private:
	iterator head;
	iterator tail;
	int headOffset = 0;
public:
		
	CircleBuf() :
		head(Csize, st), tail(Csize, st)
	{
	}
	const CircleBuf& operator=(const CircleBuf& other)
	{
		if(this == &other)
			return *this;
		int elemCnt = other.elem;
		_type* CpyElem = new _type[elemCnt];
		int current = 0;
		for (auto a : other) 
		{
			CpyElem[current++] = a;
		}
		setCapacity(0);
		setCapacity(other.size());
		for (int i = 0; i < elemCnt; ++i)
		{
			preAdd(CpyElem[elemCnt - 1 - i]);
		}
		delete[] CpyElem;
		return *this;
	}
	void preAdd(_type data)
	{
		if (elem < Csize)
			++elem;
		*(--head) = data;
		if (is_empty)
		{
			is_empty = false;
			--tail;
			head.number = 0;
			tail.number = elem;
			return;
		}
		if (head.ref == tail.ref) --tail;
		head.number = 0;
		tail.number = elem;
	}
	void postAdd(_type data)
	{
		if (elem < Csize)
			++elem;
		*(++tail) = data;
		if (is_empty)
		{
			is_empty = false;
			++head;
			head.number = 0;
			tail.number = elem;
			return;
		}
		if (head.ref == tail.ref) ++head;
		head.number = 0;
		tail.number = elem;
	}
	void preDel()
	{
		if (elem)
			--elem;
		if (is_empty)
		{
			return;
		}
		if (head.ref == tail.ref)
		{
			is_empty = true;
		}
		else
			++head;
		head.number = 0;
		tail.number = elem;
	}
	void postDel()
	{
		if (elem)
			--elem;
		if (is_empty)
		{
			return;
		}
		if (head.ref == tail.ref)
		{
			is_empty = true;
		}
		else
			--tail;
		if (head.ref == tail.ref) ++head;
		head.number = 0;
		tail.number = elem;
	}
	int size() const
	{
		return Csize;
	}
	void setCapacity(int sizeBuf)
	{
		if (Csize == 0)
		{
			is_empty = true;
			st = new _type[sizeBuf];
			Csize = sizeBuf;
			head = iterator(Csize, st);
			tail = iterator(Csize, st);
		}
		else
		{
			int elemCnt = elem;
			_type* CpyElem = new _type[elemCnt];
			int current = 0;
			for (auto a : *this)
				CpyElem[current++] = a;
			elem = 0;
			is_empty = true;
			delete[] st;
			st = new _type[sizeBuf];
			Csize = sizeBuf;
			head = iterator(Csize, st);
			tail = iterator(Csize, st);
			if (Csize == 0)
				return;
			for (int i = 0; i < elemCnt; ++i)
			{
				preAdd(CpyElem[elemCnt - 1 - i]);
			}
			delete[] CpyElem;
		}
	}
	_type& operator[](int sizeBuf)
	{
		return *(head + sizeBuf);
	}
	
	_type& front()
	{
		return *(head);
	}

	_type& back()
	{
		return *(tail);
	}

	iterator begin() const{
		return head;
	}
	iterator end() const{
		iterator x = tail + 1;
		x.number = elem;
		return x;
	}

	~CircleBuf()
	{
		setCapacity(0);
	}
};
