#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

enum colors {
	white,
	green,
	red,
	blue,
	orange,
	yellow
};

enum sides {
	U,
	F,
	R,
	B,
	L,
	D
};

struct side {
	int elems[3][3];
	const side& operator=(const side& other);
	void setColor(int n);
	void rightRotate();
	void leftRotate();
	void sym();
};

class cubic
{
public:
	side sides[6] = {};
	std::string process = "";
	cubic();
	explicit cubic(side data[6]);
	const cubic& operator=(const cubic& other);
	const cubic& rotationR(bool fl = true);
	const cubic& rotationR1(bool fl = true);
	const cubic& rotationL1(bool fl = true);
	const cubic& rotationL(bool fl = true);
	const cubic& rotationU(bool fl = true);
	const cubic& rotationU1(bool fl = true);
	const cubic& rotationF(bool fl = true);
	const cubic& rotationF1(bool fl = true);
	const cubic& rotationD(bool fl = true);
	const cubic& rotationD1(bool fl = true);
	const cubic& rotationB(bool fl = true);
	const cubic& rotationB1(bool fl = true);
	const cubic& rotationM(bool fl = true);
	const cubic& rotationM1(bool fl = true);
	const cubic& rotateZ(bool fl = true);
	const cubic& rotateX(bool fl = true);
	const cubic& rotateY(bool fl = true);
	const cubic& rotateY1(bool fl = true);
	const cubic& rotateX1(bool fl = true);
	const cubic& rotateZ1(bool fl = true);
	const cubic& makeCross();
	const cubic& makeAnglesUp();
	const cubic& changeColorUpPartCross();
	const cubic& makeCross1Part();
	const cubic& rotateAngle();
	const cubic& makeAnglesUp1Part();
	const cubic& pushToMiddleLeft();
	const cubic& pushToMiddleRight();
	const cubic& makeSecondLayout();
	const cubic& changeUpToLeft();
	const cubic& changeUpToRight();
	const cubic& changeAllUpCrossColors();
	const cubic& makeLastCross();
	bool sameSet(int a1, int a2, int a3, int b1, int b2, int b3);
	const cubic& changeRotationOfLastAngles();
	const cubic& changeAllExcept1();
	const cubic& makeLastAngles();
	void out(std::ostream& out = std::cout);
	const cubic& makeallWithOut();
	const cubic& makeall();
	const cubic& read(std::istream& in = std::cin);
	bool existable();
	cubic randomCubic();
	const cubic& cons();
};
		