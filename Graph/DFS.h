#ifndef DFS_H
#define DFS_H

#include <set>
#include "Graph.h"
#include "Node.h"

class DFS
{
private:
	const Graph* graph;
	set<Node*> visited;
	bool connected(Node* begin, Node* end, int depth);

public:
	DFS(const Graph& graph);

	bool connected(Node* begin, Node* end);
};

#endif // !DFS_H
