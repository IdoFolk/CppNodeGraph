#pragma once

class Node;

class Edge
{
public:
    Node* source;
    Node* destination;
    int weight;

    Edge(Node* source, Node* destination, int weight)
        : source(source), destination(destination), weight(weight)
    {
    }
};
