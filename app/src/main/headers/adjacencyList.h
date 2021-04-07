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
    std::map<int, double> euclidDistance;
};

class adjacencyList {
public:
    void addEdge(adjListCollection &collection, int source, int dest, double weight);

    void addEucildDist(adjListCollection &collection, int source, double euclidDist);

    void printGraph(adjListCollection &collection);

    int insertInMaps(adjListCollection &collection, long long int id);

    std::vector<long long int> spVectorToLongId(adjListCollection &collection, std::vector<int> spList);

    int getIntID(adjListCollection &collection, long long int value);

    long long int getLongID(adjListCollection &collection, int value);
};




#endif //BACHELORCPP_ADJACENCYLIST_H
