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
    if (choice.size() > 1) {
        choiceint = 0;
        error = true;
    }
    else {
        try {
            choiceint = stoi(choice);
        }
        catch (const exception& e) {
            choiceint = 0;
            error = true;
        }

        if (!(choiceint >= min && choiceint <= max)) {
            choiceint = 0;
            error = true;
        }
    }

    if (error) {
        cout << "Input not recognized, please insert a number between " << min << " and " << max << "\n";
    }

    return choiceint;
}

void printMenu(string &title , vector<string> &options){
    if(title.size() > MENU_WIDTH-2)
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

void printResults(Graph graph, const string& title1){
    Manager temp;

    printSectionTitle(title1);
    vector<int> tour1;

    cout << "->Backtracking" << endl;
    auto dist1 = backtracking(graph, tour1);
    printTour(tour1, dist1);
    cout << endl;
    cout << endl;

    cout << "->Nearest Neighbour" << endl;
    auto tour2 = nearestNeighbor(graph.getVertexSet()[0], graph);
    auto dist2 = getDistance(graph,tour2, false, temp);
    printTour(tour2, dist2);

    cout << endl;
    cout << endl;

    cout << "->Christofides Algorithm" << endl;
    auto tour3 = Christofides_algorithm(graph);
    auto dist3 = getDistance(graph, tour2, false, temp);
    printTour(tour3, dist3);
}


int main() {
    Manager manager;
    manager.loadShipping();
    manager.loadStadiums();
    manager.loadTourism();
    //manager.loadExtra("200");
    //manager.loadPathGraph("./data/extra/edges_25.csv");
    Graph shippingGraph = manager.getShippingGraph();
    Graph stadiumGraph = manager.getStadiumsGraph();
    Graph tourismGraph = manager.getTourismGraph();

    string title= "Railway Network Manager";
    vector<string> choices = {
            "SHOW TOY GRAPHS ANALYTICS",
            "SHOW MEDIUM GRAPHS ANALYTICS",
            "Select Real-World graph with neareast neighbor",
            "Select Real-World graph with Christofides algorithm",
            "Quit"
    };

    int choiceint = 0;
    do {
        printMenu(title, choices);
        choiceint = getChoice(1, 5);
        switch (choiceint) {
            case 1:
                printResults(shippingGraph, "SHIPPING GRAPH");
                printResults(stadiumGraph, "STADIUM GRAPH");
                printResults(tourismGraph, "TOURISM GRAPH");
                cout << endl;
                for(int i=0; i< MENU_WIDTH; i++){cout << "=";}
                cout << endl;
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            default:
                break;
        }
    } while (choiceint != 5);

    while (true){};
    return 0;
}