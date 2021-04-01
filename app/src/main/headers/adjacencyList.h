//
// Created by abg on 22-03-2021.
//

#ifndef BACHELORCPP_ADJACENCYLIST_H
#define BACHELORCPP_ADJACENCYLIST_H
#include <vector>
#include <map>

struct adjListCollection{
    int idSoFar=0;
    std::map<long long int, int> longIdToIntID{};
    std::map<int, long long int> intIdToLongID{};
    std::vector<std::vector<std::pair<int, double>>> adjlst{};
};

class adjacencyList {
public:
    void addEdge(adjListCollection &collection, int source, int dest, double weight);
    //void addEdge(std::vector<int, int> *adjlst, int source, int dest, int weigth);

    void printGraph(adjListCollection &collection);

    int insertInMaps(adjListCollection &collection, long long int id);
    std::vector<long long int> spVectorToLongId(adjListCollection &collection, std::vector<int> spList);
};




#endif //BACHELORCPP_ADJACENCYLIST_H
