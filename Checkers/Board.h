#ifndef BOARD_H
#define BOARD_H

#include <fstream>
#include <string>
#include <map>
#include <tuple>
#include <vector>
#include "Checker.h"

using namespace std;

class Checker;
struct Cell;
struct Move;

class BoardException
{
};

class Board
{
private:
	map<Cell, Checker*> checkers;

	void readFile(string path);

	tuple<int, int, bool> convertPos(string str);
	int convertSym(char sym);

public:
	Board(string path);
	~Board();

	bool hasCell(Cell cell);
	Checker* getCell(Cell cell);
	vector<Move>* calcWhiteMoves();

	friend ostream& operator<<(ostream& out, Board& board);
};

#endif // !BOARD_H

