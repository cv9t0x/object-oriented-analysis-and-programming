#include <iostream>
#include "Rational.h"

using namespace std;

int main()
{
	/*Rational r1(3, 5);
	Rational r2 = r1++;

	cout << r2 << endl;
	cout << ++r1 <<endl;*/

	Rational a(1, 4), b(0), c(-1);

	Rational::quadraticEquations(a, b, c);

	return 0;
}