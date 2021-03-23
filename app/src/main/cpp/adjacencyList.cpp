//
// Created by abg on 22-03-2021.
//

#include "adjacencyList.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

int main() {
    return 0;

}


void adjacencyList::addEdge(vector<vector<pair<int, int>>> &adjlst, int source, int dest, int weigth) {
    adjlst[source].push_back(make_pair(dest, weigth));
    //otherway
    //adj[dest].push_back(make_pair(source, weigth));
}

// Print adjacency list representaion ot graph
//this has been yoinked
void adjacencyList::printGraph(vector<vector<pair<int, int>>> &adjlst) {
    cout << adjlst.size();
    for (int s = 0; s < adjlst.size()-1; s++){
        cout << "Node " << s << " makes an edge with \n";
        for (auto&  pair: adjlst[s]){
            cout << "Node " << s << " -> " << pair.first << "weight: " << pair.second << "\n";
        }
        cout << "\n";
    }
}
