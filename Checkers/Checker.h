#ifndef CHECKER_H
#define CHECKER_H

#include <string>
#include <istream>
#include <vector>
#include "Board.h"

using namespace std;

class Board;

struct Cell {
	int x, y;

	bool const operator==(const Cell& other) const
	{
		return x == other.x && y == other.y;
	}

	bool const operator<(const Cell& other) const
	{
		return x < other.x || (x == other.x && y < other.y);
	}
};

struct Move {
	Cell src, dst;
};

enum class AttackDirection {LEFT_TOP, LEFT_DOWN, RIGHT_TOP, RIGHT_DOWN};

class Checker
{
private:
	Cell pos;
	bool isWhite;
	bool isCrown;

	bool inBoard(int coordinate);
	bool isAttackable(Cell cell, AttackDirection dir, Board& board);
	enum class AttackDirection getAttackDirection(Cell src, Cell dst);
	Cell* getAttackPos(Cell cell, AttackDirection dir);

	vector<Move>* getMovesChecker(Board& board);
	vector<Move>* getMovesCrown(Board& board);

	friend class Board;
	
public:
	Checker(int x, int y, bool isWhite, bool isCrown);
	~Checker();
	
	vector<Move>* getMovesArray(Board& board);

	//bool const isWhite() const;
	
	friend ostream& operator<<(ostream& out, Checker& checker);
};


#endif // !CHECKER_H

