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
	/*Graph graph;
	Node* node1 = new Node("1");
	Node* node2 = new Node("2");
	Node* node3 = new Node("3");

	graph.addEdge(node1, node2);
	graph.addEdge(node1, node2);
	graph.removeEdge(node1, node2);
	graph.removeEdge(node1, node2);
	graph.addEdge(node1, node2);

	cout << graph;*/
	string path = "TestGraph.txt";
	ifstream file;

	file.open(path.c_str());

	if (file.is_open())
	{
		string buf;
		getline(file, buf);

		Graph graph;

		while (!file.fail())
		{
			string source, target;
			file >> source >> target;

			if (source == "" || target == "")
				continue;

			Node* begin = new Node(source);
			Node* end = new Node(target);

			graph.addEdge(begin, end);
		}

		cout << graph;

		vector<Graph*> graphs;
		bool start = true;

		Graph* firstGraph = new Graph;
		(*firstGraph).addEdge(*(graph.getEdges().begin()));
		graphs.push_back(firstGraph);

		for (node_iterator nt = (*firstGraph).begin(); nt != (*firstGraph).end(); nt++)
		{
			cout << (**nt);
		}


		//cout << (*firstGraph);


		/*int count = 0;

		for (graph_iterator it = graphs.begin(); it != graphs.end(); it++)
		{
			cout << "-----------------------\n";
			cout << "Graph" << " " << ++count << endl;
			cout << "-----------------------\n";
			cout << (**it);
			cout << "-----------------------\n\n";
		}*/
	}

	file.close();

	return 0;
}