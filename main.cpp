#include "backtracking.h"
#include "2opt.h"
#include <sstream>
#include "Christofides.h"
#include "Manager.h"
#include "NearestNeighbor.h"

using namespace std;

int main() {
    Manager manager;
    manager.loadShipping();
    manager.loadStadiums();
    manager.loadTourism();
    manager.loadExtra("200");
    manager.loadPathGraph("./data/extra/edges_25.csv");


    //cout << "Backtracking: " << endl;
    //vector<int> auxiliar;
    //backtracking(graph, auxiliar);
    //cout << "Distance: " << getDistance(graph, auxiliar) << endl;
    //printVector(auxiliar, 0);

    Graph graph = manager.getShippingGraph();

    cout << "Christofides: " << endl;
    Christofides_algorithm(graph);


    cout << "Nearest Neighbor" << endl;
    nearestNeighbor(graph.getVertexSet()[0], graph);

}