#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
#include <istream>

using namespace std;

class Node
{
private:
	string name;
	vector<Node*> neighbours;

	void addNeighbour(Node* node);
	void removeNeighbour(Node* node);

public:
	typedef vector<Node*>::const_iterator node_iterator;

	Node(const string name);
	~Node();

	node_iterator nb_begin() const;
	node_iterator nb_end() const;
	
	const string& getName();
	const vector<Node*> getNeighbours();

	friend class Graph;
	friend ostream& operator <<(ostream& out, const Node& node);
};

#endif // !NODE_H

