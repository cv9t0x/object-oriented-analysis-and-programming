#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Figure.h"
#include <math.h>

class TriangleException {};

class Triangle : public Figure
{
private:
	double a;
	double b;
	double c;

public:
	Triangle();
	Triangle(const double a, const double b, const double c);

	bool isExist(const double a, const double b, const double c);

	const double calc_area() override;
	const double calc_perimeter() override;
	const char* get_name() override;
};

Triangle::Triangle()
{
	this->a = 0;
	this->b = 0;
	this->c = 0;
}

Triangle::Triangle(const double a, const double b, const double c)
{
	if (!isExist(a, b, c) || a < 0 || b < 0 || c < 0)
		throw TriangleException();

	this->a = a;
	this->b = b;
	this->c = c;
}

bool Triangle::isExist(const double a, const double b, const double c)
{
	return (a + b > c && a + c > b && b + c > a) ? true : false;
}

const double Triangle::calc_area()
{
	if (area == 0)
	{
		double pHalf = 0.5 * calc_perimeter();
		area = sqrt(pHalf * (pHalf - a) * (pHalf - b) * (pHalf - c));
	}

	return area;
}

const double Triangle::calc_perimeter()
{
	if (perimeter == 0)
	{
		perimeter = a + b + c;
	}

	return perimeter;
}

const char* Triangle::get_name()
{
	return "Triangle";
}

#endif // !TRIANGLE_H