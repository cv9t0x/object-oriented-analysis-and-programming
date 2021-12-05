#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Polygon.h"
#include "Figure.h"

using namespace std;

int main()
{
	Circle circle(1.5);
	Rectangle rectangle(5, 10.1);
	Triangle triangle(2.2, 3.7, 5);


	const int polygonSize = 5;
	double data[polygonSize][2]{ {0.6, 2.1}, {1.8, 3.6}, {2.2, 2.3}, {3.6, 2.4}, {3.1, 0.5} };
	double** coordinates = new double* [polygonSize];
	for (int i = 0; i < polygonSize; i++)
	{
		coordinates[i] = new double[2];
		for (int j = 0; j < 2; j++)
		{
			coordinates[i][j] = data[i][j];
		}
	}

	Polygon polygon(coordinates, polygonSize);

	const int figureSize = 4;
	Figure* figures[figureSize]{&circle, &rectangle, &triangle, &polygon};

	for (int i = 0; i < figureSize; i++)
	{
		cout << "Figure: " << figures[i]->get_name() << endl;
		cout << "Area = " << figures[i]->calc_area() << endl;
		cout << "Perimeter = " << figures[i]->calc_perimeter() << endl;
		cout << endl;
	}

	double sum_area = 0;
	double sum_perimeter = 0;

	for (int i = 0; i < figureSize; i++)
	{
		sum_area += figures[i]->calc_area();
		sum_perimeter += figures[i]->calc_perimeter();
	}

	cout << "Sum of areas = " << sum_area << endl;
	cout << "Sum of perimeter = " << sum_perimeter << endl;

	return 0;
}