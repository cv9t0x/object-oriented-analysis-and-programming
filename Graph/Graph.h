#ifndef GRAPH_H
#define GRAPH_H

#include <set>
#include "Node.h"
#include "Edge.h"

using namespace std;

class Graph
{
private:
	set<Node*> nodes;
	set<Edge*> edges;

public:
	typedef set<Node*>::const_iterator node_iterator;

	Graph();
	~Graph();

	node_iterator begin();
	node_iterator end();

	void addNode(Node* node);
	void removeNode(Node* node);
	void addEdge(Node* begin, Node* end, int weight);
	void removeEdge(Node* begin, Node* end);

};

#endif // !GRAPH_H

