#include <iostream>
#include "MyLong.h"

using namespace std;

int main()
{
	MyLong num1(9223372036854775807);
	MyLong num2(num1);
	MyLong num3 = num1 * num2;

	cout << num3;

	return 0;
}