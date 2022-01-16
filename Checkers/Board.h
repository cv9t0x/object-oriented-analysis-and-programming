#ifndef BOARD_H
#define BOARD_H

#include <map>
#include <tuple>
#include "Checker.h"

using namespace std;

struct Cell {
	string pos;
	int x, y;

	Cell(string pos, int x, int y) { this->pos = pos; this->x = x; this->y = y; };
	~Cell() {};
};

class BoardException
{
};

class Board
{
private:
	map<Cell*, Checker*> checkers;

	void readFile(string path);

	tuple<int, int, bool> convertPos(string str);
	int convertSym(char sym);

public:
	Board(string path);
	~Board();

	friend ostream& operator<<(ostream& out, Board& board);
};

#endif // !BOARD_H

