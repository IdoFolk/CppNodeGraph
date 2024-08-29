#pragma once
#include <vector>
#include "Node.h"

class Graph
{
public:
    std::vector<Node> nodes;
    void AddNode(int id);
    void AddEdge(int sourceId, int destinationId, int weight);
    void PrintGraph();
    Node* FindNode(int id);
};
