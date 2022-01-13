#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Graph.h"
#include "Node.h"
#include "BFS.h"
#include "DFS.h"

using namespace std;

int main()
{
	string path = "TestGraphBig.txt";

	ifstream file;

	file.open(path);

	if (file.is_open())
	{
		string buf;
		getline(file, buf);

		Graph mainGraph;

		while (!file.fail())
		{
			string source, target;

			file >> source >> target;

			if (source == "" && target == "")
				continue;

			mainGraph.addEdge(source, target);
		}

		file.close();

		vector<Graph*> graphs;
		BFS bfs(mainGraph);
		
		for (size_t i = 0; i < mainGraph.getNodes().size() - 1; i++)
		{
			Node* begin = mainGraph.getNodes()[i];

			for (size_t j = i + 1; j < mainGraph.getNodes().size(); j++)
			{
				Node* end = mainGraph.getNodes()[j];

				if (bfs.connected(begin, end))
				{
					bool isFind = false;

					for (Graph* graph : graphs)
					{
						if(graph->hasNode(begin) || graph->hasNode(end))
						{
							graph->addEdge(begin, end);

							isFind = true;

							break;
						}
					}

					if (!isFind)
					{
						Graph* graph = new Graph;

						graph->addEdge(begin, end);
						graphs.push_back(graph);
					}
				}
			}
		}

		for (size_t i = 0; i < graphs.size(); i++)
		{
			string path = "Graph" + to_string(i + 1) + ".dat";
			ofstream fout(path);

			if (fout.is_open())
			{
				fout << *graphs[i];
				cout << "Graph " << i + 1 << " was successful written" << endl;
			}
			else
			{
				cout << "Open file error" << endl;
			}
		}
	}
	else
	{
		cout << "Open file error" << endl;
	}

	return 0;
}