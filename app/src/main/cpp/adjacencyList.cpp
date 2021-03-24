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


void adjacencyList::addEdge(vector<vector<pair<int, double>>> &adjlst, int source, int dest, double weigth) {
    //cout << "sour " << source << " arrsize " << adjlst.size() << "\n";
    if (adjlst.empty() || adjlst.size()-1 < source){
        vector<pair<int,double>> secondVector{};
        adjlst.resize(source+1,  secondVector);
    }
    if(adjlst.size() > source){
        if (adjlst[source].empty()){
            vector<pair<int,double>> secondVector{make_pair(dest,weigth)};
            adjlst[source] = secondVector;
            //cout << "first elem of vec is " << dest << "\n";
        } else{
            adjlst[source].push_back(make_pair(dest, weigth));
            //cout << "new edge " << dest << "\n";
        }
    }
}

// Print adjacency list representaion ot graph
//this has partly been yoinked
void adjacencyList::printGraph(vector<vector<pair<int, double>>> &adjlst) {
    cout << "size of adjlist "<< adjlst.size() << "\n";
    for (int s = 0; s < adjlst.size(); s++){
        cout << "Node " << s << " -> \n";
        for (auto&  pair: adjlst[s]){
            cout << " dest: " << pair.first << " weight: " << pair.second << "\n";
        }
    }
}
