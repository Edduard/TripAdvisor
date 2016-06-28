#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "Graph.h"

class Algorithm
{
    int tail, head, queue[20];
    Graph *g;

    public:
        Algorithm(Graph*);
        virtual ~Algorithm();

        int printPath(int[], int, int);
        int getTail();
        int getHead();

        void enqueue(int);
        int dequeue();

    protected:

    private:
};

#endif // ALGORITHM_H
