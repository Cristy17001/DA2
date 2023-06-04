#ifndef DA23_PART2_CHRISTOFIDES_H
#define DA23_PART2_CHRISTOFIDES_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <algorithm>
#include "2opt.h"
#include "data_structures/VertexEdge.h"
#include "data_structures/Graph.h"

using namespace std;

// Auxiliary function for the Hungarian Algorithm
/**
 * Find the minimum value in a specified row of a matrix, excluding a specific column.
 *
 * @param matrix The matrix to search.
 * @param row The index of the row to search.
 * @param ignore_column The index of the column to exclude.
 * @return The minimum value found in the row.
 */
double min_row(std::vector<std::vector<double>> matrix, int row, int ignore_column);

/**
 * Find the minimum value in a specified column of a matrix, excluding a specific row.
 *
 * @param matrix The matrix to search.
 * @param column The index of the column to search.
 * @param ignore_row The index of the row to exclude.
 * @return The minimum value found in the column.
 */
double min_column(const std::vector<std::vector<double>>& matrix, int column, int ignore_row);

/**
 * Clear a specified row of a matrix by setting all its elements to 0.
 *
 * @param matrix The matrix to modify.
 * @param row The index of the row to clear.
 */
void clear_row(std::vector<std::vector<double>>& matrix, int row);

/**
 * Clear a specified column of a matrix by setting all its elements to 0.
 *
 * @param matrix The matrix to modify.
 * @param column The index of the column to clear.
 */
void clear_column(std::vector<std::vector<double>>& matrix, int column);

/**
 * Perform the Prim's algorithm to find a minimum spanning tree on a graph.
 *
 * @param graph The Graph object representing the graph to process.
 * @return A vector of Vertex pointers representing the vertices in the minimum spanning tree.
 */
std::vector<Vertex*> prim(const Graph& graph);

/**
 * Solve the Hungarian algorithm to find the optimal assignment in a matrix.
 *
 * @param matrix The matrix to solve.
 * @return A vector of pairs representing the optimal assignment in the matrix.
 */
std::vector<std::pair<int, int>> solve_hungarian(std::vector<std::vector<double>> matrix);

/**
 * Apply the Christofides algorithm to find an approximate solution for the Traveling Salesman Problem (TSP).
 *
 * @param graph The Graph object representing the TSP problem.
 * @return A vector of integers representing the order of visited vertices in the TSP tour.
 */
std::vector<int> Christofides_algorithm(Graph& graph);

#endif //DA23_PART2_CHRISTOFIDES_H
