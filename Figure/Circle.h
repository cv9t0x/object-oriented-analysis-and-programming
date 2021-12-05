#ifndef CIRCLE_H
#define CIRCLE_H
#include "Figure.h"

const double PI = 3.14;

class CircleException {};

class Circle : public Figure
{
private:
	double r;

public:
	Circle(const double r = 0);

	const double calc_area() override;
	const double calc_perimeter() override;
	const char* get_name() override;
};

Circle::Circle(const double r)
{
	if (r < 0)
		throw CircleException();

	this->r = r;
}

const double Circle::calc_area()
{
	if (area == 0)
	{
		area = PI * r * r;
	}
	
	return area;
}

const double Circle::calc_perimeter()
{
	if (perimeter == 0)
	{
		perimeter = 2 * PI * r;
	}

	return perimeter;
}

const char* Circle::get_name()
{
	return "Circle";
}


#endif // !CIRCLE_H