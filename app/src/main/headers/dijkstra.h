//
// Created by a on 31-03-2021.
//

#ifndef BACHELORCPP_DIJKSTRA_H
#define BACHELORCPP_DIJKSTRA_H
#include<iostream>
#include<vector>
#include<set>
#include<tuple>
#include "adjacencyList.h"


using namespace std;
class dijkstra {
public:
    tuple<double, vector<int>> djikstraShortestPath(int source, int dest, adjListCollection &adjListCollection);
};


#endif //BACHELORCPP_DIJKSTRA_H
