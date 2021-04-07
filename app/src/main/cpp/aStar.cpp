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
tuple<double, vector<int>> aStar::aStarShortestPath(int source, int dest, adjListCollection &adjListCollection) {
    //const double INF = 999999999999;
    //int sizeOfGraph = adjListCollection.intIdToLongID.size();

    ////initilaize distance from source to everything to infinity
    ////distance from source to source to 0
    //vector<double> distance(sizeOfGraph,INF);
    //distance[source] = 0;
    ////has the node been seen vector
    //vector<bool> nodeSeen(sizeOfGraph,false);
    //nodeSeen[source] = true;
    ////path from source to destination
    //vector<int> prevNode(sizeOfGraph,-1);
    ////prevNode[source] = -1;

    ////heap of nodes to evaluate
    //priority_queue<pair<int,double>, vector<pair<int,double>>, comparator> minHeap;
    //minHeap.push(make_pair(source,0.0));

    //while (!minHeap.empty()){
    //    //pop the top element
    //    pair<int,double> head = minHeap.top();
    //    minHeap.pop();
    //    int headId = head.first;

    //    //Have we reached destination check
    //    if (head.first==dest){
    //        //we have arrived at destination and we are done
    //        //cout << "we have hit destination \n";
    //        break;
    //    }

    //    //add new nodes to queue
    //    for(auto i: adjListCollection.adjlst[headId]){
    //        int node = i.first;
    //        double weight = i.second;

    //        //relaxation step
    //        if(!nodeSeen[node] && (distance[headId]+weight) < distance[node]){
    //            //update the distance to the node and add it to the queue
    //            distance[node] = distance[headId]+weight;
    //            prevNode[node] = headId; //remember the node before for finding the shortest path to destination
    //            minHeap.push(make_pair(node,distance[node]));
    //        }
    //    }
    //    //mark head as it has been seen and cant be considered again
    //    nodeSeen[headId] = true;
    //}
    //vector<int> path = createSPList(prevNode,source,dest);
    //return make_tuple(distance[dest],path);
    vector<int> res;
    res.push_back(1);
    return std::make_tuple(0.0,res);
}
