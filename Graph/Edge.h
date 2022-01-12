#ifndef EDGE_H
#define EDGE_H

#include <istream>
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

	friend class Graph;
};

#endif // !EDGE_H