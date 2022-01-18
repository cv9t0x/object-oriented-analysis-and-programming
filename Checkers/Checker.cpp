#include "Checker.h"
#include <iostream>

Checker::Checker(int x, int y, bool isWhite, bool isCrown)
{
	pos.x = x;
	pos.y = y;
	this->isWhite = isWhite;
	this->isCrown = isCrown;
}

Checker::~Checker()
{
}

vector<Move>* Checker::getMovesChecker(Board& board)
{
	vector<Move>* moves = new vector<Move>();
	Move move{};
	move.src = pos;
	move.dst = pos;
	bool attack = false;

	for (int x = pos.x - 1; x <= pos.x + 1; x += 2)
	{
		if (!inBoard(x)) continue;

		move.dst.x = x;

		for (int y = pos.y - 1; y <= pos.y + 1; y += 2)
		{
			if (!inBoard(x)) continue;

			move.dst.y = y;

			if (board.hasCell(move.dst))
			{
				if (board.getCell(move.dst)->isWhite != isWhite)
				{
					AttackDirection dir = getAttackDirection(pos, move.dst);

					if (isAttackable(move.dst, dir, board))
					{
						move.dst = *getAttackPos(move.dst, dir);

						if (!attack) moves->clear();

						moves->push_back(move);
						attack = true;
					}
				}

				continue;
			}

			if ((isWhite && move.dst.y < pos.y) || (!isWhite && move.dst.y > pos.y)) continue;
			if (!attack) moves->push_back(move);
		}
	}

	return moves;
}

vector<Move>* Checker::getMovesCrown(Board& board)
{
	vector<Move>* moves = new vector<Move>();
	Move move{};
	move.src = pos;
	move.dst = pos;
	bool attack = false;

	return moves;
}

vector<Move>* Checker::getMovesArray(Board& board)
{
	return isCrown ? getMovesCrown(board) : getMovesChecker(board);
}

bool Checker::inBoard(int coordinate)
{
	return coordinate < 0 || coordinate > 7 ? false : true;
}

bool Checker::isAttackable(Cell cell, AttackDirection dir, Board& board)
{
	if (dir == AttackDirection::LEFT_TOP)
	{
		cell.x--;
		cell.y++;
	}
	else if (dir == AttackDirection::LEFT_DOWN)
	{
		cell.x--;
		cell.y--;
	}
	else if (dir == AttackDirection::RIGHT_TOP)
	{
		cell.x++;
		cell.y++;
	}
	else if (dir == AttackDirection::RIGHT_DOWN)
	{
		cell.x++;
		cell.y--;
	}

	if (!inBoard(cell.x) || !inBoard(cell.y) || board.hasCell(cell)) return false;

	return true;
}

enum class AttackDirection Checker::getAttackDirection(Cell src, Cell dst)
{
	if (src.x > dst.x)
	{
		if(src.y > dst.y)
			return AttackDirection::LEFT_DOWN;
		else
			return AttackDirection::LEFT_TOP;
	}
	else {
		if (src.y > dst.y)
			return AttackDirection::RIGHT_DOWN;
		else
			return AttackDirection::RIGHT_TOP;
	}
}

Cell* Checker::getAttackPos(Cell cell, AttackDirection dir)
{
	Cell* tmp = &cell;

	if (dir == AttackDirection::LEFT_TOP)
	{
		tmp->x--;
		tmp->y++;
	}
	else if (dir == AttackDirection::LEFT_DOWN)
	{
		tmp->x--;
		tmp->y--;
	}
	else if (dir == AttackDirection::RIGHT_TOP)
	{
		tmp->x++;
		tmp->y++;
	}
	else if (dir == AttackDirection::RIGHT_DOWN)
	{
		tmp->x++;
		tmp->y--;
	}

	return tmp;
}

ostream& operator<<(ostream& out, Checker& checker)
{
	out << (checker.isWhite ? "white" : "black") << " " << (checker.isCrown ? "crown" : "") << endl;

	return out;
}