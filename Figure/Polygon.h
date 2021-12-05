#ifndef POLYGON_H
#define POLYGON_H
#include "Figure.h"
#include <cmath>

class Polygon : public Figure
{
private:
	double** coordinates;
	int size;

public:
	Polygon(double** coordinates, const int size);
	~Polygon();

	const double calc_area() override;
	const double calc_perimeter() override;
	const char* get_name() override;
};

Polygon::Polygon(double** coordinates, const int size)
{
	this->size = size;
	this->coordinates = new double* [size];

	for (int i = 0; i < size; i++)
	{
		this->coordinates[i] = new double[2];

		for (int j = 0; j < 2; j++)
		{
			this->coordinates[i][j] = coordinates[i][j];
		}
	}
}

Polygon::~Polygon()
{
	for (int i = 0; i < size; i++)
		delete[] coordinates[i];

	delete[] coordinates;
}

const double Polygon::calc_area()
{
	if (area == 0)
	{
		double sum1 = coordinates[size - 1][0] * coordinates[0][1];
		double sum2 = coordinates[size - 1][1] * coordinates[0][0];

		for (int i = 0; i < size - 1; i++)
		{
			sum1 = sum1 + coordinates[i][0] * coordinates[i + 1][1];
			sum2 = sum2 + coordinates[i][1] * coordinates[i + 1][0];
		}

		area = (sum1 > sum2) ? (sum1 - sum2) / 2 : (sum2 - sum1) / 2;
	}

	return area;
}

const double Polygon::calc_perimeter()
{
	if (perimeter == 0)
	{
		perimeter = sqrt((coordinates[0][0] - coordinates[size - 1][0]) * (coordinates[0][0] - coordinates[size - 1][0]) + (coordinates[0][1] - coordinates[size - 1][1]) * (coordinates[0][1] - coordinates[size - 1][1]));
		for (int i = 0; i < size - 1; i++)
		{
			perimeter += sqrt((coordinates[i][0] - coordinates[i+1][0]) * (coordinates[i][0] - coordinates[i + 1][0]) + (coordinates[i][1] - coordinates[i + 1][1]) * (coordinates[i][1] - coordinates[i + 1][1]));
		}
	}

	return perimeter;
}

const char* Polygon::get_name()
{
	return "Polygon";
}
#endif // !POLYGON_H

