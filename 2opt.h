#include <vector>
#include <iostream>
#include <iterator>
#include "./data_structures/Graph.h"
#include "Manager.h"

long double getDistance(const Graph& g, std::vector<int>& path, bool isRealWorld, Manager manager);

double two_opt(Graph& g, std::vector<int>& bestPath);