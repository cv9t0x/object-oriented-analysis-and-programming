#ifndef CHECKER_H
#define CHECKER_H

#include <string>
#include <istream>

using namespace std;

class Checker
{
private:
	bool isWhite;
	bool isCrown;

public:
	Checker(bool isWhite, bool isCrown);
	~Checker();
	
	friend ostream& operator<<(ostream& out, Checker& checker);
};


#endif // !CHECKER_H

