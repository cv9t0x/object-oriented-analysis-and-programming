#include "MyLong.h"
#include <iostream>

MyLong::MyLong()
{
	digits.push_back(0);
}

MyLong::MyLong(long long num)
{
	if (num == 0)
		digits.push_back(num);

	while (num)
	{
		digits.push_back(num % BASE);
		num /= BASE;
	}
}

MyLong::MyLong(const MyLong& other)
{
	clear();

	for(auto digit : other.digits)
		digits.push_back(digit);
}

MyLong::~MyLong()
{
	clear();
}

void MyLong::clear()
{
	digits.clear();
}

void MyLong::operator=(const MyLong& other)
{
	clear();

	for (auto digit : other.digits)
		digits.push_back(digit);
}

bool MyLong::operator==(const MyLong& other)
{
	if (digits.size() > other.digits.size() || digits.size() < other.digits.size())
		return false;

	for (int i = 0; i < digits.size(); i++)
	{
		if (digits[i] != other.digits[i])
			return false;
	}

	return true;
}

bool MyLong::operator!=(const MyLong& other)
{
	return !(*this == other);
}

bool MyLong::operator<(const MyLong& other)
{
	if (other.digits.size() > digits.size())
		return true;
	else if (digits.size() > other.digits.size())
		return false;
	else 
	{
		for (int i= digits.size() - 1; i >= 0; i--)
		{
			int t_digit = digits[i];
			int o_digit = other.digits[i];

			if (t_digit < o_digit)
				return true;
		}

		return false;
	}
}

MyLong& MyLong::operator+=(const MyLong& other)
{
	int size = other.digits.size() > digits.size() ? digits.size() : other.digits.size();

	for (int i = 0; i < size; i++)
		digits[i] += other.digits[i];

	for (int i = 0; i < digits.size() - 1; i++)
	{
		if (digits[i] >= BASE)
		{
			digits[i] -= BASE;
			digits[i + 1]++;
		}
	}

	return *this;
}

MyLong MyLong::operator+(const MyLong& other)
{
	MyLong result(*this);
	result += other;
	return result;
}

MyLong& MyLong::operator++(int)
{
	MyLong result(*this);
	*this += 1;
	return result;
}

MyLong& MyLong::operator++()
{
	*this += 1;
	return *this;
}

MyLong& MyLong::operator-=(const MyLong& other)
{
	int size = other.digits.size() > digits.size() ? digits.size() : other.digits.size();

	for (int i = 0; i < size; i++)
		digits[i] -= other.digits[i];

	for (int i = 0; i < digits.size() - 1; i++)
	{
		if (digits[i] < 0)
		{
			digits[i] += BASE;
			digits[i + 1]--;
		}
	}

	return *this;
}

MyLong MyLong::operator-(const MyLong& other)
{
	MyLong result(*this);
	result -= other;
	return result;
}

MyLong& MyLong::operator--(int)
{
	MyLong result(*this);
	*this -= 1;
	return result;
}

MyLong& MyLong::operator--()
{
	*this -= 1;
	return *this;
}

MyLong& MyLong::operator*=(const MyLong& other)
{
	MyLong result;

	result.digits.resize(digits.size() + other.digits.size());

	for (int i = 0; i < digits.size(); i++)
	{
		for (int j = 0; j < other.digits.size(); j++)
		{
			result.digits[i + j] += digits[i] * other.digits[j];
		}
	}

	for (int i = 0; i < result.digits.size() - 1; i++)
	{
		result.digits[i + 1] += result.digits[i] / BASE;
		result.digits[i] %= BASE;
	}

	*this = result;

	return *this;
}

MyLong MyLong::operator*(const MyLong& other)
{
	MyLong result(*this);
	result *= other;
	return result;
}

MyLong& MyLong::operator/=(const int num)
{
	if (num == 0)
		throw new MyLongException();
	
	for (int i = digits.size() - 1; i >= 0; i--) {
		if (i) {
			digits[i - 1] += (digits[i] % num) * BASE;
		}

		digits[i] /= num;
	}

	return *this;
}

MyLong MyLong::operator/(const int num)
{
	MyLong result(*this);
	result /= num;
	return result;
}

MyLong& MyLong::operator%=(const int num)
{
	*this -= (*this / num) * num;

	return *this;
}

MyLong MyLong::operator%(const int num)
{
	MyLong result(*this);
	result %= num;
	return result;
}

MyLong MyLong::pow(MyLong& num, int degree)
{
	if (degree < 0)
		throw new MyLongException();

	if (degree == 0)
		return 1;
	else if (degree % 2 == 0)
	{
		MyLong buf = pow(num, degree / 2);
		return buf * buf;
	}
	else
		return num * pow(num, degree - 1);
}

MyLong MyLong::pow(MyLong& num, MyLong degree)
{
	if (degree < 0)
		throw new MyLongException();

	if (degree == 0)
		return 1;
	else if (degree % 2 == 0)
	{
		MyLong buf = pow(num, degree / 2);
		return buf * buf;
	}
	else
		return num * pow(num, degree - 1);
}

ostream& operator<<(ostream& out, MyLong& num)
{
	string result, buffer;
	bool flag = true;
	
	for (int i = num.digits.size() - 1; i >= 0; i--)
	{
		string s = to_string(num.digits[i]);

		buffer += s.insert(0, "0000", 4 - s.length());
	}

	for (int i = 0; i < buffer.length(); i++)
	{
		if (buffer[i] == '0' && flag) continue;

		result += buffer[i];
		flag = false;
	}

	result = result.length() == 0 ? "0" : result;

	out << result << endl;

	return out;
}