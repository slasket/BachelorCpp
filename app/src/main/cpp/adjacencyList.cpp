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

int adjacencyList::insertInMaps(adjListCollection &collection, long long int id){
    //if the key doesnt already exsist
    int newId;
    if(collection.longIdToIntID.count(id) ==0){
        collection.longIdToIntID.insert(make_pair(id, collection.idSoFar));
        collection.intIdToLongID.insert(make_pair(collection.idSoFar,id));

        newId = collection.idSoFar;
        collection.idSoFar ++;
    }else{
        newId = collection.longIdToIntID.find(id)->second;
    }
    return newId;
}


void adjacencyList::addEdge(adjListCollection &collection, int source, int dest, double weight) {
    //cout << "sour " << source << " arrsize " << collection.adjlst.size() << "\n";
    if (collection.adjlst.empty() || collection.adjlst.size()-1 < source){
        vector<pair<int,double>> secondVector{};
        collection.adjlst.resize(source+1,  secondVector);
    }
    if(collection.adjlst.size() > source){
        if (collection.adjlst[source].empty()){
            vector<pair<int,double>> secondVector{make_pair(dest,weight)};
            collection.adjlst[source] = secondVector;
            //cout << "first elem of vec is " << dest << "\n";
        } else{
            collection.adjlst[source].push_back(make_pair(dest, weight));
            //cout << "new edge " << dest << "\n";
        }
    }
}

// Print adjacency list representaion ot graph
//this has partly been yoinked
void adjacencyList::printGraph(adjListCollection &collection) {
    cout << "size of adjlist "<< collection.adjlst.size() << endl;
    for (int s = 0; s < collection.adjlst.size(); s++){
        cout << "Node " << s << endl;
        for (auto&  pair: collection.adjlst[s]){
            cout << " dest: " << pair.first << " weight: " << pair.second << endl;
        }
    }
}

vector<long long int> adjacencyList::spVectorToLongId(adjListCollection &collection, vector<int> spList) {
    vector<long long int> vectorWLongs;
    for(auto id: spList){
        long long int newid = collection.intIdToLongID.find(id)->second;
        vectorWLongs.push_back(newid);
    }
    return vectorWLongs;
}

void adjacencyList::addEucildDist(adjListCollection &collection, int source, double euclidDist) {
    collection.euclidDistance.insert(make_pair(source,euclidDist));
}
