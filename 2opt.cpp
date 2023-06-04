#include "2opt.h"

long double getDistance(const Graph& g, std::vector<int>& path, bool isRealWorld, Manager manager){
    long double distance = 0;
    for (unsigned int i = 0; i < path.size(); ++i) {
        unsigned int nextID = (i == (path.size()-1)) ? path[0]: path[i+1] ;
        Vertex *v = g.findVertex(path[i]);
        if (v == nullptr)
            return -INF;
        
        Edge* e = nullptr;
        for(Edge* tmp: v->getAdj()){
            if (tmp->getDest()->getId() == nextID) {
                e = tmp;
                break;
            }
        }
        if (e == nullptr && isRealWorld) {
            auto geo_positions = manager.getGeoPositions();
            auto current_positon = geo_positions[v->getId()];
            auto position_next = geo_positions[nextID];
            distance += manager.haversineDistance(current_positon.latitude, current_positon.longitude, position_next.latitude, position_next.longitude);
            return distance;
        }
        else if (e == nullptr) {
            std::cout << "Infinity" << std::endl;
            return INF;
        }
        distance += e->getWeight();
    }
    return distance;
}