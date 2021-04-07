//
// Created by a on 07-04-2021.
//

#ifndef BACHELORCPP_ASTAR_H
#define BACHELORCPP_ASTAR_H
#include<iostream>
#include<vector>
#include<set>
#include<tuple>
#include "adjacencyList.h"

using namespace std;
class aStar {
public:
    tuple<double, vector<int>> aStarShortestPath(int source, int dest, adjListCollection &adjListCollection);
};


#endif //BACHELORCPP_ASTAR_H
