#include "Node.h"
#include <istream>
#include <string>
#include <set>

using namespace std;

typedef set<Node*>::const_iterator node_iterator;

Node::Node(string name)
{
	this->name = name;
}

Node::~Node()
{
	neighbours.clear();
}

node_iterator Node::nb_begin() const
{
	return neighbours.begin();
}

node_iterator Node::nb_end() const
{
	return neighbours.end();
}

const string& Node::getName()
{
	return name;
}

const set<Node*> Node::getNeighbours()
{
	return neighbours;
}

void Node::addNeighbour(Node* neighbour)
{
	if (neighbours.find(neighbour) == neighbours.end())
	{
		neighbours.insert(neighbour);
		return;
	}
}

void Node::removeNeighbour(Node* neighbour)
{
	if (neighbours.find(neighbour) != neighbours.end())
	{
		neighbours.erase(neighbour);
		return;
	}
}

ostream& operator<<(ostream& out, const Node& node)
{
	for (node_iterator it = node.nb_begin(); it != node.nb_end(); it++)
	{
		out << (*it)->getName() << " ";
	}
	out << endl;

	return out;
}