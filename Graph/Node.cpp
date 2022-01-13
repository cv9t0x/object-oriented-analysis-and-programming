#include <istream>
#include <string>
#include <vector>
#include "Node.h"

using namespace std;

typedef vector<Node*>::const_iterator node_iterator;

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

const vector<Node*> Node::getNeighbours()
{
	return neighbours;
}

void Node::addNeighbour(Node* node)
{
	for(Node * neighbour : neighbours)
	{
		if (neighbour == node)
			return;
	}

	neighbours.push_back(node);
}

void Node::removeNeighbour(Node* node)
{
	for (node_iterator it = nb_begin(); it != nb_end(); it++)
	{
		if ((*it) == node)
		{
			neighbours.erase(it);
			return;
		}
	}
}

ostream& operator<<(ostream& out, const Node& node)
{
	out << "--------------\n";
	out << "Name: " << node.name << endl;
	out << "Neighbours: ";

	for (Node* neighbour : node.neighbours)
	{
		out << neighbour->getName() << " ";
	}

	out << endl;
	out << "--------------\n";

	return out;
}