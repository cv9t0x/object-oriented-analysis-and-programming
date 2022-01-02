#include <iostream>
#include "Graph.h"
#include "Node.h"
<<<<<<< HEAD
=======
#include "BFS.h"
#include "DFS.h"
>>>>>>> eeedb0b4710fb8226d58518ef8f6becc0d051023

using namespace std;

int main()
{
<<<<<<< HEAD
	Node node1("node1");
	Node node2("node2");

	Graph graph;

	graph.addNode(&node1);
	graph.addNode(&node2);
=======
	Graph graph;
	Node node1("node1");
	Node node2("node2");
	Node node3("node3");

	graph.addNode(&node1);
	graph.addNode(&node2);
	graph.addNode(&node3);

	graph.addEdge(&node1, &node3, 50);

	cout << graph;

	BFS bfs(graph);
	DFS dfs(graph);

	cout << "BFS: " << bfs.connected(&node1, &node2) << endl;
	cout << "DFS: " << dfs.connected(&node1, &node2) << endl;
>>>>>>> eeedb0b4710fb8226d58518ef8f6becc0d051023

	return 0;
}