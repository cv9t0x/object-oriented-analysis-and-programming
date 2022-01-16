#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
	string path = "Board.txt";

	Board board(path);

	cout << board;

	return 0;
}