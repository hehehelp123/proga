#include "polynom.h"

CPolynom::~CPolynom()
{
	for (int i = 0; i < components.size(); ++i)
		delete(components[i]);
}

CPolynom::CPolynom(std::vector<float> koefDeg)
{
	for (int i = 0; i < koefDeg.size() / 2; ++i)
		components.push_back(new monoch(koefDeg[2 * i], koefDeg[2 * i + 1]));
}

CPolynom::CPolynom(const CPolynom& other)
{
	for (int i = 0; i < other.components.size(); ++i)
		(*this).plus1(other.components[i]);
}

CPolynom& CPolynom::operator=(const CPolynom& other)
{
	if (this == &other)
		return *this;
	components.resize(0);
	for (int i = 0; i < other.components.size(); ++i)
		(*this).plus1(other.components[i]);
	return *this;
}

void CPolynom::plus1(monoch* comp)
{
	(*this)[comp->deg] += comp->koef;
}

CPolynom CPolynom::operator-() const
{
	CPolynom result = *this;
	for (int i = 0; i < result.components.size(); ++i)
	{
		result.components[i]->koef = -result.components[i]->koef;
	}
	return result;
}

CPolynom CPolynom::operator+=(const CPolynom& other)
{
	*this = *this + other;
	return *this;
}

CPolynom CPolynom::operator-=(const CPolynom& other)
{
	*this = *this - other;
	return *this;
}

CPolynom CPolynom::operator/=(const int num)
{
	*this = *this / num;
	return *this;
}

CPolynom CPolynom::operator*=(const CPolynom& other)
{
	*this = *this * other;
	return *this;
}

float CPolynom::operator()(const int k) const
{
	for (int i = 0; i < components.size(); ++i)
	{
		if (components[i]->deg == k)
		{
			return components[i]->koef;
		}
	}
	return 0;
}

float& CPolynom::operator[](const int k)
{
	for (int i = 0; i < components.size(); ++i)
	{
		if (components[i]->deg == k)
		{
			return components[i]->koef;
		}
	}
	components.push_back(new monoch(0, k));
	return (*this)[k];
}




CPolynom operator+(const CPolynom& first, const CPolynom& second)
{
	CPolynom result;
	for (int i = 0; i < first.components.size(); ++i)
		result.plus1(first.components[i]);
	for (int i = 0; i < second.components.size(); ++i)
		result.plus1(second.components[i]);
	return result;
}

CPolynom operator*(const CPolynom& first, const CPolynom& second)
{
	CPolynom result;
	for (int i = 0; i < first.components.size(); ++i)
		for (int j = 0; j < second.components.size(); ++j)
			result.plus1(&monoch(second.components[j]->koef * first.components[i]->koef, second.components[j]->deg + first.components[i]->deg));
	return result;
}

CPolynom operator-(const CPolynom& first, const CPolynom& second)
{
	return (first + -(second));
}

CPolynom operator/(const CPolynom& obj, const int num)
{
	CPolynom result = obj;
	for (int i = 0; i < result.components.size(); ++i)
	{
		result.components[i]->koef = result.components[i]->koef / num;
	}
	return result;
}


bool operator==(const CPolynom& first, const CPolynom& second)
{
	for (int i = 0; i < first.components.size(); ++i)
		if (first(first.components[i]->deg) != second(first.components[i]->deg))
			return false;
	for (int i = 0; i < second.components.size(); ++i)
		if (first(second.components[i]->deg) != second(second.components[i]->deg))
			return false;
	return true;;
}

bool operator!=(const CPolynom& first, const CPolynom& second)
{
	return !(first == second);
}

std::ostream& operator<<(std::ostream& out, const CPolynom& obj)
{
	bool fl = true;
	for (int i = 0; i < obj.components.size(); ++i)
	{
		if (fl)
		{
			if (obj.components[i]->koef == 0)
				continue;
			if (obj.components[i]->koef != 1 || obj.components[i]->deg == 0)
				out << (obj.components[i]->koef);
			if (obj.components[i]->deg != 0)
			{
				if (obj.components[i]->deg != 1)
					out << "x^" << obj.components[i]->deg;
				else
					out << "x";
			}
			fl = false;
			continue;
		}
		if (obj.components[i]->koef)
		{
			if (obj.components[i]->koef > 0)
				out << " + ";
			else
				out << " - ";
			out << std::abs(obj.components[i]->koef);
			if (obj.components[i]->deg != 0)
			{
				if (obj.components[i]->deg != 1)
					out << "x^" << obj.components[i]->deg;
				else
					out << "x";
			}
		}
	}
	return out;
}


std::istream& operator>>(std::istream& in, CPolynom& obj)
{
	CPolynom result;
	int n;
	float a, b;
	in >> n;
	for (int i = 0; i < n; ++i)
	{
		in >> a >> b;
		result.plus1(&monoch(a, b));
	}
	obj = result;
	return in;
}
