#include "cubic.h"
const side& side::operator=(const side& other)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			elems[i][j] = other.elems[i][j];
		}
	}
	return *this;
}
void side::setColor(int n)
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			elems[i][j] = n;
		}
	}
}
void side::rightRotate()
{
	side last = *this;
	elems[0][0] = last.elems[2][0];
	elems[0][1] = last.elems[1][0];
	elems[0][2] = last.elems[0][0];
	elems[1][0] = last.elems[2][1];
	elems[1][2] = last.elems[0][1];
	elems[2][0] = last.elems[2][2];
	elems[2][1] = last.elems[1][2];
	elems[2][2] = last.elems[0][2];
}
void side::leftRotate()
{
	rightRotate();
	rightRotate();
	rightRotate();
}
void side::sym()
{
	for (int i = 0; i < 3; ++i)
	{
		int k = elems[i][0];
		elems[i][0] = elems[i][2];
		elems[i][2] = k;
	}
}
cubic:: cubic() {
	for (int i = 0; i < 6; ++i)
	{
		sides[i].setColor(i);
	}
}
cubic::cubic(side data[6]) {
	for (int i = 0; i < 6; ++i)
	{
		sides[i] = data[i];
	}
}
const cubic& cubic:: operator=(const cubic& other)
{
	for (int i = 0; i < 6; ++i)
	{
		sides[i] = other.sides[i];
	}
	return *this;
}
const cubic& cubic::rotationR(bool fl)
{
	if (fl)
	{
		process = process + "R ";
	}
	sides[R].rightRotate();
	int line[3];
	line[0] = sides[F].elems[0][2];
	line[1] = sides[F].elems[1][2];
	line[2] = sides[F].elems[2][2];
	sides[F].elems[0][2] = sides[D].elems[2][2];
	sides[F].elems[1][2] = sides[D].elems[1][2];
	sides[F].elems[2][2] = sides[D].elems[0][2];
	sides[D].elems[0][2] = sides[B].elems[0][2];
	sides[D].elems[1][2] = sides[B].elems[1][2];
	sides[D].elems[2][2] = sides[B].elems[2][2];
	sides[B].elems[0][2] = sides[U].elems[2][2];
	sides[B].elems[1][2] = sides[U].elems[1][2];
	sides[B].elems[2][2] = sides[U].elems[0][2];
	sides[U].elems[0][2] = line[0];
	sides[U].elems[1][2] = line[1];
	sides[U].elems[2][2] = line[2];
	return *this;
}
const cubic& cubic::rotationR1(bool fl)
{
	if (fl)
	{
		process = process + "R1 ";
	}
	rotationR(false);
	rotationR(false);
	rotationR(false);
	return *this;
}
const cubic& cubic::rotationL1(bool fl)
{
	if (fl)
	{
		process = process + "L1 ";
	}
	sides[L].rightRotate();
	int line[3];
	line[0] = sides[F].elems[0][0];
	line[1] = sides[F].elems[1][0];
	line[2] = sides[F].elems[2][0];
	sides[F].elems[0][0] = sides[D].elems[2][0];
	sides[F].elems[1][0] = sides[D].elems[1][0];
	sides[F].elems[2][0] = sides[D].elems[0][0];
	sides[D].elems[0][0] = sides[B].elems[0][0];
	sides[D].elems[1][0] = sides[B].elems[1][0];
	sides[D].elems[2][0] = sides[B].elems[2][0];
	sides[B].elems[0][0] = sides[U].elems[2][0];
	sides[B].elems[1][0] = sides[U].elems[1][0];
	sides[B].elems[2][0] = sides[U].elems[0][0];
	sides[U].elems[0][0] = line[0];
	sides[U].elems[1][0] = line[1];
	sides[U].elems[2][0] = line[2];
	return *this;
}
const cubic& cubic::rotationL(bool fl)
{
	if (fl)
	{
		process = process + "L ";
	}
	rotationL1(false);
	rotationL1(false);
	rotationL1(false);
	return *this;
}
const cubic& cubic::rotationU(bool fl)
{
	if (fl)
	{
		process = process + "U ";
	}
	rotateZ(false);
	rotationR(false);
	rotateZ(false);
	rotateZ(false);
	rotateZ(false);
	return *this;
}
const cubic& cubic::rotationU1(bool fl)
{
	if (fl)
	{
		process = process + "U1 ";
	}
	rotationU(false);
	rotationU(false);
	rotationU(false);
	return *this;
}
const cubic& cubic::rotationF(bool fl)
{
	if (fl)
	{
		process = process + "F ";
	}
	rotateY(false);
	rotationL(false);
	rotateY(false);
	rotateY(false);
	rotateY(false);
	return *this;
}
const cubic& cubic::rotationF1(bool fl)
{
	if (fl)
	{
		process = process + "F1 ";
	}
	rotationF(false);
	rotationF(false);
	rotationF(false);
	return *this;
}
const cubic& cubic::rotationD(bool fl)
{
	if (fl)
	{
		process = process + "D ";
	}
	rotateZ(false);
	rotationL(false);
	rotateZ(false);
	rotateZ(false);
	rotateZ(false);
	return *this;
}
const cubic& cubic::rotationD1(bool fl)
{
	if (fl)
	{
		process = process + "D1 ";
	}
	rotationD(false);
	rotationD(false);
	rotationD(false);
	return *this;
}
const cubic& cubic::rotationB(bool fl)
{
	if (fl)
	{
		process = process + "B ";
	}
	rotateY(false);
	rotationR(false);
	rotateY(false);
	rotateY(false);
	rotateY(false);
	return *this;
}
const cubic& cubic::rotationB1(bool fl)
{
	if (fl)
	{
		process = process + "B1 ";
	}
	rotationB(false);
	rotationB(false);
	rotationB(false);
	return *this;
}
const cubic& cubic::rotationM(bool fl)
{
	if (fl)
	{
		process = process + "M ";
	}
	rotationD1(false);
	rotationU(false);
	rotateY1(false);
	return *this;
}
const cubic& cubic::rotationM1(bool fl)
{
	if (fl)
	{
		process = process + "M1 ";
	}
	rotationD(false);
	rotationU1(false);
	rotateY(false);
	return *this;
}
const cubic& cubic::rotateZ(bool fl)
{
	if (fl)
	{
		process = process + "Z ";
	}
	sides[F].rightRotate();
	sides[B].rightRotate();
	side bufCpy = sides[U];
	side bufTrans = sides[L];
	bufTrans.sym();
	bufTrans.rightRotate();
	sides[U] = bufTrans;
	bufTrans = sides[D];
	bufTrans.rightRotate();
	sides[L] = bufTrans;
	bufTrans = sides[R];
	bufTrans.sym();
	bufTrans.rightRotate();
	sides[D] = bufTrans;
	bufTrans = bufCpy;
	bufTrans.rightRotate();
	sides[R] = bufTrans;
	return *this;
}
const cubic& cubic::rotateX(bool fl)
{
	if (fl)
	{
		process = process + "X ";
	}
	sides[L].rightRotate();
	sides[R].rightRotate();
	side bufCpy = sides[F];
	side bufTrans = sides[D];
	bufTrans.leftRotate();
	bufTrans.sym();
	bufTrans.rightRotate();
	sides[F] = bufTrans;
	sides[D] = sides[B];
	bufTrans = sides[U];
	bufTrans.leftRotate();
	bufTrans.sym();
	bufTrans.rightRotate();
	sides[B] = bufTrans;
	sides[U] = bufCpy;
	return *this;
}
const cubic& cubic::rotateY(bool fl)
{
	if (fl)
	{
		process = process + "Y ";
	}
	sides[U].rightRotate();
	sides[D].rightRotate();
	side bufCpy = sides[F];
	side bufTrans = sides[B];
	sides[F] = sides[R];
	bufTrans.sym();
	sides[R] = bufTrans;
	sides[B] = sides[L];
	bufTrans = bufCpy;
	bufTrans.sym();
	sides[L] = bufTrans;
	return *this;
}
const cubic& cubic::rotateY1(bool fl)
{
	if (fl)
	{
		process = process + "Y1 ";
	}
	rotateY(false);
	rotateY(false);
	rotateY(false);
	return *this;
}
const cubic& cubic::rotateX1(bool fl)
{
	if (fl)
	{
		process = process + "X1 ";
	}
	rotateX(false);
	rotateX(false);
	rotateX(false);
	return *this;
}
const cubic& cubic::rotateZ1(bool fl)
{
	if (fl)
	{
		process = process + "Z1 ";
	}
	rotateZ(false);
	rotateZ(false);
	rotateZ(false);
	return *this;
}
const cubic& cubic::makeCross()
{
	for (int i = 0; i < 4; ++i)
	{
		makeCross1Part();
		rotateY1();
	}
	return *this;
}
const cubic& cubic::makeAnglesUp()
{
	for (int i = 0; i < 4; ++i)
	{
		makeAnglesUp1Part();
		rotateY1();
	}
	return *this;
}
const cubic& cubic::changeColorUpPartCross()
{
	for (int i = 0; i < 4; ++i)
	{
		rotationR();
		rotationM();
	}
	return *this;
}
const cubic& cubic::makeCross1Part()
{
	int& colorMain = sides[U].elems[1][2];
	int& colorOptional = sides[R].elems[0][1];
	int currentColor = sides[U].elems[1][1];
	int optionalColor = sides[R].elems[1][1];
	for (int i = 0; i < 4; ++i)
	{
		if (!((colorMain == currentColor && colorOptional == optionalColor) || (colorMain == optionalColor && colorOptional == currentColor)))
		{
			rotationR();
			rotationM();
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		if (!((colorMain == currentColor && colorOptional == optionalColor) || (colorMain == optionalColor && colorOptional == currentColor)))
		{
			rotationD();
			rotationR();
			rotationR();
		}
	}
	if (!((colorMain == currentColor && colorOptional == optionalColor) || (colorMain == optionalColor && colorOptional == currentColor)))
	{
		rotationR();
	}
	if (!((colorMain == currentColor && colorOptional == optionalColor) || (colorMain == optionalColor && colorOptional == currentColor)))
	{
		rotationR();
	}
	if (!((colorMain == currentColor && colorOptional == optionalColor) || (colorMain == optionalColor && colorOptional == currentColor)))
	{
		rotationR();
	}
	if (!((colorMain == currentColor && colorOptional == optionalColor) || (colorMain == optionalColor && colorOptional == currentColor)))
	{
		rotationF();
		rotationM();
		rotationR1();
	}
	if (!((colorMain == currentColor && colorOptional == optionalColor) || (colorMain == optionalColor && colorOptional == currentColor)))
	{
		rotationL();
		rotationM();
		rotationM();
		rotationR1();
	}
	if (!((colorMain == currentColor && colorOptional == optionalColor) || (colorMain == optionalColor && colorOptional == currentColor)))
	{
		rotationB();
		rotationM();
		rotationM();
		rotationM();
		rotationR1();
	}
	if (colorMain == optionalColor && colorOptional == currentColor)
	{
		changeColorUpPartCross();
	}
	for (; optionalColor != sides[R].elems[1][1];)
	{
		rotationM();
	}
	return *this;
}
const cubic& cubic::rotateAngle()
{
	rotationF1();
	rotationR();
	rotationF();
	rotationR1();
	rotationF1();
	rotationR();
	rotationF();
	rotationR1();
	return *this;
}
const cubic& cubic::makeAnglesUp1Part()
{
	int& colorMain = sides[U].elems[2][2];
	int& colorOptional1 = sides[R].elems[0][0];
	int& colorOptional2 = sides[F].elems[0][2];
	int currentColor = sides[U].elems[1][1];
	int optionalColor1 = sides[R].elems[1][1];
	int optionalColor2 = sides[F].elems[1][1];
	for (int i = 0; i < 4; ++i)
	{
		if (!(colorMain == currentColor && colorOptional1 == optionalColor1 && colorOptional2 == optionalColor2))
		{
			rotationR1();
			rotationD();
			rotationR();
			for (int i = 0; i < 3; ++i)
			{
				if (!(colorMain == currentColor && colorOptional1 == optionalColor1 && colorOptional2 == optionalColor2))
				{
					rotateAngle();
				}
			}
		}
	}
	if (!(colorMain == currentColor && colorOptional1 == optionalColor1 && colorOptional2 == optionalColor2))
	{
		rotationD();
		rotationD();
		rotationR1();
		rotationD();
		rotationR();
		for (int i = 0; i < 3; ++i)
		{
			if (!(colorMain == currentColor && colorOptional1 == optionalColor1 && colorOptional2 == optionalColor2))
			{
				rotateAngle();
			}
		}
	}
	if (!(colorMain == currentColor && colorOptional1 == optionalColor1 && colorOptional2 == optionalColor2))
	{
		rotationL();
		rotationD();
		rotationL1();
		rotationD1();
		rotationR1();
		rotationD();
		rotationR();
		for (int i = 0; i < 3; ++i)
		{
			if (!(colorMain == currentColor && colorOptional1 == optionalColor1 && colorOptional2 == optionalColor2))
			{
				rotateAngle();
			}
		}
	}
	if (!(colorMain == currentColor && colorOptional1 == optionalColor1 && colorOptional2 == optionalColor2))
	{
		rotateY1();

		rotationL();
		rotationD();
		rotationL1();
		rotationD1();

		rotateY();
		rotationD();

		rotationR1();
		rotationD();
		rotationR();
		for (int i = 0; i < 3; ++i)
		{
			if (!(colorMain == currentColor && colorOptional1 == optionalColor1 && colorOptional2 == optionalColor2))
			{
				rotateAngle();
			}
		}
	}

	if (!(colorMain == currentColor && colorOptional1 == optionalColor1 && colorOptional2 == optionalColor2))
	{
		rotateY1();
		rotateY1();

		rotationL();
		rotationD();
		rotationL1();
		rotationD1();

		rotateY();
		rotateY();
		rotationD();
		rotationD();

		rotationR1();
		rotationD();
		rotationR();
		for (int i = 0; i < 3; ++i)
		{
			if (!(colorMain == currentColor && colorOptional1 == optionalColor1 && colorOptional2 == optionalColor2))
			{
				rotateAngle();
			}
		}
	}
	return *this;
}
const cubic& cubic::pushToMiddleLeft()
{
	rotationD();
	rotationL();
	rotationD1();
	rotationL1();
	rotationD1();
	rotationF1();
	rotationD();
	rotationF();
	return *this;
}
const cubic& cubic::pushToMiddleRight()
{
	rotationD1();
	rotationR1();
	rotationD();
	rotationR();
	rotationD();
	rotationF();
	rotationD1();
	rotationF1();
	return *this;
}
const cubic& cubic::makeSecondLayout()
{
	int& colorMainPlace = sides[F].elems[1][2];
	int& colorOptionalPlace = sides[R].elems[1][0];
	int& colorMain = sides[F].elems[2][1];
	int& colorOptional = sides[D].elems[2][1];
	int optionalColor = sides[D].elems[1][1];
	for (int i = 0; i < 4; ++i, rotateY1())
	{
		if (colorMainPlace == optionalColor || colorOptionalPlace == optionalColor)
		{
			continue;
		}
		for (int i = 0; i < 4; ++i, rotationD())
		{
			if (colorMain == optionalColor || colorOptional == optionalColor)
			{
				pushToMiddleRight();
				break;
			}
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j, rotateY1())
		{
			for (int k = 0; k < 4; ++k, rotationD1())
			{
				if (colorMain == sides[F].elems[1][1])
				{
					if (colorOptional == sides[L].elems[1][1])
					{
						pushToMiddleLeft();
					}
					else
					{
						if (colorOptional == sides[R].elems[1][1])
						{
							pushToMiddleRight();
						}
					}
				}
			}
		}
	}
	return *this;
}
const cubic& cubic::changeUpToLeft()
{
	rotationU();
	rotationF();
	rotationR();
	rotationU();
	rotationR1();
	rotationU1();
	rotationF1();
	return *this;
}
const cubic& cubic::changeUpToRight()
{
	rotateY();
	changeUpToLeft();
	rotateY1();
	return *this;
}
const cubic& cubic::changeAllUpCrossColors()
{
	int& currentColor = sides[U].elems[1][2];
	int mainColor = sides[U].elems[1][1];
	for (int i = 0; i < 4; ++i, rotationU())
	{
		if (currentColor != mainColor)
		{
			changeColorUpPartCross();
		}
		if (currentColor != mainColor)
		{
			changeColorUpPartCross();
		}
	}
	return *this;
}
const cubic& cubic::makeLastCross()
{
	rotateZ();
	rotateZ();
	int& colorCurrent = sides[F].elems[1][1];
	int& colorCurrentChangeable = sides[F].elems[0][1];
	int& colorOptionalChangeable = sides[F].elems[0][1];
	for (int i = 0; i < 4; ++i, rotationU())
	{
		if ((colorCurrent == sides[F].elems[0][1]) || (colorCurrent == sides[U].elems[2][1]))
		{
			break;
		}
	}
	rotateY();
	if (colorCurrent != colorCurrentChangeable && colorCurrent != colorOptionalChangeable)
	{
		if (colorCurrent == sides[R].elems[0][1] || colorCurrent == sides[U].elems[1][2])
		{
			changeUpToRight();
			rotateY();
			if (colorCurrent == sides[R].elems[0][1] || colorCurrent == sides[U].elems[1][2])
			{
				changeUpToRight();
			}
		}
		else
		{
			rotateY();
			changeUpToRight();
			changeUpToLeft();
			if (colorCurrent == sides[R].elems[0][1] || colorCurrent == sides[U].elems[1][2])
			{
				changeUpToRight();
			}
		}
	}
	else
	{
		rotateY();
		if (colorCurrent == sides[R].elems[0][1] || colorCurrent == sides[U].elems[1][2])
		{
			changeUpToRight();
		}
	}
	changeAllUpCrossColors();
	return *this;
}
bool cubic::sameSet(int a1, int a2, int a3, int b1, int b2, int b3)
{
	int a[3];
	int b[3];
	a[0] = a1;
	a[1] = a2;
	a[2] = a3;
	b[0] = b1;
	b[1] = b2;
	b[2] = b3;
	for (int i = 0; i < 3; ++i)
	{
		bool fl = false;
		for (int j = 0; j < 3; ++j)
		{
			if (a[i] == b[j])
			{
				fl = true;
			}
		}
		if (!fl)
		{
			return false;
		}
	}
	return true;
}
const cubic& cubic::changeRotationOfLastAngles()
{
	rotationR();
	rotationF1();
	rotationR1();
	rotationF();
	rotationR();
	rotationF1();
	rotationR1();
	rotationF();
	return *this;
}
const cubic& cubic::changeAllExcept1()
{
	rotationF1();
	rotationL1();
	rotationF();
	rotationR1();
	rotationF1();
	rotationL();
	rotationF();
	rotationR();
	return *this;
}
const cubic& cubic::makeLastAngles()
{
	int& firstAngle1 = sides[U].elems[2][0];
	int& firstAngle2 = sides[F].elems[0][0];
	int& firstAngle3 = sides[L].elems[0][0];
	int& secondAngle1 = sides[U].elems[2][2];
	int& secondAngle2 = sides[F].elems[0][2];
	int& secondAngle3 = sides[R].elems[0][0];
	for (; !(sameSet(firstAngle1, firstAngle2, firstAngle3, sides[F].elems[0][1], sides[U].elems[0][1], sides[L].elems[0][1]) ||
		sameSet(secondAngle1, secondAngle2, secondAngle3, sides[F].elems[0][1], sides[U].elems[0][1], sides[R].elems[0][1]));)
	{
		changeAllExcept1();
	}
	if (sameSet(secondAngle1, secondAngle2, secondAngle3, sides[F].elems[0][1], sides[U].elems[0][1], sides[R].elems[0][1]))
	{
		rotateY();
	}
	rotateY();
	for (; !(sameSet(firstAngle1, firstAngle2, firstAngle3, sides[F].elems[0][1], sides[U].elems[0][1], sides[L].elems[0][1]) ||
		sameSet(secondAngle1, secondAngle2, secondAngle3, sides[F].elems[0][1], sides[U].elems[0][1], sides[R].elems[0][1]));)
	{
		changeAllExcept1();
	}
	for (int i = 0; i < 4; ++i, rotationU())
	{
		int m = 0;
		for (; secondAngle1 != sides[U].elems[1][1];)
		{
			++m;
			if (m > 10000)
			{
				return *this;
			}
			changeRotationOfLastAngles();
		}
	}
	return *this;
}
void cubic::out(std::ostream& out)
{
	for (int i = 2; i >= 0; --i)
	{
		out << "      ";
		for (int j = 0; j < 3; ++j)
		{
			out << sides[B].elems[i][j] << " ";
		}
		out << '\n';
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			out << sides[L].elems[2 - j][2 - i] << " ";
		}
		for (int j = 0; j < 3; ++j)
		{
			out << sides[U].elems[i][j] << " ";
		}
		for (int j = 0; j < 3; ++j)
		{
			out << sides[R].elems[j][2 - i] << " ";
		}
		out << '\n';
	}
	for (int i = 0; i < 3; ++i)
	{
		out << "      ";
		for (int j = 0; j < 3; ++j)
		{
			out << sides[F].elems[i][j] << " ";
		}
		out << '\n';
	}
	for (int i = 0; i < 3; ++i)
	{
		out << "      ";
		for (int j = 0; j < 3; ++j)
		{
			out << sides[D].elems[2 - i][j] << " ";
		}
		out << '\n';
	}
	out << '\n';
}
const cubic& cubic::makeallWithOut()
{
	process = "";
	makeCross();
	out();
	makeAnglesUp();
	out();
	makeSecondLayout();
	out();
	makeLastCross();
	out();
	makeLastAngles();
	out();
	std::cout << process << "\n";
	return *this;
}
const cubic& cubic::makeall()
{
	process = "";
	makeCross();
	makeAnglesUp();
	makeSecondLayout();
	makeLastCross();
	makeLastAngles();
	return *this;
}
const cubic& cubic::read(std::istream& in)
{
	for (int i = 2; i >= 0; --i)
	{
		for (int j = 0; j < 3; ++j)
		{
			in >> sides[B].elems[i][j];
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			in >> sides[L].elems[2 - j][2 - i];
		}
		for (int j = 0; j < 3; ++j)
		{
			in >> sides[U].elems[i][j];
		}
		for (int j = 0; j < 3; ++j)
		{
			in >> sides[R].elems[j][2 - i];
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			in >> sides[F].elems[i][j];
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			in >> sides[D].elems[2 - i][j];
		}
	}
	return *this;
}
bool cubic::existable()
{
	cubic buf = *this;
	buf.makeall();
	int color[6] = { -1, -1, -1, -1, -1, -1 };
	for (int k = 0; k < 6; ++k)
	{
		int current = -1;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if (current == -1)
				{
					current = sides[k].elems[0][0];
					if (current < 6)
					{
						color[current] = 1;
					}
					else
					{
						return false;
					}
				}
				if (sides[k].elems[0][0] != current)
				{
					return false;
				}
			}
		}
	}
	for (int i = 0; i < 6; ++i)
	{
		if (color[i] == -1)
		{
			return false;
		}
	}
	return true;
}
cubic cubic::randomCubic()
{
	srand(time(0));
	for (int j = 0; j < 1000; ++j)
	{
		int i = rand() % 20;
		switch (i)
		{
		case 0:
			rotateX();
			break;
		case 1:
			rotateX1();
			break;
		case 2:
			rotateY();
			break;
		case 3:
			rotateY1();
			break;
		case 4:
			rotateZ();
			break;
		case 5:
			rotateZ1();
			break;
		case 6:
			rotationB();
			break;
		case 7:
			rotationB1();
			break;
		case 8:
			rotationD();
			break;
		case 9:
			rotationD1();
			break;
		case 10:
			rotationF();
			break;
		case 11:
			rotationF1();
			break;
		case 12:
			rotationL();
			break;
		case 13:
			rotationL1();
			break;
		case 14:
			rotationM();
			break;
		case 15:
			rotationM1();
			break;
		case 16:
			rotationR();
			break;
		case 17:
			rotationR1();
			break;
		case 18:
			rotationU();
			break;
		case 19:
			rotationU1();
			break;
		}
	}
	return *this;
}
const cubic& cubic::cons()
{
	std::cout <<
		"case 0: rotateX()\ncase 1: rotateX1()\ncase 2: rotateY()\ncase 3: rotateY1()\ncase 4: rotateZ()\ncase 5: rotateZ1()\ncase 6: rotationB()\ncase 7: rotationB1()"
		"\ncase 8: rotationD()\ncase 9: rotationD1()\ncase 10: rotationF()\ncase 11: rotationF1()\ncase 12: rotationL()\ncase 13: rotationL1()\ncase 14: rotationM()\nc"
		"ase 15: rotationM1()\ncase 16: rotationR()\ncase 17: rotationR1()\ncase 18: rotationU()\ncase 19: rotationU1()\n";
	for (;;)
	{
		std::string i;
		std::cin >> i;
		int k = std::stoi(i);
		switch (k)
		{
		case 0:
			rotateX();
			break;
		case 1:
			rotateX1();
			break;
		case 2:
			rotateY();
			break;
		case 3:
			rotateY1();
			break;
		case 4:
			rotateZ();
			break;
		case 5:
			rotateZ1();
			break;
		case 6:
			rotationB();
			break;
		case 7:
			rotationB1();
			break;
		case 8:
			rotationD();
			break;
		case 9:
			rotationD1();
			break;
		case 10:
			rotationF();
			break;
		case 11:
			rotationF1();
			break;
		case 12:
			rotationL();
			break;
		case 13:
			rotationL1();
			break;
		case 14:
			rotationM();
			break;
		case 15:
			rotationM1();
			break;
		case 16:
			rotationR();
			break;
		case 17:
			rotationR1();
			break;
		case 18:
			rotationU();
			break;
		case 19:
			rotationU1();
			break;
		default:
			std::cout << "Wrong command. Game over";
			return *this;
		}
		out();
	}
	return *this;
}