#pragma once
#include <string>
#include <vector>
#include "../DataStructures/Graph.h"
using namespace std;

class CSVParser
{
public:
    static vector<vector<string>> parseCSV(const string& filename);
    static Graph* CreateGraphFromCSV(const vector<vector<string>>& filename);
};
