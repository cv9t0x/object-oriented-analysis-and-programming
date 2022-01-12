#ifndef GRAPH_H
#define GRAPH_H

#include <istream>
#include <string>
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

	node_iterator begin() const;
	node_iterator end() const;

	set<Node*> getNodes();
	set<Edge*> getEdges();

	void addNode(Node* node);
	void removeNode(Node* node);

	void addEdge(Edge* edge, int weight = 0);
	void addEdge(Node* begin, Node* end, int weight = 0);
	void removeEdge(Node* begin, Node* end);
	bool hasNode(Node* node);
	//bool hasNodeByName(string name);
	//Node* getNodeByName(string name);

	void operator=(const Graph& other);

	friend ostream& operator<<(ostream& out, const Graph& graph);
};

#endif // !GRAPH_H