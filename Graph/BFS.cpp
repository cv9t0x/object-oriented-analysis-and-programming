#include <queue>
#include <set>
#include "BFS.h"

using namespace std;

typedef vector<Node*>::const_iterator node_iterator;

BFS::BFS(const Graph& graph)
{
	this->graph = &graph;
}

bool BFS::connected(Node* begin, Node* end)
{
	queue<Node*> nodes;
	set<Node*> visited;
	nodes.push(begin);

	while (!nodes.empty())
	{
		Node* next = nodes.front();
		nodes.pop();

		if (end == next)
		{
			return true;
		}

		visited.insert(next);

		for (node_iterator it = next->nb_begin(); it != next->nb_end(); it++)
		{
			if (visited.find(*it) == visited.end())
			{
				nodes.push(*it);
			}
		}
	}

	return false;
}