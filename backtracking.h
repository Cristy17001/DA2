#include <vector>
#include <iostream>
#include <numeric>
#include "./data_structures/Graph.h"
#include "./data_structures/MutablePriorityQueue.h"
#include "Timer.h"

#define DIJKSTRA_OPTIMIZATION_MIN_HEIGHT (8) //minimum distance in levels from leaf nodes in which dijkstra is called.

void dijkstra_subgraph(Graph& g, int startIndex){
    MutablePriorityQueue<Vertex> q;
    for(Vertex* v : g.getVertexSet()){
        if(!v->isVisited()){
            v->setDist(std::numeric_limits<double>::infinity());
            v->setPath(nullptr);
        }
    }
    Vertex * startVertex = g.findVertex(startIndex);
    startVertex->setDist(0);
    q.insert(startVertex);
    while(!q.empty()){
        Vertex*curr=q.extractMin();
        for(Edge*e : curr->getAdj()){
            Vertex* eDest = e->getDest();
            if(eDest->isVisited())
                continue;
            double newDist = curr->getDist() + e->getWeight();
            if(eDest->getDist() < newDist){
                continue;
            }
            eDest->setDist(newDist);
            if(eDest->getPath() == nullptr)
                q.insert(eDest);
            else
                q.decreaseKey(eDest);
            eDest->setPath(e);
        }
    }
}
void dijkstra(Graph& g, int startIndex){
    MutablePriorityQueue<Vertex> q;
    for(Vertex* v : g.getVertexSet()){
        v->setDist(std::numeric_limits<double>::infinity());
        v->setPath(nullptr);
    }
    Vertex * startVertex = g.findVertex(startIndex);
    startVertex->setDist(0);
    q.insert(startVertex);
    while(!q.empty()){
        Vertex*curr=q.extractMin();
        for(Edge*e : curr->getAdj()){
            Vertex* eDest = e->getDest();
            double newDist = curr->getDist() + e->getWeight();
            if(eDest->getDist() < newDist){
                continue;
            }
            eDest->setDist(newDist);
            if(eDest->getPath() == nullptr)
                q.insert(eDest);
            else
                q.decreaseKey(eDest);
            eDest->setPath(e);
        }
    }
}

void recursiveVisit(Graph& g, std::vector<int>& bestPath, double& bestDistance, std::vector<int>& path, double distance){
    Vertex * v = g.getVertexSet().at(path.back());
    if(v->getDist() >= (bestDistance - distance)) // current node cannot complete cycle in less distance than bestPath.
        return; //Pruned.
    if(path.size() == g.getNumVertex()){//completed cycle.
        if(path[1] > path.back())
            return;
        Edge * e=nullptr;
        for (auto edge : v->getAdj()){
            if(edge->getDest()->getId() ==0){
                e = edge;
                break;
            }
        }
        if(e == nullptr){
            return; //last vertex in path cannot reach starting node.
        }
        distance += e->getWeight();

        if(distance < bestDistance){
            std::copy(path.begin(), path.end(), bestPath.begin());
            bestDistance = distance;
        }
        return;
    }
    v->setVisited(true);
    if(g.getNumVertex() - path.size() == DIJKSTRA_OPTIMIZATION_MIN_HEIGHT){ //does not get broken in subbranches
        dijkstra_subgraph(g,path.front());//Better pruning.
    }
    for (auto edge : v->getAdj())
    {
        if(edge->getDest()->isVisited())
            continue; // vertex already in path;
        if(g.getNumVertex() - path.size() > DIJKSTRA_OPTIMIZATION_MIN_HEIGHT){ //needs calling again as subbranches will overwrite it.
            dijkstra_subgraph(g,path.front()); //Better pruning.
        }
        double nextDistance = distance + edge->getWeight();
        if (nextDistance < bestDistance){ // maybe redundant?
            path.push_back(edge->getDest()->getId());
            recursiveVisit(g, bestPath, bestDistance, path, nextDistance);
            path.pop_back();
        }
    }
    v->setVisited(false);
}
double backtracking(Graph& g, std::vector<int>& bestPath){
    Timer timer;
    timer.start();
    bestPath.resize(g.getNumVertex());
    dijkstra(g,0);
    std::iota(bestPath.begin(), bestPath.end(),0);
    std::vector<int> tempPath = {0};
    tempPath.reserve(g.getNumVertex());
    dijkstra(g, 0);
    double bestDistance = std::numeric_limits<double>::infinity();
    recursiveVisit(g,bestPath,bestDistance, tempPath, 0);
    timer.stop();
    std::cout << "Function took: " << timer.getDurationInSeconds() << " s" << std::endl;
    return bestDistance;
}
