#include "Christofides.h"
#include "Timer.h"

// Auxiliary function for Christofides
double min_row(vector<vector<double>> matrix, int row, int ignore_column) {
    double row_minimum = INF;
    unsigned int size = matrix.size();

    for (int j = 0; j < size; j++) {
        if (j != ignore_column) {
            if (matrix[row][j] < row_minimum) {
                row_minimum = matrix[row][j];
            }
        }
    }

    return row_minimum;
}
double min_column(const vector<vector<double>>& matrix, int column, int ignore_row) {
    double column_minimum = INF;
    unsigned int size = matrix.size();

    for (int i = 0; i < size; i++) {
        if (i != ignore_row) {
            if (matrix[i][column] < column_minimum) {
                column_minimum = matrix[i][column];
            }
        }
    }

    return column_minimum;
}
void clear_row(vector<vector<double>>& matrix, int row) {
    for (int j = 0; j < matrix.size(); j++) {
        matrix[row][j] = INF;
    }
}
void clear_column(vector<vector<double>>& matrix, int column) {
    for (auto& row: matrix) {
        row[column] = INF;
    }
}

// Main function for Christofides
vector<Vertex *> prim(const Graph& graph) {
    auto vertexSet = graph.getVertexSet();
    if (vertexSet.empty()) {
        return vertexSet;
    }

    // Reset auxiliary info
    for(auto v : vertexSet) {
        v->setDist(INF);
        v->setPath(nullptr);
        v->setVisited(false);
    }

    // start with an arbitrary vertex
    Vertex* s = vertexSet.front();
    s->setDist(0);

    // initialize priority queue
    MutablePriorityQueue<Vertex> q;
    q.insert(s);
    // process vertices in the priority queue
    while(!q.empty()) {
        auto v = q.extractMin();
        v->setVisited(true);
        for(auto &e : v->getAdj()) {
            Vertex* w = e->getDest();
            if (!w->isVisited()) {
                auto oldDist = w->getDist();
                if(e->getWeight() < oldDist) {
                    w->setDist(e->getWeight());
                    w->setPath(e);
                    if (oldDist == INF) {
                        q.insert(w);
                    }
                    else {
                        q.decreaseKey(w);
                    }
                }
            }
        }
    }

    return vertexSet;
}

vector<pair<int, int>> solve_hungarian(vector<vector<double>> matrix) {
    unsigned long size = matrix.size();
    vector<pair<int, int>> res;


    while (res.size() != size) {
        // Row reduction
        for (int i = 0; i < size; i++) {
            double row_minimum = min_row(matrix, i, std::numeric_limits<int>::max());
            if (row_minimum != INF && row_minimum != 0) {
                for (auto &e: matrix[i]) {
                    // Subtract the row minimum
                    e -= row_minimum;
                }
            }
        }

        // Column reduction
        for (int i = 0; i < size; i++) {
            double column_minimum = min_column(matrix, i, std::numeric_limits<int>::max());
            if (column_minimum != INF && column_minimum != 0) {
                for (int j = 0; j < size; j++) {
                    matrix[j][i] -= column_minimum;
                }
            }
        }

        // Largest penalty
        double largest_penalty = 0;
        int largest_pen_row = 0;
        int largest_pen_column = 0;

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix[i][j] == 0) {
                    double penalty = min_row(matrix, i, j) + min_column(matrix, j, i);
                    if (penalty > largest_penalty) {
                        largest_penalty = penalty;
                        largest_pen_row = i;
                        largest_pen_column = j;
                    }
                }
            }
        }
        // Add the one with the largest penalty to the result
        res.emplace_back(largest_pen_row, largest_pen_column);

        // Remove the reverse and that row and column
        matrix[largest_pen_column][largest_pen_row] = INF;
        clear_row(matrix, largest_pen_row);
        clear_column(matrix, largest_pen_column);

    }

    return res;
}


vector<int> Christofides_algorithm(Graph& graph) {
    Timer timer;
    timer.start();

    // STEP 1:
    // Get the MST of the graph using Prims or Kruskal algorithm
    auto res = prim(graph);

    Graph MST;

    for (const auto v : res) {
        MST.addVertex(v->getId());
        if (v->getPath() != nullptr) {
            MST.addVertex(v->getPath()->getOrig()->getId());
            MST.addBidirectionalEdge(v->getId(), v->getPath()->getOrig()->getId(), v->getPath()->getWeight());
        }
    }

    // STEP 2:
    // Get the vertices with odd number of neighbors from MST
    unordered_map<Vertex*, int> odd_vertex;
    vector<Vertex*> odd_vertex_vec;

    int index = 0;
    for (auto v: MST.getVertexSet()) {
        if (v->getAdj().size() % 2 != 0) {
            odd_vertex.insert({graph.findVertex(v->getId()), index});
            odd_vertex_vec.push_back(graph.findVertex(v->getId()));
            index++;
        }
    }

    // STEP 3:
    // Construct the cost matrix with those vertices
    vector<vector<double>> CostMatrix(odd_vertex.size(), vector<double>(odd_vertex.size(), INF));
    for (auto v: odd_vertex_vec) {
        int current_index = odd_vertex[v];
        for (auto neighbor: v->getAdj()) {
            if (odd_vertex.find(neighbor->getDest()) != odd_vertex.end()) {
                int neighbor_index = odd_vertex[neighbor->getDest()];
                CostMatrix[current_index][neighbor_index] = neighbor->getWeight();
                CostMatrix[neighbor_index][current_index] = neighbor->getWeight();

            }
        }
    }

    // STEP 4:
    // Execute the Hungarian algorithm to determine the perfect matching
    auto pairs = solve_hungarian(CostMatrix);

    // STEP 5:
    // Add the edges obtained in the last step to the MST
    for (auto p: pairs) {
        double weight = CostMatrix[p.first][p.second];
        if (odd_vertex_vec[p.first]->getId() != odd_vertex_vec[p.second]->getId()
        && MST.existsEdge(odd_vertex_vec[p.first]->getId(), odd_vertex_vec[p.second]->getId())) {
            MST.addBidirectionalEdge(odd_vertex_vec[p.first]->getId(), odd_vertex_vec[p.second]->getId(), weight);
        }
    }


    // STEP 6:
    // Find the Euclidean circuit that visits all edges only once
    auto euclidean_circuit = MST.dfs(0);

    timer.stop();
    cout << "Function took: " << timer.getDurationInSeconds() << " ms" << endl;
    return euclidean_circuit;
}
