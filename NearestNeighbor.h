#ifndef DA23_PART2_NEARESTNEIGHBOR_H
#define DA23_PART2_NEARESTNEIGHBOR_H

#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include "data_structures/VertexEdge.h"
#include "data_structures/Graph.h"
#include "2opt.h"


std::vector<int> nearestNeighbor(Vertex* startVertex, Graph& graph);

#endif //DA23_PART2_NEARESTNEIGHBOR_H
