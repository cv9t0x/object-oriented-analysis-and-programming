#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Figure.h"

using namespace std;

int main()
{
	Circle circle(1.5);
	Rectangle rectangle(5, 10.1);
	Triangle triangle(2.2, 3.7, 5);

	const int size = 3;
	Figure* figures[size]{&circle, &rectangle, &triangle};

	for (int i = 0; i < size; i++)
	{
		cout << "Figure: " << figures[i]->get_name() << endl;
		cout << "Area = " << figures[i]->calc_area() << endl;
		cout << "Perimeter = " << figures[i]->calc_perimeter() << endl;
		cout << endl;
	}

	double sum_area = 0;
	double sum_perimeter = 0;

	for (int i = 0; i < size; i++)
	{
		sum_area += figures[i]->calc_area();
		sum_perimeter += figures[i]->calc_perimeter();
	}

	cout << "Sum of areas = " << sum_area << endl;
	cout << "Sum of perimeter = " << sum_perimeter << endl;

	return 0;
}