//
// Created by abg on 22-03-2021.
//

#include "adjacencyList.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    vector<pair<int,int>> adjlst;
    return 0;

}


void adjacencyList::addEdge(std::vector<std::pair<int, int>> *adjlst, int source, int dest, int weigth) {
    adjlst[source].emplace_back(dest, weigth);

    //otherway
    //adj[dest].push_back(make_pair(source, weigth));

}

// Print adjacency list representaion ot graph
//this has been yoinked

void adjacencyList::printGraph(std::vector<std::pair<int, int>> *adj, int V) {
    int v, w;
    for (int u = 0; u < V; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}
