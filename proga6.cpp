#include <iostream>
#include "cubic.h"
#include <fstream>

int main()
{
	cubic a;
	a.out();
	a.randomCubic();
	std::ofstream out("output.txt");
	a.out(out);
	out.close();
	std::ifstream in("output.txt");
	cubic b;
	b.read(in);
	b.makeall();
	std::cout << b.existable() << std::endl;
	cubic c;
	c.randomCubic();
	c.out();
	c.makeallWithOut();
	cubic d;
	d.cons();
}
