#ifndef NODE_H
#define NODE_H

#include <string>
#include <set>

using namespace std;

class Node
{
private:
	string name;
	set<Node*> neighbours;

	void addNeighbour(Node* neighbour);
	void removeNeighbour(Node* neighbour);

public:
	typedef set<Node*>::const_iterator node_iterator;

	Node(const string name);
	~Node();

	node_iterator nb_begin() const;
	node_iterator nb_end() const;
	
	const string& getName();
	const set<Node*> getNeighbours();

	friend class Graph;
};

#endif // !NODE_H

