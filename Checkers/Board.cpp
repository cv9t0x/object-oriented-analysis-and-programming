#include "Board.h"

Board::Board(string path)
{
	readFile(path);
	vector<Move>* pResult = calcWhiteMoves();

	delete pResult;
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

				Checker* checker = new Checker(x, y, isWhite, isCrown);
				checkers.insert({ checker->pos , checker });

				nWhite--;

				continue;
			}

			if (nBlack)
			{
				isWhite = false;
				tie(x, y, isCrown) = convertPos(s);

				Checker* checker = new Checker(x, y, isWhite, isCrown);
				checkers.insert({ checker->pos , checker });

				nBlack--;

				continue;
			}

			break;

		}

		if (nWhite || nBlack)
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
		return code - 49;

	if (code > 64 && code < 73)
		return code - 65;

	if (code == 77)
		return -1;

	throw new BoardException();
}

bool Board::hasCell(Cell cell)
{
	return checkers.find(cell) != checkers.end() ? true : false;
}

Checker* Board::getCell(Cell cell)
{
	for (auto& item : checkers)
	{
		if (item.first == cell)
			return item.second;
	}

	return nullptr;
}

vector<Move>* Board::calcWhiteMoves()
{
	vector<Move>* moves = new vector<Move>();

	for (auto& item : checkers)
	{
		if (item.second->isWhite)
		{
			for (Move move : *(item.second->getMovesArray(*this)))
				moves->push_back(move);
		}
	}

	return moves;
}

ostream& operator<<(ostream& out, Board& board)
{
	for (auto& item : board.checkers)
		out << "X: " << item.first.x << " " << "Y: " <<item.first.y << " " << *item.second;

	return out;
}