#include "PathFinding.h"

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;


void PathFinding::GetShortestPath(Graph* graph, int startNode, int goalNode)
{
    // If one of the nodes is not in the graph.
    if(graph->FindNode(startNode) == nullptr || graph->FindNode(goalNode) == nullptr)
    {
        cout << "One of the nodes is not in the graph." << endl;
        return;
    }
        
    // Create a priority queue to store the nodes to be visited.
    priority_queue<Node*, vector<Node*>, greater<>> minHeap;

    // Create an unordered map to keep track of visited nodes.
    unordered_map<int, Node*> visited;

    // Add the start node to the priority queue and mark it as visited.
    Node* start = graph->FindNode(startNode);
    minHeap.push(start);
    visited[startNode] = start;

    while (!minHeap.empty())
    {
        // Get the node with the minimum distance from the start node.
        Node* current = minHeap.top();
        minHeap.pop();

        // If the current node is the goal node, we have found the shortest path
        if (current->id == goalNode)
        {
            break;
        }

        // Visit all the neighbors of the current node.
        for (const auto& edge : current->edges)
        {
            int neighborId = edge.destination->id;
            int weight = edge.weight;

            if (visited.find(neighborId) == visited.end()) // If the neighbor node has not been visited before.
            {
                Node* neighborNode = graph->FindNode(neighborId);
                minHeap.push(neighborNode);
                visited[neighborId] = neighborNode;
                visited[neighborId]->distance = current->distance + weight;
                visited[neighborId]->previous = current;
            }
            else if (visited[neighborId]->distance > current->distance + weight) // If the neighbor node has already been visited.
            {
                visited[neighborId]->distance = current->distance + weight;
                visited[neighborId]->previous = current;
            }
        }
    }

    vector<int> path;

    // Follow the previous nodes from the goal node to the start node.
    Node* current = visited[goalNode];
    while (current != nullptr)
    {
        path.push_back(current->id);
        current = current->previous;
    }

    // Reverse the order of the nodes in the path.
    reverse(path.begin(), path.end());


    // Print the path.
    std::cout << "Shortest Path: ";
    for (const int& nodeId : path)
    {
        cout << '[' << nodeId << "]";
        if (nodeId != goalNode) cout << " -> ";
    }
    cout << '\n';
    cout << "Cost: " << visited[goalNode]->distance;
    cout << endl;
}
