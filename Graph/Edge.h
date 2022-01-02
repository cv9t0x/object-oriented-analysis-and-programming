#ifndef EDGE_H
#define EDGE_H

<<<<<<< HEAD
=======
#include <istream>
>>>>>>> eeedb0b4710fb8226d58518ef8f6becc0d051023
#include "Node.h"

class Edge
{
private:
	Node* begin;
	Node* end;
	int weight;

public:
	Edge(Node* begin, Node* end, const int weight);
	~Edge();

	int getWeight();
	Node* getBegin();
	Node* getEnd();
<<<<<<< HEAD
};

#endif // !EDGE_H
=======

	friend class Graph;
};

#endif // !EDGE_H
>>>>>>> eeedb0b4710fb8226d58518ef8f6becc0d051023
