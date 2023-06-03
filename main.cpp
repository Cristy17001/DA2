#include "backtracking.h"
#include "2opt.h"
#include <fstream>
#include <sstream>
#include "Christofides.h"
#include "Manager.h"

using namespace std;

int main() {
    Manager manager;
    manager.loadShipping();
    manager.loadStadiums();
    manager.loadTourism();
    Graph graph = manager.getShippingGraph();

    cout << "Backtracking: " << endl;
    vector<int> auxiliar;
    backtracking(graph, auxiliar);
    cout << "Distance: " << getDistance(graph, auxiliar) << endl;
    printVector(auxiliar, 0);

    cout << "Christofides: " << endl;
    Christofides_algorithm(graph);

    /*
    ifstream edges;
    string str;
    Graph graph;
    edges.open("./data/Toy-Graphs/shipping.csv");
    if (edges.is_open()) {
        getline(edges,str);
    } else {
        cout << "Failed to open\n";
        return 1;
    }
    cout << "lines\n";
    while (!edges.eof()) {
        string origin, destiny, weight;
        int origin_, destiny_;
        double weight_;
        getline(edges, origin, ',');
        getline(edges, destiny, ',');
        getline(edges, weight);

        if (origin.empty() || destiny.empty() || weight.empty()) {continue;}

        //cout << origin << "->" << destiny << " :" << weight << endl;
        origin_ = stoi(origin);
        destiny_ = stoi(destiny);
        weight_ = stod(weight);

        graph.addVertex(origin_);
        graph.addVertex(destiny_);
        graph.addBidirectionalEdge(origin_ ,destiny_ ,weight_);
    }
    edges.close();
    cout << "Executing Christofides" << endl;
    auto res = Christofides_algorithm(graph);


//    dijkstra(graph,0);
//    for (auto v:graph.getVertexSet()) {
//        cout<< v->getId() << ":" << v->getDist()<<"\n";
//    }
//    std::vector<int> result;
//    result.reserve(graph.getNumVertex());
//    for (unsigned int i=0; i < graph.getNumVertex(); ++i)
//        result.push_back(i);
//    double bestDistance=backtracking(graph,result);
//    //double bestDistance = two_opt(graph,result);
//    cout << "distance:" << bestDistance << "\n";
//    for(auto i : result)
//        cout << i<< ",";
//    cout << "\n";
    */
//    return 0;
}