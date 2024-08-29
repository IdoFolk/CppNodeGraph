#include "Graph.h"

#include <iostream>

void Graph::AddEdge(int sourceId, int destinationId, int weight)
{
    Node* sourceNode = FindNode(sourceId);
    Node* destinationNode = FindNode(destinationId);

    Edge edge(sourceNode, destinationNode, weight);
    sourceNode->edges.push_back(edge);
}

void Graph::AddNode(int id)
{
    Node node(id);
    nodes.push_back(node);
}

Node* Graph::FindNode(int id)
{
    for (Node& node : nodes)
    {
        if (node.id == id)
        {
            return &node;
        }
    }

    return nullptr;
}

void Graph::PrintGraph()
{
    for (Node& node : nodes)
    {
        for (Edge edge : node.edges)
        {
            std::cout << "Node " << '[' << node.id << ']' << " -" << edge.weight << "-> " << '[' << edge.destination->id
                << ']' << '\n';
        }

        std::cout << "\n";
    }
}
