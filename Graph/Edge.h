#ifndef EDGE_H
#define EDGE_H

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
};

#endif // !EDGE_H
