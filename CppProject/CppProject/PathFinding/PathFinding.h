#pragma once
#include "../DataStructures/Graph.h"

class PathFinding
{
public:
    static void GetShortestPath(Graph* graph, int startNode, int goalNode);
};
