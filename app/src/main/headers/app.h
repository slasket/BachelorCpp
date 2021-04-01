/*
 * This C++ source file was generated by the Gradle 'init' task.
 */
#ifndef APP_H
#define APP_H

#include <string>
#include <utility>
#include <vector>
#include "adjacencyList.h"
#include "djikstra.h"

//name spaces for methods
namespace BachelorCpp {
    class createAdjList {
    public:
        int createList(std::string path, std::string method, adjListCollection &adjListCollection);

        int dummyVector(adjListCollection &adjListCollection);
    };
    class shortestPathAlgo{
    public:
        vector<int> shortestPath(int method, int source, int dest, adjListCollection &adjListCollection);
    };
}

#endif
