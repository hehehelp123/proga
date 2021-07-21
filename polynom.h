#pragma once
#include <iostream>
#include <vector>

struct monoch {
	float koef = 0;
	float deg = 0;
	explicit monoch(float k, float d) :
		koef(k),
		deg(d)
	{	}
};

class CPolynom {
	std::vector<monoch*> components;

	void plus1(monoch* comp);

public:
	explicit CPolynom() = default;

	explicit CPolynom(std::vector<float> koefDeg);

	CPolynom(const CPolynom& other);

	CPolynom& operator=(const CPolynom& other);

	friend CPolynom operator+(const CPolynom& first, const CPolynom& second);

	friend CPolynom operator*(const CPolynom& first, const CPolynom& second);

	friend CPolynom operator-(const CPolynom& first, const CPolynom& second);

	friend CPolynom operator/(const CPolynom& obj, const int num);

	friend bool operator==(const CPolynom& first, const CPolynom& second);

	friend bool operator!=(const CPolynom& first, const CPolynom& second);

	friend std::ostream& operator<<(std::ostream& out, const CPolynom& obj);

	friend std::istream& operator>>(std::istream& out, CPolynom& obj);

	CPolynom operator-() const;

	CPolynom operator+=(const CPolynom& other);

	CPolynom operator-=(const CPolynom& other);

	CPolynom operator/=(const int num);

	CPolynom operator*=(const CPolynom& other);

	float operator()(const int k) const;

	float& operator[](const int k);

	~CPolynom();
};
