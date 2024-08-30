#include <iostream>
#include <random>

#include "DataStructures/Graph.h"
#include "Parsing/CSVParser.h"
#include "PathFinding/PathFinding.h"

using namespace std;

int main(int argc, char* argv[])
{
    const std::string filename = "CSV graph.csv";
    auto csvData = CSVParser::parseCSV(filename);
    Graph* graph = CSVParser::CreateGraphFromCSV(csvData);

    graph->PrintGraph();
    
    while (true)
    {
        int selectedStartNode = 0;
        int selectedEndNode = 0;
        cout << "Enter the starting node" << endl;
        cin >> selectedStartNode;
        cout << "Enter the ending node" << endl;
        cin >> selectedEndNode;
        cout << "Start Node: " << selectedStartNode << " End Node: " << selectedEndNode << "\n";
        PathFinding::GetShortestPath(graph, selectedStartNode, selectedEndNode);
        cout << "\n";
    }
    
    return 0;
}
