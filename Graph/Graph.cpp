#include <iostream>
#include <vector>
#include <istream>
#include "Graph.h"

using namespace std;

typedef vector<Node*>::const_iterator node_iterator;
typedef vector<Edge*>::const_iterator edge_iterator;

Graph::Graph()
{
}

Graph::~Graph()
{
	nodes.clear();
	edges.clear();
}

node_iterator Graph::nd_begin() const
{
    return nodes.begin();
}

node_iterator Graph::nd_end() const
{
    return nodes.end();
}

edge_iterator Graph::eg_begin() const
{
    return edges.begin();
}

edge_iterator Graph::eg_end() const
{
    return edges.end();
}

void Graph::addNode(Node* newNode, bool flag)
{
    for (Node* node : nodes)
    {
        if (node == newNode)
        {
            if (!flag)
                cout << "Node already exists" << endl;
            return;
        } 
    }

    nodes.push_back(newNode);
}

void Graph::removeNode(Node* node)
{
    for (node_iterator it = nd_begin(); it != nd_end(); it++)
    {
        if ((*it) == node)
        {
            for (Node* neighbour : (*it)->neighbours)
            {
                removeEdge(node, neighbour);
                neighbour->removeNeighbour(*it);
            }

            nodes.erase(it);

            return;
        }
    }

    cout << "Node doesn't exist" << endl;
}

bool Graph::hasNode(Node* node)
{
    for (Node* n : nodes)
    {
        if (n == node)
            return true;
    }

    return false;
}

void Graph::addEdge(Node* begin, Node* end, int weight)
{
    for (Edge* edge : edges)
    {
        if (edge->begin == begin && edge->end == end
            || edge->begin == end && edge->end == begin)
        {
            return;
        }
    }

    edges.push_back(new Edge(begin, end, weight));

    addNode(begin, true);
    addNode(end, true);

    begin->addNeighbour(end);
    end->addNeighbour(begin);
}

void Graph::addEdge(Edge* newEdge, int weight)
{
    addEdge(newEdge->begin, newEdge->end, weight);
}

void Graph::addEdge(string begin, string end, int weight)
{
    Node* beginNode = nullptr;
    Node* endNode = nullptr;

    for (Node* node : nodes)
    {
        if (node->name == begin)
            beginNode = node;
        
        if (node->name == end)
            endNode = node;

        if (beginNode != nullptr && endNode != nullptr)
            break;
    }

    if (beginNode != nullptr && endNode != nullptr)
        addEdge(beginNode, endNode);
    else if (beginNode == nullptr && endNode != nullptr)
        addEdge(new Node(begin), endNode);
    else if (beginNode != nullptr && endNode == nullptr)
        addEdge(beginNode, new Node(end));
    else
        addEdge(new Node(begin), new Node(end));
}

void Graph::removeEdge(Node* begin, Node* end)
{
    for (edge_iterator it = eg_begin(); it != eg_end(); it++)
    {
        if ((*it)->getBegin() == begin && (*it)->getEnd() == end || 
            (*it)->getEnd() == begin && (*it)->getBegin() == end)
        {
            edges.erase((it));
            return;
        }
    }

    cout << "Edge doesn't exist" << endl;
}

vector<Node*> Graph::getNodes()
{
    return nodes;
}

vector<Edge*> Graph::getEdges()
{
    return edges;
}

ostream& operator<<(ostream& out, const Graph& graph)
{
    out << "NODES:" << endl;
    for (size_t i = 0; i < graph.nodes.size(); i++)
    {
        if (i == graph.nodes.size() - 1)
            out << graph.nodes[i]->getName() << endl;
        else
            out << graph.nodes[i]->getName() << ", ";
    }

    out << "EDGES:" << endl;
    for (Edge* edge : graph.edges)
    {
        out << edge->getBegin()->getName() << " -" << edge->getWeight() << "- " << edge->getEnd()->getName() << endl;
    }

    return out;
}

/*





void Graph::operator=(const Graph& other)
{
    this->nodes.clear();
    this->edges.clear();

    for (node_iterator it = other.nodes.begin(); it != other.nodes.end(); it++)
    {
        this->nodes.push_back((*it));
    }

    for (edge_iterator it = other.edges.begin(); it != other.edges.end(); it++)
    {
        this->edges.push_back((*it));
    }
}

*/
