#include "CSVParser.h"
#include <random>

#include <fstream>
#include <sstream>

#include "../Random.h"

using namespace std;


vector<vector<string>> CSVParser::parseCSV(const string& filename)
{
    ifstream file(filename);
    vector<vector<string>> data;

    string line;
    while (getline(file, line))
    {
        istringstream ss(line);
        string cell;
        vector<string> row;
        while (getline(ss, cell, ','))
        {
            row.push_back(cell);
        }
        data.push_back(row);
    }

    return data;
}


Graph* CSVParser::CreateGraphFromCSV(const vector<vector<string>>& csvData)
{
    Graph* graph = new Graph();

    for (const auto& row : csvData)
    {
        graph->AddNode(stoi(row[0]));
    }

    for (const auto& row : csvData)
    {
        for (int i = 1; i < row.size(); ++i)
        {
            graph->AddEdge(stoi(row[0]), stoi(row[i]), Random::GetRandomInt(1, 10));
        }
    }
    return graph;
}
