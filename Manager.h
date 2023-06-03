//
// Created by Cristiano on 03/06/2023.
//

#ifndef DA23_PART2_MANAGER_H
#define DA23_PART2_MANAGER_H

#include "data_structures/VertexEdge.h"
#include "data_structures/Graph.h"
#include <fstream>
#include <sstream>
#include<iostream>
#include<string>

class Manager {

private:
    Graph tourismGraph;  // toy graph tourism
    Graph shippingGraph;
public:
    const Graph &getTourismGraph() const;

    void setTourismGraph(const Graph &tourismGraph);

    const Graph &getShippingGraph() const;

    void setShippingGraph(const Graph &shippingGraph);

    const Graph &getStadiumsGraph() const;

    void setStadiumsGraph(const Graph &stadiumsGraph);

private:
    // toy graph shipping
    Graph stadiumsGraph; // toy graph stadiums

public:
    int loadTourism();
    int loadShipping();
    int loadStadiums();


};


#endif //DA23_PART2_MANAGER_H
