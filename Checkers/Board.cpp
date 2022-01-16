#include <iostream>
#include <fstream>
#include <utility>
#include "Board.h"

Board::Board(string path)
{
	readFile(path);
}

Board::~Board()
{
	checkers.clear();
}

void Board::readFile(string path)
{
	ifstream in;
	in.open(path);

	if (in.is_open())
	{
		string s;
		int nWhite = 0;
		int nBlack = 0;
		
		while (getline(in, s))
		{
			if (s == "" || s == "\n")
				continue;

			if (s.substr(0, s.find(' ')) == "White:")
			{
				nWhite = stoi(s.substr(s.find(' ')));
				continue;
			}

			if (s.substr(0, s.find(' ')) == "Black:")
			{
				nBlack = stoi(s.substr(s.find(' ')));
				continue;
			}

			int x, y;
			bool isCrown, isWhite;

			if (nWhite)
			{
				isWhite = true;
				tie(x, y, isCrown) = convertPos(s);

				checkers.insert({ new Cell(s, x, y), new Checker(isWhite, isCrown) });

				nWhite--;

				continue;
			}
			else if (nBlack)
			{
				isWhite = false;
				tie(x, y, isCrown) = convertPos(s);

				checkers.insert({ new Cell(s, x, y), new Checker(isWhite, isCrown) });

				nBlack--;

				continue;
			}
			else 
			{
				break;
			}
		}
	}
	else 
	{
		throw new BoardException();
	}
}

tuple<int, int, bool> Board::convertPos(string str)
{
	if (!(str.length() == 2 || str.length() == 3))
		throw new BoardException();

	int x, y;
	bool isCrown = false;

	if (str.length() == 3)
	{
		isCrown = convertSym(str[0]) == -1;
		x = convertSym(str[1]);
		y = convertSym(str[2]);
	}
	else
	{
		x = convertSym(str[0]);
		y = convertSym(str[1]);
	}

	return make_tuple(x, y, isCrown);
}

int Board::convertSym(char sym)
{
	int code = (int)sym;

	if (code > 48 && code < 57)
	{
		return code - 49;
	}
	else if (code > 64 && code < 73)
	{
		return code - 65;
	}
	else if (code == 77)
	{
		return -1;
	}
	else
	{
		throw new BoardException();
	}
}

ostream& operator<<(ostream& out, Board& board)
{
	for (auto item : board.checkers)
	{
		out << item.first->pos << " " << *item.second;
	}

	return out;
}