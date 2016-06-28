#include "Graph.h"
#include<iostream>
using namespace std;

int main(){
    Graph G1;
    G1.displayGraph();
    G1.addRoad(4,2,2);
    G1.findShortestPathBetween(1,3);

    return 0;
}
