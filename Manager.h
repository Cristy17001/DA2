#ifndef DA23_PART2_MANAGER_H
#define DA23_PART2_MANAGER_H

#include "data_structures/VertexEdge.h"
#include "data_structures/Graph.h"
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cmath>


struct geo_pos {
    double latitude;
    double longitude;
};


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

    // Real World Graphs
    Graph realWorld;

    // For real world graphs
    std::unordered_map<int, geo_pos> geo_positions;


public:

    const Graph &getRealWorld() const;
    void setRealWorld(const Graph &realWorld);

    const std::unordered_map<int, geo_pos> &getGeoPositions() const;
    void setGeoPositions(const std::unordered_map<int, geo_pos> &geoPositions);

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

    // Convert degrees to radians
    static double toRadians(double degrees);

    // Calculate the distance between two points using Haversine formula
    double haversineDistance(double lat1, double lon1, double lat2, double lon2);


    /**
     * Load tourism graph information.
     *
     * @return An integer representing error if different from 0
     */
    int loadTourism();

    /**
     * Load shipping graph information.
     *
     * @return An integer representing error if different from 0
     */
    int loadShipping();

    /**
     * Load stadiums graph information.
     *
     * @return An integer representing error if different from 0
     */
    int loadStadiums();

    /**
     * Load extra graphs information.
     *
     * @param n_edges The number of edges of the extra graph.
     * @return An integer representing error if different from 0
     */
    int loadExtra(const std::string& n_edges);

    /**
     * Load the graph given the path to a file.
     *
     * @param path The file path to load the path graph from.
     * @return An integer representing error if different from 0
     */
    int loadPathGraph(const std::string& path);

    int loadRealWorld(const std::string& graph_name);

};


#endif //DA23_PART2_MANAGER_H
