#ifndef DA23_PART2_MANAGER_H
#define DA23_PART2_MANAGER_H

#include "data_structures/VertexEdge.h"
#include "data_structures/Graph.h"
#include <unordered_set>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

class Manager {

private:
    // Toy Graphs
    Graph tourismGraph;
    Graph shippingGraph;
    Graph stadiumsGraph;

    // Extra graphs
    Graph extraGraph;

    // Graph by path
    Graph pathGraph;


public:
    const Graph &getPathGraph() const;
    void setPathGraph(const Graph &pathGraph);

    const Graph &getExtraGraph() const;
    void setExtraGraph(const Graph &extraGraph);

    const Graph &getTourismGraph() const;
    void setTourismGraph(const Graph &tourismGraph);

    const Graph &getShippingGraph() const;
    void setShippingGraph(const Graph &shippingGraph);
    const Graph &getStadiumsGraph() const;
    void setStadiumsGraph(const Graph &stadiumsGraph);

    int loadTourism();
    int loadShipping();
    int loadStadiums();
    int loadExtra(const std::string& n_edges);
    int loadPathGraph(const std::string& path);


};


#endif //DA23_PART2_MANAGER_H
