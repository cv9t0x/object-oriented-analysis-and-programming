#include "Graph.h"
#include <iostream>
#include <set>

typedef set<Node*>::const_iterator node_iterator;

Graph::Graph()
{
}

Graph::~Graph()
{
	nodes.clear();
}

void Graph::addNode(Node* node)
{
	if (nodes.find(node) == nodes.end())
	{
		nodes.insert(node);
		return;
	}

	cout << "Node already exists" << endl;
}

void Graph::removeNode(Node* node)
{
	if (nodes.find(node) != nodes.end())
	{
		nodes.erase(node);

		for (node_iterator it = nodes.begin(); it != nodes.end(); it++)
		{
			(*it)->removeNeighbour(node);
		}

		return;
	}

	cout << "Node doesn't exist" << endl;
}

void Graph::addEdge(Node* begin, Node* end)
{
	if (nodes.find(begin) == nodes.end() || nodes.find(end) == nodes.end())
	{
		return;
	}

	begin->addNeighbour(end);
	end->addNeighbour(begin);
}

void Graph::removeEdge(Node* begin, Node* end)
{
	if (nodes.find(begin) != nodes.end() || nodes.find(end) != nodes.end())
	{
		return;
	}

	this->removeNode(begin);
	this->removeNode(end);
}

node_iterator Graph::begin()
{
	return nodes.begin();
}

node_iterator Graph::end()
{
	return nodes.end();
}