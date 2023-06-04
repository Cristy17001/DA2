// By: Gonçalo Leão

#include "Graph.h"

int Graph::getNumVertex() const {
    return vertexSet.size();
}

const std::vector<Vertex *>& Graph::getVertexSet() const {
    return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex * Graph::findVertex(const int &id) const {
    if(vertexSet.size() > id)
        return vertexSet.at(id);
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
int Graph::findVertexIdx(const int &id) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getId() == id)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool Graph::addVertex(const int &id) {
    if (findVertex(id) != nullptr)
        return false;
    if(vertexSet.size()<id)
        vertexSet.reserve(id);
    for(unsigned int i = vertexSet.size(); i<=id ;++i){
        vertexSet.push_back(new Vertex(i));
    }
    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w);
    return true;
}

bool Graph::addBidirectionalEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, w);
    auto e2 = v2->addEdge(v1, w);
    //e1->setReverse(e2);
    //e2->setReverse(e1);
    return true;
}

std::vector<int> Graph::dfs(const int &source) {
    std::vector<int> res;
    // Get the source vertex
    auto s = findVertex(source);
    if (s == nullptr) {
        return res;
    }

    // Set that no vertex has been visited yet
    for (auto v : vertexSet) {
        v->setVisited(false);
    }

    // Perform the actual DFS using recursion
    dfsVisit(s, res);

    return res;
}

void Graph::dfsVisit(Vertex *v, std::vector<int> &res) const {
    v->setVisited(true);
    res.push_back(v->getId());
    for (auto & e : v->getAdj()) {
        auto w = e->getDest();
        if (!w->isVisited()) {
            dfsVisit(w, res);
        }
    }
}

void Graph::clear() {
    vertexSet.clear();
}

bool Graph::existsEdge(int source, int dest) {
    auto vertex = vertexSet[source];
    for (auto n: vertex->getAdj()) {
        if (n->getOrig()->getId() == source && n->getDest()->getId() == dest) {
            return false;
        }
    }
    return true;
}




