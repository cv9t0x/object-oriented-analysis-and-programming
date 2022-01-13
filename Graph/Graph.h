#ifndef GRAPH_H
#define GRAPH_H

#include <istream>
#include <string>
#include <vector>
#include "Node.h"
#include "Edge.h"

typedef vector<Node*>::const_iterator node_iterator;
typedef vector<Edge*>::const_iterator edge_iterator;

class Graph
{
private:
	vector<Node*> nodes;
	vector<Edge*> edges;

	

public:
	Graph();
	~Graph();

	node_iterator nd_begin() const;
	node_iterator nd_end() const;

	edge_iterator eg_begin() const;
	edge_iterator eg_end() const;

	void addNode(Node* newNode, bool flag = false);
	void removeNode(Node* node);
	bool hasNode(Node* node);

	void addEdge(Node* begin, Node* end, int weight = 0);
	void addEdge(Edge* newEdge, int weight = 0);
	void addEdge(string begin, string end, int weight = 0);
	void removeEdge(Node* begin, Node* end);
	
	vector<Node*> getNodes();
	vector<Edge*> getEdges();

	friend ostream& operator<<(ostream& out, const Graph& graph);
};

#endif // !GRAPH_H