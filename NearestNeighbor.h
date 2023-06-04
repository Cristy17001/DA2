#ifndef DA23_PART2_NEARESTNEIGHBOR_H
#define DA23_PART2_NEARESTNEIGHBOR_H

#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include "data_structures/VertexEdge.h"
#include "data_structures/Graph.h"
#include "2opt.h"


/**
 * Finds an approximate solution to the Traveling Salesman Problem (TSP)
 * using the Nearest Neighbor heuristic.
 *
 * @param startVertex Pointer to the starting vertex for the TSP tour.
 * @param graph Reference to the Graph object representing the TSP problem.
 * @complexity O(N^2), where N is the number of vertices in the graph
 * @return A vector of integers representing the order of visited vertices in the TSP tour.
 */
std::vector<int> nearestNeighbor(Vertex* startVertex, Graph& graph);

#endif //DA23_PART2_NEARESTNEIGHBOR_H
