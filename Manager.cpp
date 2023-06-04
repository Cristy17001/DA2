#include "Manager.h"


int Manager::loadTourism(){
    std::ifstream tourism;
    std::string line;
    tourism.open("./data/Toy-Graphs/tourism.csv");

    //checks if opened
    if(tourism.is_open()){ std::getline(tourism,line);} //gets the first line
    else{
        std::cout << "Could not open file";
        return 1;
    }

    //loads graph
    while (!tourism.eof()){

        //variables declaration &loads them
        int origin,destination;
        double weight;
        std::string origin_string,destination_string,weight_string;
        std::string origin_label,destination_label;

        std::getline(tourism,origin_string,',');
        std::getline(tourism,destination_string,',');
        std::getline(tourism,weight_string,',');
        std::getline(tourism,origin_label,',');
        std::getline(tourism,destination_label);

        origin = std::stoi(origin_string);
        destination = std::stoi(destination_string);
        weight = std::stod(weight_string);

        //adds the edge && vertex
        if(tourismGraph.addVertex(origin)){tourismGraph.findVertex(origin)->setLabel(origin_label);}
        if(tourismGraph.addVertex(destination)){tourismGraph.findVertex(origin)->setLabel(destination_label);}
        tourismGraph.addBidirectionalEdge(origin, destination, weight);
    }

    tourism.close();
    return 0;
}

int Manager::loadShipping(){

    std::ifstream shipping;
    std::string line;
    shipping.open("./data/Toy-Graphs/shipping.csv");

    //checks if opened
    if(shipping.is_open()){ std::getline(shipping,line);} //gets the first line
    else{
        std::cout << "Could not open file";
        return 1;
    }

    //loads graph
    while (!shipping.eof()){

        //variables declaration &loads them
        int origin,destination;
        double weight;
        std::string origin_string,destination_string,weight_string;

        std::getline(shipping,origin_string,',');
        std::getline(shipping,destination_string,',');
        std::getline(shipping,weight_string);


        origin = std::stoi(origin_string);
        destination = std::stoi(destination_string);
        weight = std::stod(weight_string);

        //adds the edge && vertex
        shippingGraph.addVertex(origin);
        shippingGraph.addVertex(destination);
        shippingGraph.addBidirectionalEdge(origin, destination, weight);
    }

    shipping.close();
    return 0;
}

int Manager::loadStadiums() {
    std::ifstream stadiums;
    std::string line;
    stadiums.open("./data/Toy-Graphs/stadiums.csv");

    //checks if opened
    if(stadiums.is_open()){ std::getline(stadiums,line);} //gets the first line
    else{
        std::cout << "Could not open file";
        return 1;
    }

    //loads graph
    while (!stadiums.eof()){

        //variables declaration &loads them
        int origin,destination;
        double weight;
        std::string origin_string,destination_string,weight_string;

        std::getline(stadiums,origin_string,',');
        std::getline(stadiums,destination_string,',');
        std::getline(stadiums,weight_string);

        origin = std::stoi(origin_string);
        destination = std::stoi(destination_string);
        weight = std::stod(weight_string);

        //adds the edge && vertex
        stadiumsGraph.addVertex(origin);
        stadiumsGraph.addVertex(destination);
        stadiumsGraph.addBidirectionalEdge(origin, destination, weight);
    }

    stadiums.close();
    return 0;
}

int Manager::loadExtra(const std::string& n_edges) {
    std::unordered_set<std::string> possibilities = {"25", "50", "75", "100", "200", "300", "400", "500", "600", "700", "800", "900"};
    std::string file_path = "./data/extra/edges_";
    if (possibilities.find(n_edges) == possibilities.end()) {
        std::cout << "Error: no such numbers of edges was found!" << std::endl;
        return 1;
    }
    else {
        file_path += n_edges + ".csv";
    }

    std::ifstream extra;
    std::string line;
    extra.open(file_path);

    //checks if opened
    if(extra.is_open()){
        std::getline(extra, line);
    } //gets the first line
    else {
        std::cout << "Could not open file";
        return 1;
    }

    //loads graph
    while (!extra.eof()){

        //variables declaration &loads them
        int origin, destination;
        double weight;
        std::string origin_string,destination_string,weight_string;

        std::getline(extra, origin_string,',');
        std::getline(extra, destination_string,',');
        std::getline(extra, weight_string);

        if (origin_string.empty() || destination_string.empty() || weight_string.empty()) {continue;}
        origin = std::stoi(origin_string);
        destination = std::stoi(destination_string);
        weight = std::stod(weight_string);

        //adds the edge && vertex
        extraGraph.addVertex(origin);
        extraGraph.addVertex(destination);
        extraGraph.addBidirectionalEdge(origin, destination, weight);
    }

    extra.close();

    return 0;
}

int Manager::loadPathGraph(const std::string& path) {
    if (pathGraph.getNumVertex() != 0) {
        pathGraph.clear();
    }

    std::ifstream file;
    std::string line;
    file.open(path);

    //checks if opened
    if(file.is_open()){
        std::getline(file, line);
    } //gets the first line
    else {
        std::cout << "Could not open file";
        return 1;
    }

    //loads graph
    while (!file.eof()){

        //variables declaration &loads them
        int origin, destination;
        double weight;
        std::string origin_string,destination_string,weight_string;

        std::getline(file, origin_string,',');
        std::getline(file, destination_string,',');
        std::getline(file, weight_string);

        if (origin_string.empty() || destination_string.empty() || weight_string.empty()) {continue;}
        origin = std::stoi(origin_string);
        destination = std::stoi(destination_string);
        weight = std::stod(weight_string);

        //adds the edge && vertex
        pathGraph.addVertex(origin);
        pathGraph.addVertex(destination);
        pathGraph.addBidirectionalEdge(origin, destination, weight);
    }

    file.close();

    return 0;
}


const Graph &Manager::getTourismGraph() const {
    return tourismGraph;
}

void Manager::setTourismGraph(const Graph &tourismGraph) {
    Manager::tourismGraph = tourismGraph;
}

const Graph &Manager::getShippingGraph() const {
    return shippingGraph;
}

void Manager::setShippingGraph(const Graph &shippingGraph) {
    Manager::shippingGraph = shippingGraph;
}

const Graph &Manager::getStadiumsGraph() const {
    return stadiumsGraph;
}

void Manager::setStadiumsGraph(const Graph &stadiumsGraph) {
    Manager::stadiumsGraph = stadiumsGraph;
}

const Graph &Manager::getExtraGraph() const {
    return extraGraph;
}

void Manager::setExtraGraph(const Graph &extraGraph) {
    Manager::extraGraph = extraGraph;
}

const Graph &Manager::getPathGraph() const {
    return pathGraph;
}

void Manager::setPathGraph(const Graph &pathGraph) {
    Manager::pathGraph = pathGraph;
}
