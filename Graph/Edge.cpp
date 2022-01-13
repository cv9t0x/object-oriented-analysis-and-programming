#include "Edge.h"
#include "Graph.h"

Edge::Edge(Node* begin, Node* end, const int weight)
{
	this->begin = begin;
	this->end = end;
	this->weight = weight;
}

Edge::~Edge()
{
}

int Edge::getWeight()
{
	return weight;
}

Node* Edge::getBegin()
{
	return begin;
}

Node* Edge::getEnd()
{
	return end;
}