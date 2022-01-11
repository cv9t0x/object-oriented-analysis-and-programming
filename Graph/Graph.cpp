#include <iostream>
#include <set>
#include <istream>
#include "Graph.h"

using namespace std;

typedef set<Node*>::const_iterator node_iterator;
typedef set<Edge*>::const_iterator edge_iterator;

Graph::Graph()
{
}

Graph::~Graph()
{
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
}

void Graph::addNode(Node* node)
{
    if (!hasNode(node))
    {
        nodes.insert(node);
        return;
    }
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
}

void Graph::addEdge(Edge* edge, int weight)
{
    if (edges.find(edge) != edges.end())
    {
        cout << "Edge already exist" << endl;
        return;
    }

    addEdge(edge->getBegin(), edge->getEnd(), weight);
}

void Graph::addEdge(Node* begin, Node* end, int weight)
{
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

    addNode(begin);
    addNode(end);

    begin->addNeighbour(end);
    end->addNeighbour(begin);
}

void Graph::removeEdge(Node* begin, Node* end)
{
    for (edge_iterator it = edges.begin(); it != edges.end(); it++)
    {
        if ((*it)->getBegin() == begin && (*it)->getEnd() == end)
        {
            begin->removeNeighbour(end);
            end->removeNeighbour(begin);

            removeNode(begin);
            removeNode(end);

            edges.erase((*it));
            return;
        }
    }

    cout << "Edge doesn't exist" << endl;
}

bool Graph::hasNode(Node* node)
{  
    for (node_iterator it = nodes.begin(); it != nodes.end(); it++)
    {
        if ((*it)->getName() == node->getName())
            return true;
    }

    if (nodes.find(node) != nodes.end())
        return true;

    return false;
}

/*bool Graph::hasNodeByName(string name)
{
    for (node_iterator it = nodes.begin(); it != nodes.end(); it++)
    {
        if ((*it)->getName() == name)
        {
            return true;
        }
    }
    return false;
}

Node* Graph::getNodeByName(string name)
{
    for (node_iterator it = nodes.begin(); it != nodes.end(); it++)
    {
        if ((*it)->getName() == name)
        {
            return *it;
        }
    }

    return nullptr;
}*/

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

    return out;
}