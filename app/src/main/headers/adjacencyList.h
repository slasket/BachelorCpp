//
// Created by abg on 22-03-2021.
//

#ifndef BACHELORCPP_ADJACENCYLIST_H
#define BACHELORCPP_ADJACENCYLIST_H


#include <vector>

class adjacencyList {
public:
    void addEdge(std::vector <std::pair<int, int>> adjlst[], int source, int dest, int weigth);
    //void addEdge(std::vector<int, int> *adjlst, int source, int dest, int weigth);

    void printGraph(std::vector<std::pair<int,int>> adj[], int V);
};


#endif //BACHELORCPP_ADJACENCYLIST_H
