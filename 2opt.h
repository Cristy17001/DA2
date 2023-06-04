#include <vector>
#include <iostream>
#include <iterator>
#include "./data_structures/Graph.h"
#include "Manager.h"

/**
 * @brief Calculates the distance of a path in the graph.
 *
 * This function calculates the distance of a given path in the graph. The time complexity of this function
 * depends on the number of vertices in the path and whether the graph is a real-world graph or not.
 *
 * @param g The graph in which to calculate the distance.
 * @param path The path for which to calculate the distance.
 * @param isRealWorld Specifies whether the graph is a real-world graph.
 * @param manager The Manager object containing additional information for real-world graphs.
 * @complexity The time complexity of this function is O(V * E), where V is the number of vertices and E the number of edges
 * @return The distance of the path.
 *
 */
long double getDistance(const Graph& g, std::vector<int>& path, bool isRealWorld, Manager manager);