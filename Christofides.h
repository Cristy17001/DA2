#ifndef DA23_PART2_CHRISTOFIDES_H
#define DA23_PART2_CHRISTOFIDES_H

#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include "data_structures/VertexEdge.h"
#include "data_structures/Graph.h"

using namespace std;

// Auxiliary function for the Hungarian Algorithm
double min_row(vector<vector<double>> matrix, int row, int ignore_column);
double min_column(const vector<vector<double>>& matrix, int column, int ignore_row);
void clear_row(vector<vector<double>>& matrix, int row);
void clear_column(vector<vector<double>>& matrix, int column);

vector<Vertex *> prim(const Graph& graph);
vector<pair<int, int>> solve_hungarian(vector<vector<double>> matrix);
void DFS();
vector<int> Christofides_algorithm(const Graph& graph);

#endif //DA23_PART2_CHRISTOFIDES_H
