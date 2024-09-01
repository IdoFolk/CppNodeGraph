#include "CSVParser.h"
#include <random>
#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>

#include "../Random/Random.h"

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
            // Trim whitespace (optional)
            cell.erase(0, cell.find_first_not_of(' ')); // leading
            cell.erase(cell.find_last_not_of(' ') + 1); // trailing

            if(empty(cell)) continue;
            
            // Validate that the cell is a number
            if (!isNumber(cell))
            {
                cerr << "Invalid data: '" << cell << "' is not a number." << endl;
                exit(0);
            }
            
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

bool CSVParser::isNumber(const string& str)
{
    // Check if the string is empty or contains non-digit characters
    if (str.empty()) return false;

    for (char c : str)
    {
        if (!isdigit(c) && c != '.' && c != '-') // Allow negative numbers and decimals
            return false;
    }
    return true;
}