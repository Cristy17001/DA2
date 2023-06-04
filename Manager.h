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

/**
 * @struct geo_pos
 * @brief Represents a geographic position with latitude and longitude coordinates.
 */
struct geo_pos {
    double latitude; /**< The latitude coordinate. */
    double longitude; /**< The longitude coordinate. */
};


/**
 * @class Manager
 * @brief The manager class that stores the main data structures of the program.
 */
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
    /**
     * @brief Gets the real world graph.
     * @return The real world graph.
     */
    const Graph& getRealWorld() const;

    /**
     * @brief Sets the real world graph.
     * @param realWorld The real world graph to set.
     */
    void setRealWorld(const Graph& realWorld);

    /**
     * @brief Gets the geographic positions of nodes in the graph.
     * @return The map of node IDs to geo positions.
     */
    const std::unordered_map<int, geo_pos>& getGeoPositions() const;

    /**
     * @brief Sets the geographic positions of nodes in the graph.
     * @param geoPositions The map of node IDs to geo positions to set.
     */
    void setGeoPositions(const std::unordered_map<int, geo_pos>& geoPositions);

    /**
     * @brief Gets the path graph.
     * @return The path graph.
     */
    const Graph& getPathGraph() const;

    /**
     * @brief Sets the path graph.
     * @param pathGraph The path graph to set.
     */
    void setPathGraph(const Graph& pathGraph);

    /**
     * @brief Gets the extra graph.
     * @return The extra graph.
     */
    const Graph& getExtraGraph() const;

    /**
     * @brief Sets the extra graph.
     * @param extraGraph The extra graph to set.
     */
    void setExtraGraph(const Graph& extraGraph);

    /**
     * @brief Gets the tourism graph.
     * @return The tourism graph.
     */
    const Graph& getTourismGraph() const;

    /**
     * @brief Sets the tourism graph.
     * @param tourismGraph The tourism graph to set.
     */
    void setTourismGraph(const Graph& tourismGraph);

    /**
     * @brief Gets the shipping graph.
     * @return The shipping graph.
     */
    const Graph& getShippingGraph() const;

    /**
     * @brief Sets the shipping graph.
     * @param shippingGraph The shipping graph to set.
     */
    void setShippingGraph(const Graph& shippingGraph);

    /**
     * @brief Gets the stadiums graph.
     * @return The stadiums graph.
     */
    const Graph& getStadiumsGraph() const;

    /**
     * @brief Sets the stadiums graph.
     * @param stadiumsGraph The stadiums graph to set.
     */
    void setStadiumsGraph(const Graph& stadiumsGraph);

    /**
     * @brief Converts degrees to radians.
     * @param degrees The value in degrees to convert.
     * @return The value in radians.
     */
    static double toRadians(double degrees);

    /**
     * @brief Calculates the distance between two points using the Haversine formula.
     * @param lat1 The latitude of the first point.
     * @param lon1 The longitude of the first point.
     * @param lat2 The latitude of the second point.
     * @param lon2 The longitude of the second point.
     * @return The distance between the two points.
     */
    double haversineDistance(double lat1, double lon1, double lat2, double lon2);

    /**
     * @brief Loads the tourism graph information.
     * @return An integer representing an error if different from 0.
     */
    int loadTourism();

    /**
     * @brief Loads the shipping graph information.
     * @return An integer representing an error if different from 0.
     */
    int loadShipping();

    /**
     * @brief Loads the stadiums graph information.
     * @return An integer representing an error if different from 0.
     */
    int loadStadiums();

    /**
     * @brief Loads the extra graph information.
     * @param n_edges The number of edges of the extra graph.
     * @return An integer representing an error if different from 0.
     */
    int loadExtra(const std::string& n_edges);

    /**
     * @brief Loads the path graph from a file.
     * @param path The file path to load the path graph from.
     * @return An integer representing an error if different from 0.
     */
    int loadPathGraph(const std::string& path);

    /**
     * @brief Loads the real world graph information.
     * @param graph_name The name of the real world graph.
     * @return An integer representing an error if different from 0.
     */
    int loadRealWorld(const std::string& graph_name);
};



#endif //DA23_PART2_MANAGER_H
