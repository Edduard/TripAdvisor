#include "Graph.h"
#include"Algorithm.h"
#include<iostream>
using namespace std;

Graph::~Graph()
{
    //dtor
}


Graph::Graph(){
    //  temp valuse
    int at1, at2;
    int i, j;

    cout<<"\n Number of attractions(vertexes): ";
    cin>>this->graphLength;

    cout<<"\n Number of roads: ";
    cin>>this->roads;

    // fill the matrix
    for(i=1;i<=this->graphLength;i++)
        for(j=1;j<=this->graphLength;j++){
            if (i==j)
                incidenceMatrix[i][j] = 1;
            else
                incidenceMatrix[i][j] = 0;
        }
    printf("\n Enter the attractions and the distance between them:\n");
    for(i=1;i<=this->roads;i++){
        label: cout<<"From: ";
        cin>>at1;
        cout<<"To: ";
        cin>>at2;
        if( at1>this->graphLength || at2>this->graphLength ){
            cout<<"\nYou chose "<< this->graphLength <<" maximum attractions!";
            goto label;
        }
        cout<<"Distance: ";
        cin>>this->incidenceMatrix[at1][at2];
    }
}

void Graph::displayGraph(){
    //  temp valuse
    int i, j;

    for(i=1;i<=this->graphLength;i++)
        for(j=1;j<=this->graphLength;j++)
            cout<<"\n"<<i<<"____"<<incidenceMatrix[i][j]<<"____"<<j;
    }
void Graph::findShortestPathBetween(int atr1, int atr2){
    Algorithm a(this);
    int tail, length, i, k, visited[20], prev[20], distance[20], tempVertex;

    // bfs here
    for(i = 1; i<this->graphLength; i++){
        visited[i] = 0;
        prev [i] = 0;
        distance[i] = 99;
    }
    visited[atr1] = 1;
    distance[atr1] = 0;
    a.enqueue(atr1);
    while ( a.getHead()!=a.getTail() ){
        tempVertex = a.dequeue();
        for( i=1;i<this->graphLength;i++)
            if(incidenceMatrix[tempVertex][i]>0){
                if(!visited[i]){
                    visited[i] = 1;
                    prev[i] = tempVertex;
                    distance[i]=distance[tempVertex]+1;
                    a.enqueue(i);
                }
            }
    }

    for(int i=1;i<=this->roads;i++)
        if(visited[i]);
        else
            cout<<"Cannot apply the algorithm for "<<i;
    cout<<"\n The shortest road is: \n";
    cout<<"Distanta este: "<<a.printPath(prev, atr2, 0);
}

void Graph::setGraphLength(int length){
    this->graphLength = length;
}

int Graph::getGraphLength(){
    return this->graphLength;
}

void Graph::setRoads(int newRoads){
    this->roads = newRoads;
}

int Graph::getRoads(){
    return this->roads;
}

int Graph::getIncidenceMatrix(int x, int y){
    return this->incidenceMatrix[x][y];
}
void Graph::addRoad(int atr1, int dist, int atr2){
    this->roads++;
    this->incidenceMatrix[atr1][atr2] = dist;
}

