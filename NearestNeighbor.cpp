#include "NearestNeighbor.h"
#include "Timer.h"

std::vector<int> nearestNeighbor(Vertex* startVertex, Graph& graph) {
    Timer timer;

    std::vector<int> tour; //gets result

    //resets
    std::vector<Vertex*> vertexSet = graph.getVertexSet();
    for(int i = 0; i<graph.getNumVertex(); i++){
        vertexSet[i]->setVisited(false);
    }

    Vertex* currentVertex = startVertex;
    currentVertex->setVisited(true);         //sets first vertex as visited
    tour.push_back(currentVertex->getId()); //initializes tour

    while (true) {
        Edge* nearestNeighborEdge = nullptr;
        double minDistance = INT64_MAX;

        for (Edge* edge : currentVertex->getAdj()) { //checks best route to next vertex
            Vertex* neighborVertex = edge->getDest();
            if (!neighborVertex->isVisited()) {
                double distance = edge->getWeight();
                if (distance < minDistance) {
                    minDistance = distance;
                    nearestNeighborEdge = edge;
                }
            }
        }

        if (nearestNeighborEdge == nullptr) { //checks if tour is finished
            bool isEdge = false;
            // All nodes have been visited, return to the starting vertex
            for(Edge* edge : currentVertex->getAdj()){
                if(edge->getDest()==startVertex) isEdge= true;
            }
            if(isEdge) tour.push_back(startVertex->getId());
            else std::cout <<"something went wrong";
            break;
        }

        //after finding the best route passes to the next vertex
        Vertex* nextVertex = nearestNeighborEdge->getDest();
        nextVertex->setVisited(true);
        tour.push_back(nextVertex->getId());
        currentVertex = nextVertex;
    }

    two_opt(graph, tour);
    std::cout << "Distance:" << getDistance(graph, tour) << std::endl;
    for (auto e: tour) {
        std::cout << e << ", ";
    }


    return tour;
}