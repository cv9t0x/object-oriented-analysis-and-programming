#include <iostream>
#include "Rational.h"

using namespace std;

int main()
{
	/*Rational r1(3, 5);
	Rational r2 = r1++;

	cout << r2 << endl;
	cout << ++r1 <<endl;*/

	//10x^2 + x - 21 = 0		x1 = -1.5; x2 = 1.4
	
	Rational a(10), b(1), c(-21);

	Rational::quadraticEquations(a, b, c);

	return 0;
}	