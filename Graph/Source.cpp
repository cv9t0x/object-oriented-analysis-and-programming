#include <iostream>
#include "Graph.h"
#include "Node.h"

using namespace std;

int main()
{
	Graph graph;
	Node node1("node1");
	Node node2("node2");
	Node node3("node3");

	graph.addNode(&node1);
	graph.addNode(&node2);
	graph.addNode(&node3);

	graph.addEdge(&node1, &node2, 5);
	graph.addEdge(&node1, &node3, 10);
	graph.addEdge(&node3, &node2, 20);
	graph.addEdge(&node2, &node3, 20);

	cout << graph;

	return 0;
}