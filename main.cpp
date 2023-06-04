#include "backtracking.h"
#include "2opt.h"
#include <sstream>
#include "Christofides.h"
#include "Manager.h"
#include "NearestNeighbor.h"

using namespace std;

int main() {
    cout << "Loading..." << endl;
    Manager manager;
    manager.loadRealWorld("graph1");


    //cout << "Backtracking: " << endl;
    //vector<int> auxiliar;
    //backtracking(graph, auxiliar);
    //cout << "Distance: " << getDistance(graph, auxiliar) << endl;
    //printVector(auxiliar, 0);


    Graph graph = manager.getRealWorld();
    Vertex * starting_node = graph.getVertexSet()[0];

    cout << "Nearest Neighbor" << endl;
    auto tour = nearestNeighbor(starting_node, graph);

    std::cout << "Distance:" << getDistance(graph, tour, true, manager) << std::endl;
    for (auto e: tour) {
        std::cout << e << ", ";
    }
    cout << starting_node->getId();

    cout << "\nChristofides: " << endl;
    auto path = Christofides_algorithm(graph);
    std::cout << "Distance:" << getDistance(graph, path, true, manager) << std::endl;
    for (auto e: path) {
        std::cout << e << ", ";
    }

    cout << starting_node->getId();
}