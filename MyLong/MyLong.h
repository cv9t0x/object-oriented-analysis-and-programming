#ifndef MYLONG_H
#define MYLONG_H

#include <cmath>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class MyLongException
{
};

class MyLong
{
static const int BASE = 10000;

private:
	vector<int> digits;

	void clear();

public:
	MyLong();
	MyLong(long long num);
	MyLong(const MyLong& other);
	~MyLong();

	void operator=(const MyLong& other);

	bool operator==(const MyLong& other);
	bool operator!=(const MyLong& other);
	bool operator<(const MyLong& other);

	MyLong& operator+=(const MyLong& other);
	MyLong operator+(const MyLong& other);
	MyLong& operator++(int);
	MyLong& operator++();

	MyLong& operator-=(const MyLong& other);
	MyLong operator-(const MyLong& other);
	MyLong& operator--(int);
	MyLong& operator--();

	MyLong& operator*=(const MyLong& other);
	MyLong operator*(const MyLong& other);

	MyLong& operator/=(const int num);
	MyLong operator/(const int num);

	MyLong& operator%=(const int num);
	MyLong operator%(const int num);

	friend ostream& operator<<(ostream& out, MyLong& num);

	static MyLong pow(MyLong& num, int degree);
	static MyLong pow(MyLong& num, MyLong degree);
};

#endif // !MYLONG_H
