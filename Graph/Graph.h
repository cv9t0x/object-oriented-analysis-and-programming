#ifndef GRAPH_H
#define GRAPH_H

#include <set>
#include "Node.h"

using namespace std;

class Graph
{
private:
	set<Node*> nodes;

public:
	typedef set<Node*>::const_iterator node_iterator;

	Graph();
	~Graph();

	void addNode(Node* node);
	void removeNode(Node* node);
	void addEdge(Node* begin, Node* end);
	void removeEdge(Node* begin, Node* end);

	node_iterator begin();
	node_iterator end();
};

#endif // !GRAPH_H

