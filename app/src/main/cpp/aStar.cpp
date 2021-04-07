//
// Created by a on 07-04-2021.
//

#include <aStar.h>
#include "adjacencyList.h"
#include <vector>
#include <queue>
#include <string>
#include <tuple>
#include "aStar.h"

using namespace std;

typedef pair<int,double> idWPair;

struct comparator{
    constexpr bool operator()(
            pair<int, double> const& a,
            pair<int, double> const& b)
    const noexcept
    {
        return a.second > b.second;
    }
};

vector<int> createList(vector<int> prevNode, int source, int destination){
    int temdest = destination;
    vector<int> shortestPath;
    while (temdest != source){
        shortestPath.push_back(temdest);
        temdest = prevNode[temdest];
    }
    shortestPath.push_back(source);
    reverse(shortestPath.begin(),shortestPath.end());
    return shortestPath;
}


tuple<double, vector<int>> aStar::aStarShortestPath(int source, int dest, adjListCollection &adjListCollection) {
    const double INF = 999999999999;
    int sizeOfGraph = adjListCollection.intIdToLongID.size();
   //initilaize distance from source to everything to infinity
    //distance from source to source to 0
    vector<double> distance(sizeOfGraph,INF);
    distance[source] = 0;
    //has the node been seen vector
    vector<bool> nodeSeen(sizeOfGraph,false);
    nodeSeen[source] = true;
    //path from source to destination
    vector<int> prevNode(sizeOfGraph,-1);
    //prevNode[source] = -1;
    //heap of nodes to evaluate
    priority_queue<pair<int,double>, vector<pair<int,double>>, comparator> minHeap;
    double sourceHeuristic = adjListCollection.euclidDistance.find(source)->second;
    minHeap.push(make_pair(source,0.0+sourceHeuristic));

   while (!minHeap.empty()){
        //pop the top element
        pair<int,double> head = minHeap.top();
        minHeap.pop();
        int headId = head.first;
       //Have we reached destination check
        if (head.first==dest){
            //we have arrived at destination and we are done
            //cout << "we have hit destination \n";
            break;
        }
       //add new nodes to queue
        for(auto i: adjListCollection.adjlst[headId]){
            int node = i.first;
            double weight = i.second;
            double heuristicWeight = adjListCollection.euclidDistance.find(node)->second;
           //relaxation step, in astar we add the heuristic weight in to consideration
            if(!nodeSeen[node] && (distance[headId]+weight+heuristicWeight) < distance[node]){
                //update the distance to the node and add it to the queue
                distance[node] = distance[headId]+weight;
                prevNode[node] = headId; //remember the node before for finding the shortest path to destination
                //add the heuristic to the weight so we sort based on it.
                minHeap.push(make_pair(node,distance[node]+heuristicWeight));
            }
        }
        //mark head as it has been seen and cant be considered again
        nodeSeen[headId] = true;
    }
    vector<int> path = createList(prevNode,source,dest);
    return make_tuple(distance[dest],path);
}
