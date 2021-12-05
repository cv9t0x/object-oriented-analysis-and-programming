#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Figure.h"

class RectangleException {};

class Rectangle : public Figure
{
private:
	double a;
	double b;

public:
	Rectangle();
	Rectangle(const double a, const double b);

	const double calc_area() override;
	const double calc_perimeter() override;
	const char* get_name() override;
};

Rectangle::Rectangle()
{
	this->a = 0;
	this->b = 0;
}

Rectangle::Rectangle(const double a, const double b)
{
	if (a < 0 || b < 0)
		throw RectangleException();

	this->a = a;
	this->b = b;
}

const double Rectangle::calc_area()
{
	if (area == 0)
	{
		area = a * b;
	}

	return area;
}

const double Rectangle::calc_perimeter()
{
	if (perimeter == 0)
	{
		perimeter = 2 * (a + b);
	}

	return perimeter;
}

const char* Rectangle::get_name()
{
	return "Rectangle";
}

#endif // !RECTANGLE_H

