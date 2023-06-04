#include "backtracking.h"
#include "2opt.h"
#include <sstream>
#include "Christofides.h"
#include "Manager.h"
#include "NearestNeighbor.h"
#define  MENU_WIDTH (60)

using namespace std;

int getChoice(int min, int max) {
    string choice;
    int choiceint;
    bool error = false;

    cin >> choice;
    try {
        choiceint = stoi(choice);
    }
    catch (const exception &e) {
        choiceint = 0;
        error = true;
    }

    if (!(choiceint >= min && choiceint <= max)) {
        choiceint = 0;
        error = true;
    }

    if (error) {
        cout << "Input not recognized, please insert a number between " << min << " and " << max << "\n";
    }

    return choiceint;
}

void printMenu(string &title , vector<string> &options){
    if(title.size()>MENU_WIDTH-2)
        return;
    string line = "+" + string(MENU_WIDTH-2,'-') + "+\n";
    cout << line;
    cout << "|";
    cout << string((MENU_WIDTH-2-title.size())/2,' ') << title <<string((MENU_WIDTH-2-title.size())/2,' ');
    if((MENU_WIDTH-title.size()) % 2)
        cout << ' ';
    cout << "|\n";
    cout << line;
    for(int i=0;i<options.size();++i){
        cout<< "| " << i+1 <<". ";
        unsigned int lineCharCount =5;
        stringstream stream;
        stream << options[i];
        while(!stream.eof()){
            string word;
            stream>>word;
            if(word.size() > MENU_WIDTH-lineCharCount-3 && lineCharCount!=2){
                stream.seekg(-word.size(),stream.cur); //ungets word.
                cout << string( max<int>(MENU_WIDTH-1-lineCharCount,0),' ')<<"|\n| "; //overflow to new line.
                lineCharCount=2;
            }else{
                if(lineCharCount==2){ //word larger than MENU_WIDTH-4
                    while(word.size() >= MENU_WIDTH-4){
                        cout << word.substr(0,MENU_WIDTH-4) << "-|\n| ";
                        word=word.substr(MENU_WIDTH-4);
                        lineCharCount=2;
                    }
                    if(word.size()==0)
                        continue;
                }
                cout << word;
                lineCharCount+=word.size();
                if(lineCharCount < MENU_WIDTH-2){
                    cout <<" ";
                    lineCharCount++;
                }
                if(lineCharCount >= MENU_WIDTH-2){
                    if(lineCharCount==MENU_WIDTH-2)
                        cout<<" ";
                    cout<< "|\n| ";
                    lineCharCount=2;
                }
            }
        }
        cout << string(MENU_WIDTH-1-lineCharCount,' ')<<"|\n";
        cout << line;
    }
    cout << "->";
}

void printSectionTitle(const string& title) {
    int size = (MENU_WIDTH - title.size()) / 2;
    for (int i = 0; i < size; i++) { cout << "="; }
    cout << title;
    for (int i = 0; i < size; i++) { cout << "="; }
    if (title.size() % 2 != 0) { cout << "="; }
    cout << endl;
}
void printTour(vector<int> tour,long double dist){
    cout <<"Path: ";
    for(auto x : tour){
        cout << x << ",";
    }
    cout << tour[0];
    cout << endl;
    cout << "Distance: " << dist << endl;
}

void printResults(Graph graph,string title1,bool doBacktracking,bool doNearestNeighbour,bool doChristofides,bool isRealWorld){
    Manager temp;

    printSectionTitle(title1);
    vector<int> tour1;

    if(doBacktracking) {
        cout << "->Backtracking" << endl;
        auto dist1 = backtracking(graph, tour1);
        printTour(tour1, dist1);
        cout << endl;
        cout << endl;
    }


    if(doNearestNeighbour) {
        cout << "->Nearest Neighbour" << endl;
        auto tour2 = nearestNeighbor(graph.getVertexSet()[0], graph);
        auto dist2 = getDistance(graph, tour2, isRealWorld, temp);
        printTour(tour2, dist2);
        cout << endl;
        cout << endl;
    }

    if(doChristofides) {
        cout << "->Christofides Algorithm" << endl;
        auto tour3 = Christofides_algorithm(graph);
        auto dist3 = getDistance(graph, tour3, isRealWorld, temp);
        printTour(tour3, dist3);
    }


    cout << endl;
    for(int i=0;i<MENU_WIDTH;i++){cout << "=";}
    cout << endl;
}


int main() {
    Manager manager;
    manager.loadShipping();
    manager.loadStadiums();
    manager.loadTourism();
    Graph shippingGraph = manager.getShippingGraph();
    Graph stadiumGraph = manager.getStadiumsGraph();
    Graph tourismGraph = manager.getTourismGraph();


    string title= "PROJECT 2";
    string titleMediumGraph = "MEDIUM GRAPHS ANALYTICS";
    string titleRealWorldGraph1 = "REAL WORLD GRAPH ANALYTICS WITH NEAREST NEIGHBOUR";
    string titleRealWorldGraph2 = "REAL WORLD GRAPH ANALYTICS WITH CHRISTOFIDES";
    string titlePathGraph = "PATH GRAPH ANALYTICS";

    vector<string> choices = {
            "SHOW TOY GRAPHS ANALYTICS",
            "SELECT MEDIUM GRAPHS ANALYTICS",
            "SELECT REAL-WORLD GRAPH WITH NEAREST NEIGHBOR",
            "SELECT REAL-WORLD GRAPH WITH CHRISTOFIDES ALGORITHM",
            "Select arbitary graph and algorithm",
            "QUIT"
    };
    vector<string> choicesMediumGraph = {
            "GRAPH WITH 25 EDGES",
            "GRAPH WITH 50 EDGES",
            "GRAPH WITH 75 EDGES",
            "GRAPH WITH 100 EDGES",
            "GRAPH WITH 200 EDGES",
            "GRAPH WITH 300 EDGES",
            "GRAPH WITH 400 EDGES",
            "GRAPH WITH 500 EDGES",
            "GRAPH WITH 600 EDGES",
            "GRAPH WITH 700 EDGES",
            "GRAPH WITH 800 EDGES",
            "GRAPH WITH 900 EDGES",
            "BACK"
    };
    vector<string> choicesRealWorldGraph = {
            "GRAPH 1",
            "GRAPH 2",
            "GRAPH 3",
            "BACK"
    };

    vector<string> choichesPathGraph{
        "BACKTRACKING",
        "NEAREST NEIGHBOUR",
        "CHRISTOFIDES",
        "NEAREST NEIGHBOUR AND CHRISTOFIDES",
        "ALL 3 ALGORITHMS",
        "BACK"
    };
    int choiceint = 0;
    int choiceint2 = 0;
    int choiceint3 = 0;
    int choiceint4 = 0;
    string filePath;
    do {
        printMenu(title, choices);
        choiceint = getChoice(1, 6);
        switch (choiceint) {
            case 1:
                printResults(shippingGraph,"SHIPPING GRAPH", true,true, true,false);
                printResults(stadiumGraph,"STADIUM GRAPH", true,true, true,false);
                printResults(tourismGraph,"TOURISM GRAPH", true,true, true,false);
                break;
            case 2:
                do {
                    printMenu(titleMediumGraph, choicesMediumGraph);
                    choiceint2 = getChoice(1, 13);
                    switch (choiceint2) {
                        case 1:
                            manager.loadExtra("25");
                            printResults(manager.getExtraGraph(),"25 EDGES GRAPH", false,true, true,false);
                            break;
                        case 2:
                            manager.loadExtra("50");
                            printResults(manager.getExtraGraph(),"50 EDGES GRAPH", false,true, true,false);
                            break;
                        case 3:
                            manager.loadExtra("75");
                            printResults(manager.getExtraGraph(),"75 EDGES GRAPH", false,true, true,false);
                            break;
                        case 4:
                            manager.loadExtra("100");
                            printResults(manager.getExtraGraph(),"100 EDGES GRAPH", false,true, true,false);
                            break;
                        case 5:
                            manager.loadExtra("200");
                            printResults(manager.getExtraGraph(),"200 EDGES GRAPH", false,true, true,false);
                            break;
                        case 6:
                            manager.loadExtra("300");
                            printResults(manager.getExtraGraph(),"300 EDGES GRAPH", false,true, true,false);
                            break;
                        case 7:
                            manager.loadExtra("400");
                            printResults(manager.getExtraGraph(),"400 EDGES GRAPH", false,true, true,false);
                            break;
                        case 8:
                            manager.loadExtra("500");
                            printResults(manager.getExtraGraph(),"500 EDGES GRAPH", false, true, true,false);
                            break;
                        case 9:
                            manager.loadExtra("600");
                            printResults(manager.getExtraGraph(),"600 EDGES GRAPH", false, true, true,false);
                            break;
                        case 10:
                            manager.loadExtra("700");
                            printResults(manager.getExtraGraph(),"700 EDGES GRAPH", false, true, true,false);
                            break;
                        case 11:
                            manager.loadExtra("800");
                            printResults(manager.getExtraGraph(),"800 EDGES GRAPH", false, true, true,false);
                            break;
                        case 12:
                            manager.loadExtra("900");
                            printResults(manager.getExtraGraph(),"900 EDGES GRAPH", false, true, true,false);
                            break;
                        case 13:
                            break;
                        default:
                            break;
                    }
                } while (choiceint2!=13);
                break;
            case 3:
                do {
                    printMenu(titleRealWorldGraph1, choicesRealWorldGraph);
                    choiceint3 = getChoice(1, 4);
                    switch (choiceint3) {
                        case 1:
                            manager.loadRealWorld("graph1");
                            printResults(manager.getRealWorld(),"REAL WORLD GRAPH 1", false, true, false, true);
                            break;
                        case 2:
                            manager.loadRealWorld("graph2");
                            printResults(manager.getRealWorld(),"REAL WORLD GRAPH 1", false, true, false, true);
                            break;
                        case 3:
                            manager.loadRealWorld("graph3");
                            printResults(manager.getRealWorld(),"REAL WORLD GRAPH 1", false, true, false, true);
                            break;
                        case 4:
                            break;
                        default:
                            break;
                    }
                }while (choiceint3!=4);
                break;
            case 4:
                do {
                    printMenu(titleRealWorldGraph2, choicesRealWorldGraph);
                    choiceint3 = getChoice(1, 4);
                    switch (choiceint3) {
                        case 1:
                            manager.loadRealWorld("graph1");
                            printResults(manager.getRealWorld(),"REAL WORLD GRAPH 1", false, false, true, true);
                            break;
                        case 2:
                            manager.loadRealWorld("graph2");
                            printResults(manager.getRealWorld(),"REAL WORLD GRAPH 1", false, false, true, true);
                            break;
                        case 3:
                            manager.loadRealWorld("graph3");
                            printResults(manager.getRealWorld(),"REAL WORLD GRAPH 1", false, false, true, true);
                            break;
                        case 4:
                            break;
                        default:
                            break;
                    }
                }while (choiceint3!=4);
                break;
            case 5:
                cout << endl;
                cout << "Enter file path: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, filePath);
                if(manager.loadPathGraph(filePath)!=0){ cout << endl;break;}
                do {
                    printMenu(titlePathGraph, choichesPathGraph);
                    choiceint4 = getChoice(1, 6);
                    manager.loadPathGraph(filePath);
                    switch (choiceint4) {
                        case 1:
                            printResults(manager.getPathGraph(),"PATH GRAPH WITH BACKTRACKING", true, false, false,
                                         false);
                            break;
                        case 2:
                            printResults(manager.getPathGraph(),"PATH GRAPH WITH NEAREST NEIGHBOUR", false, true, false,
                                         false);
                            break;
                        case 3:
                            printResults(manager.getPathGraph(),"PATH GRAPH WITH CHRISTOFIDES", false, false, true,
                                         false);
                            break;
                        case 4:
                            printResults(manager.getPathGraph(),"PATH GRAPH WITH NEAREST NEIGHBOUR AND CHRISTOFIDES", false,
                                         true, true,
                                         false);
                            break;
                        case 5:
                            printResults(manager.getPathGraph(),"PATH GRAPH WITH ALL ALGORITHMS", true, true, true,
                                         false);
                            break;
                        case 6:
                            break;
                        default:
                            break;
                    }
                }while (choiceint4!=6);
                break;
            case 6:
                break;
            default:
                break;
        }
    } while (choiceint != 6);

    return 0;
}