#include <vector>
#include <iostream>
#include <iterator>
#include "./data_structures/Graph.h"

double getDistance(const Graph& g, std::vector<int>& path);

void printVector(std::vector<int>& v, int line);

double two_opt(Graph& g, std::vector<int>& bestPath);