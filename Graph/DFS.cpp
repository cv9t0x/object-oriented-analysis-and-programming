#include "DFS.h"

typedef set<Node*>::const_iterator node_iterator;

DFS::DFS(const Graph& graph)
{
	this->graph = &graph;
}

bool DFS::connected(Node* begin, Node* end)
{
	visited.clear();

	return connected(begin, end, 0);
}

bool DFS::connected(Node* begin, Node* end, int depth)
{
	if (begin == end)
	{
		return true;
	}

	visited.insert(begin);

	for (node_iterator it = begin->nb_begin(); it != begin->nb_end(); it++)
	{
		if (visited.find(*it) == visited.end())
		{
			if (connected(*it, end, depth + 1)) return true;
		}
	}

	return false;
}