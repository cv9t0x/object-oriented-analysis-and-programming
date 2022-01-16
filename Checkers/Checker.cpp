#include "Checker.h"

Checker::Checker(bool isWhite, bool isCrown)
{
	this->isWhite = isWhite;
	this->isCrown = isCrown;
}

Checker::~Checker()
{
}

ostream& operator<<(ostream& out, Checker& checker)
{
	out << (checker.isWhite ? "white" : "black") << " " << (checker.isCrown ? "crown" : "") << endl;

	return out;
}