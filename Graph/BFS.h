#ifndef BFS_H
#define BFS_H

#include "Graph.h"
#include "Node.h"

class BFS
{
private:
	const Graph* graph;

public:
	BFS(const Graph& graph);
	
	bool connected(Node* begin, Node* end);
};

#endif // !BFS_H
