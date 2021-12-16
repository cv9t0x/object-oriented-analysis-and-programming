#include <iostream>
#include <string>
#include <set>
#include "Node.h"

typedef set<Node*>::const_iterator node_iterator;

Node::Node(string name)
{
	this->name = name;
}

Node::~Node()
{
	neighbours.clear();
}

node_iterator Node::nb_begin()
{
	return neighbours.begin();
}

node_iterator Node::nb_end()
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

	cout << "Neighbour already exists" << endl;
}

void Node::removeNeighbour(Node* neighbour)
{
	if (neighbours.find(neighbour) != neighbours.end())
	{
		neighbours.erase(neighbour);
		return;
	}

	cout << "Neighbour doesn't exist" << endl;
}