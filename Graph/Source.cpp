#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Graph.h"
#include "Node.h"
#include "BFS.h"
#include "DFS.h"

using namespace std;

typedef vector<Node*>::const_iterator node_iterator;

bool inVector(vector<Node*> nodes, Node* node)
{
	for (Node* n : nodes)
	{
		if (node == n)
			return true;
	}
	return false;
}

void setGraph(vector<Node*>& visited, Graph& graph, Node* current)
{	
	visited.push_back(current);

	for (Node* neighbour : current->getNeighbours())
	{
		graph.addEdge(current, neighbour);


		if (inVector(visited, neighbour))
			continue;

		setGraph(visited, graph, neighbour);
	}
}

vector<Graph*> getGraphs(Graph* mainGraph)
{
	vector<Graph*> graphs;
	vector<Node*> visited;
	node_iterator beginIt = mainGraph->nd_begin();

	while (visited.size() != mainGraph->getNodes().size())
	{
		Graph* graph = new Graph;
		Node* begin = nullptr;

		if (visited.size() == 0)
		{
			begin = *mainGraph->nd_begin();
		}
		else
		{
			for (node_iterator it = beginIt; it != mainGraph->nd_end(); it++)
			{
				if (!inVector(visited, *it))
				{
					beginIt = it;
					begin = *it;
					break;
				}
			}
		}

		setGraph(visited, *graph, begin);

		graphs.push_back(graph);
	}

	return graphs;
}

void writeGraphs(vector<Graph*> graphs)
{
	for (size_t i = 0; i < graphs.size(); i++)
	{
		string path = "Graph" + to_string(i + 1) + ".dat";
		ofstream fout(path);

		if (fout.is_open())
		{
			fout << *graphs[i];
			fout.close();
			cout << "Graph " << i + 1 << " was successful written" << endl;
		}
		else
		{
			cout << "Open file error" << endl;
		}
	}
}

int main()
{
	string path = "TestGraphSmall.txt";

	ifstream file;

	file.open(path);

	if (file.is_open())
	{
		string buf;
		getline(file, buf);

		Graph* mainGraph = new Graph;

		while (!file.fail())
		{
			string source, target;

			file >> source >> target;

			if (source == "" && target == "")
				continue;

			mainGraph->addEdge(source, target);
		}

		file.close();

		vector<Graph*> graphs = getGraphs(mainGraph);
		writeGraphs(graphs);
	}
	else
	{
		cout << "Open file error" << endl;
	}
		
	return 0;
}