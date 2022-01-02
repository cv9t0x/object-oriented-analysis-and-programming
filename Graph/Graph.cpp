#include <iostream>
#include <set>
<<<<<<< HEAD
#include "Graph.h"
=======
#include <istream>
#include "Graph.h"

using namespace std;
>>>>>>> eeedb0b4710fb8226d58518ef8f6becc0d051023

typedef set<Node*>::const_iterator node_iterator;
typedef set<Edge*>::const_iterator edge_iterator;

Graph::Graph()
{
}

Graph::~Graph()
{
<<<<<<< HEAD
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
=======
    nodes.clear();
    edges.clear();
}


node_iterator Graph::begin() const
{
    return nodes.begin();
}

node_iterator Graph::end() const
{
    return nodes.end();
}

set<Node*> Graph::getNodes()
{
    return nodes;
}

set<Edge*> Graph::getEdges()
{
    return edges;
>>>>>>> eeedb0b4710fb8226d58518ef8f6becc0d051023
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
<<<<<<< HEAD
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
=======
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

    for (edge_iterator it = edges.begin(); it != edges.end(); it++)
    {
        if ((*it)->getBegin() == begin && (*it)->getEnd() == end
            || (*it)->getBegin() == end && (*it)->getEnd() == begin)
        {
            cout << "Edge already exists" << endl;
            return;
        }
    }

    Edge* edge = new Edge(begin, end, weight);
    edges.insert(edge);

    begin->addNeighbour(end);
    end->addNeighbour(begin);
>>>>>>> eeedb0b4710fb8226d58518ef8f6becc0d051023
}

void Graph::removeEdge(Node* begin, Node* end)
{
<<<<<<< HEAD
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
=======
    if (nodes.find(begin) == this->end())
    {
        cout << "Begin node doesn't exist" << endl;
        return;
    }
>>>>>>> eeedb0b4710fb8226d58518ef8f6becc0d051023

    if (nodes.find(end) == this->end())
    {
        cout << "End node doesn't exist" << endl;
        return;
    }

    for (edge_iterator it = edges.begin(); it != edges.end(); it++)
    {
        if ((*it)->getBegin() == begin && (*it)->getEnd() == end)
        {
            begin->removeNeighbour(end);
            end->removeNeighbour(begin);
            edges.erase((*it));
            return;
        }
    }

    cout << "Edge doesn't exist" << endl;
}
<<<<<<< HEAD
=======

void Graph::operator=(const Graph& other)
{
    this->nodes.clear();
    this->edges.clear();

    for (node_iterator it = other.nodes.begin(); it != other.nodes.end(); it++)
    {
        this->nodes.insert((*it));
    }

    for (edge_iterator it = other.edges.begin(); it != other.edges.end(); it++)
    {
        this->edges.insert((*it));
    }
}

ostream& operator<<(ostream& out, const Graph& graph)
{
    out << "---------------------" << endl;
    out << "NODES:" << endl;
    for (node_iterator it = graph.nodes.begin(); it != graph.nodes.end(); it++)
    {
        out << (*it)->getName() << " ";
    }
    out << "\n\nEDGES:" << endl;

    for (edge_iterator it = graph.edges.begin(); it != graph.edges.end(); it++)
    {
        out << (*it)->getBegin()->getName() << "\t- " << (*it)->getWeight() << " -\t" << (*it)->getEnd()->getName();
        out << endl;
    }
    out << "---------------------" << endl;

    return out;
}
>>>>>>> eeedb0b4710fb8226d58518ef8f6becc0d051023
