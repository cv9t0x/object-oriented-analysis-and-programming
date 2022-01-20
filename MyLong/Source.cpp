#include <iostream>
#include "MyLong.h"

using namespace std;

int main()
{
	MyLong num1(92233720368547758);
	MyLong num2(92233720368547758);
	MyLong result;

	result = num1 + num2;
	cout << "Sum: " << result;

	result = num1 - num2;
	cout << "Sub: " << result;

	result = num1 * num2;
	cout << "Mul: " << result;

	result /= 2;
	cout << "Div by short: " << result;

	return 0;
}