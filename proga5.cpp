#include <iostream>
#include <algorithm>
#include "buf.h"

int main()
{
	CircleBuf<int> example;
	example.setCapacity(7);
	example.preAdd(2);
	example.preAdd(4);
	example.preAdd(6);
	example.preAdd(21);
	example.preAdd(3);
	example.preAdd(4);
	example.preAdd(466);
	example.preAdd(4);
	for (auto a : example)
	{
		std::cout << a << ' ';
	}
	std::sort(example.begin(), example.end());
	std::cout << std::endl;
	for (auto a : example)
		std::cout << a << ' ';
	example.setCapacity(10);
	example.preDel();
	example.postDel();
	example.preDel();
	example.preDel();
	example.preDel();
	std::cout << std::endl;
	for (auto a : example)
		std::cout << a << ' ';
	example.preAdd(3);
	example.preAdd(458);
	std::cout << std::endl;
	for (auto a : example)
		std::cout << a << ' ';
	std::sort(example.begin(), example.end());
	std::cout << std::endl;
	for (auto a : example)
		std::cout << a << ' ';
	CircleBuf<int> example2;
	example.preAdd(3);
	example2 = example;
	example.setCapacity(1);
	std::cout << std::endl;
	for (auto a : example2)
		std::cout << a << ' ';
	example2[3] = 666;
	example2.front() = 123;
	std::cout << std::endl;
	for (auto a : example2)
		std::cout << a << ' ';
}
