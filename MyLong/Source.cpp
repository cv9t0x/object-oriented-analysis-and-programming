#include <iostream>
#include "MyLong.h"

using namespace std;

int main()
{
	MyLong num1(125);
	MyLong num2(1);
	MyLong result;

	cout << "-------------" << endl;
	result = num1 + num2;
	cout << "+: " << result;
	cout << "-------------" << endl;

	result = num1 - num2;
	cout << "-: " << result;
	cout << "-------------" << endl;

	result = num1 * num2;
	cout << "*: " << result;
	cout << "-------------" << endl;

	result /= 5;
	cout << "/ by int: " << result;
	cout << "-------------" << endl;

	result = MyLong::pow(num1, 3);
	cout << "^ by int: " << result;
	cout << "-------------" << endl;

	MyLong degree(5);
	result = MyLong::pow(num1, degree);
	cout << "^ by MyLong: " << result;
	cout << "-------------" << endl;

	//cout << (3 / 2) << endl;

	return 0;
}