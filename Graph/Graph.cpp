#include <iostream>
#include <set>
#include "Graph.h"

typedef set<Node*>::const_iterator node_iterator;

Graph::Graph()
{
}

Graph::~Graph()
{
	nodes.clear();
	edges.clear();
}


node_iterator Graph::begin()
{
	return nodes.begin();
}

node_iterator Graph::end()
{
	return nodes.end();
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

void Graph::addEdge(Node* begin, Node* end, int weight)
{
	if (nodes.find(begin) == nodes.end())
	{
		cout << "Begin node doesn't exist" << endl;
		return;
	}

	if (nodes.find(end) == nodes.end())
	{
		cout << "End node doesn't exist" << endl;
		return;
	}

	Edge* edge = new Edge(begin, end, weight);

	if (edges.find(edge) != edges.end())
	{
		cout << "Edge already exists" << endl;
	}

	edges.insert(edge);
	begin->addNeighbour(end);
	end->addNeighbour(begin);
}

void Graph::removeEdge(Node* begin, Node* end)
{
	if (nodes.find(begin) == nodes.end())
	{
		cout << "Begin node doesn't exist" << endl;
		return;
	}

	if (nodes.find(end) == nodes.end())
	{
		cout << "End node doesn't exist" << endl;
		return;
	}

	this->removeNode(begin);
	this->removeNode(end);
}
