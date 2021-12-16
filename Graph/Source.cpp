#include <iostream>
#include "Graph.h"
#include "Node.h"

using namespace std;

int main()
{
	Node node1("node1");
	Node node2("node2");

	Graph graph;

	graph.addNode(&node1);
	graph.addNode(&node2);

	return 0;
}