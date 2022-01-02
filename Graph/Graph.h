#ifndef GRAPH_H
#define GRAPH_H

#include <istream>
#include <set>
#include "Node.h"
#include "Edge.h"

typedef set<Node*>::const_iterator node_iterator;

class Graph
{
private:
	set<Node*> nodes;
	set<Edge*> edges;

public:
	Graph();
	~Graph();

<<<<<<< HEAD
	node_iterator begin();
	node_iterator end();
=======
	node_iterator begin() const;
	node_iterator end() const;

	set<Node*> getNodes();
	set<Edge*> getEdges();
>>>>>>> eeedb0b4710fb8226d58518ef8f6becc0d051023

	void addNode(Node* node);
	void removeNode(Node* node);
	void addEdge(Node* begin, Node* end, int weight);
	void removeEdge(Node* begin, Node* end);

<<<<<<< HEAD
};
=======
	void operator=(const Graph& other);
>>>>>>> eeedb0b4710fb8226d58518ef8f6becc0d051023

	friend ostream& operator<<(ostream& out, const Graph& graph);
};

#endif // !GRAPH_H