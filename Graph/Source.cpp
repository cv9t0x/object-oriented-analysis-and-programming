#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Graph.h"
#include "Node.h"
#include "BFS.h"
#include "DFS.h"

using namespace std;

typedef vector<Graph*>::const_iterator graph_iterator;
typedef set<Node*>::const_iterator node_iterator;

int main()
{
	Graph graph;
	Node* node1 = new Node("1");
	Node* node2 = new Node("2");
	Node* node3 = new Node("3");

	graph.addEdge(node1, node2);
	graph.addEdge(node1, node2);
	graph.removeEdge(node1, node2);
	graph.removeEdge(node1, node2);
	graph.addEdge(node1, node2);
	graph.addEdge(node1, node3);

	cout << graph;

	return 0;
}