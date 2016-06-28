#include "Algorithm.h"
#include<iostream>
using namespace std;

Algorithm::Algorithm(Graph* G){
    this->g = G;
    this->tail = 1;
    this->head = 1;
}

Algorithm::~Algorithm()
{
    //dtor
}

int Algorithm::printPath(int prev[], int atr2, int sum){
    if(prev[atr2]!=0)
        sum = sum + this->printPath(prev, prev[atr2], this->g->getIncidenceMatrix(prev[atr2],atr2));
    cout<<atr2<<" ";
    return sum;
}

void Algorithm::enqueue(int x){
    this->queue[this->tail] = x;
    this->tail++;
}

int Algorithm::dequeue(){
    int x;
    x = this->queue[this->head];
    this->head++;
    return x;
}

int Algorithm::getHead(){
    return this->head;
}

int Algorithm::getTail(){
    return this->tail;
}

