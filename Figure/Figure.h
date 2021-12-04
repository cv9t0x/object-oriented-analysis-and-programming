#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
protected:
	double area;
	double perimeter;

public:
	Figure();

	virtual const double calc_area() = 0;
	virtual const double calc_perimeter() = 0;
	virtual const char* get_name() = 0;
};

Figure::Figure()
{
	area = 0;
	perimeter = 0;
}

#endif // !FIGURE_H

