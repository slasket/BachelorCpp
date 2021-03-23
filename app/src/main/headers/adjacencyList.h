//
// Created by abg on 22-03-2021.
//

#ifndef BACHELORCPP_ADJACENCYLIST_H
#define BACHELORCPP_ADJACENCYLIST_H
#include <vector>
using namespace std;
class adjacencyList {
public:
    void addEdge(vector<vector<pair<int, int>>> &adjlst, int source, int dest, int weigth);
    //void addEdge(std::vector<int, int> *adjlst, int source, int dest, int weigth);

    void printGraph(vector<vector<pair<int, int>>> &adjlst);
};


#endif //BACHELORCPP_ADJACENCYLIST_H
