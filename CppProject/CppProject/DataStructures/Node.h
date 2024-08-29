#pragma once
#include <vector>
#include "Edge.h"

class Node
{
public:
    int id;
    std::vector<Edge> edges;
    int distance;
    Node* previous;

    Node(int id) : id(id)
    {
    }
};
