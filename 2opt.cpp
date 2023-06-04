#include "2opt.h"

double getDistance(const Graph& g, std::vector<int>& path){
    double distance = 0;
    for(unsigned int i=0; i<path.size();++i){
        unsigned int nextID= (i == (path.size()-1))? path[0]: path[i+1] ;
        Vertex*v = g.findVertex(path[i]);
        if (v == nullptr)
            return - INF;
        
        Edge*e = nullptr;
        for(Edge*tmp:v->getAdj()){
            if(tmp->getDest()->getId() == nextID){
                e=tmp;
                break;
            }
        }
        if(e == nullptr)
            return INF;
        distance+=e->getWeight();
    }
    return distance;
}
void printVector(std::vector<int>& v, int line){
    std::cout << line << ":";
    for(int i: v){
        std::cout <<i << ",";
    }
    std::cout << "\n";
}
double two_opt(Graph& g, std::vector<int>& bestPath){
    //TODO generate a starting path.
    printVector(bestPath,31);
    std::vector<int> testPath(g.getNumVertex());
    printVector(testPath,33);
    double bestDistance = getDistance(g, bestPath);
    bool foundImprovement;
    do{
        foundImprovement = false;
        for(unsigned int i=1; i<bestPath.size() && !foundImprovement; ++i){
            //testPath.push_back(bestPath[i-1]);
            printVector(testPath,41);
            testPath[i-1]=bestPath[i-1];
            for(unsigned int j= i+1 ; j <= bestPath.size(); ++j){
                auto bestJt=bestPath.begin() + j;
                auto testJt = std::reverse_copy(bestPath.begin()+i,bestJt,testPath.begin()+i);
                //std::advance(testIt,j-i);
                std::copy(bestJt,bestPath.end(),testJt);
                double testDistance = getDistance(g,testPath);
                if(testDistance<bestDistance){
                    foundImprovement = true;
                    bestDistance = testDistance;
                    std::copy(testPath.begin()+i,testPath.begin()+j,bestPath.begin()+i);
                    break;
                }
            }
        }
    } while(foundImprovement);
    return bestDistance;
}