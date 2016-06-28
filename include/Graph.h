#ifndef GRAPH_H
#define GRAPH_H


class Graph
{
    int incidenceMatrix[20][20];
    int graphLength;
    int roads;

    public:
        virtual ~Graph();

        Graph();
        void displayGraph();
        void findShortestPathBetween(int, int);

        void setGraphLength(int);
        int getGraphLength();
        void addRoad(int, int, int);

        int getIncidenceMatrix(int, int);
        void setRoads(int);
        int getRoads();

    protected:

    private:
};

#endif // GRAPH_H
