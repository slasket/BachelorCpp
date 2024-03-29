/*
 * This C++ source file was generated by the Gradle 'init' task.
 */

#include <cstdlib>
#include "app.h"
#include <adjacencyList.h>
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <FileReader.h>
#include <sstream>
#include <chrono>
#include <aStar.h>
#include "dijkstra.h"

using namespace std;
//DO THE STUFF
int main () {
    return 0;
}


int BachelorCpp::createAdjList::createList(string path, string method, adjListCollection &adjListCollection) {
    if (method == "file") {
        FileReader reader;
        reader.readFile(std::move(path), adjListCollection);
    } else if (method == "java") {
        string line;
        bool reading = true;
        while (reading) {
            getline(cin, line);
            adjacencyList listMutator;
            istringstream buf(line);
            istream_iterator<string> beg(buf), end;
            vector<string> lineAsTokens(beg, end);

            int source;
            int dest;
            double weight;
            for (auto &value: lineAsTokens) {
                char firstChar = value[0];
                if (firstChar == '#') {
                    long long int sourceID = stoll(value.substr(1, value.size() - 1));
                    source = listMutator.insertInMaps(adjListCollection, sourceID);
                } else if (firstChar == ';') {
                    long long int destID = stoll(value.substr(1, value.size() - 1));
                    dest = listMutator.insertInMaps(adjListCollection, destID);
                } else if (firstChar == ',') {
                    weight = stod(value.substr(1, value.size() - 1));
                    listMutator.addEdge(adjListCollection, source, dest, weight);
                } else if (firstChar == '!') {
                    cout << "Finished making adjencency list in cpp" << endl;
                    reading = false;
                }
            }
        }
        return 0;
    }
}

int BachelorCpp::createAdjList::dummyVector(adjListCollection &adjListCollection) {
    //cout << "stuff added";
    adjacencyList test;
    cout << "0 -> 1,2 \n";
    test.addEdge(adjListCollection, 0,1,1);
    cout << "1 -> 2,15 \n";
    test.addEdge(adjListCollection,1,2,15);
    cout << "1 -> 4,2 \n";
    test.addEdge(adjListCollection, 1, 4, 2);
    cout << "2 -> 1,1 \n";
    test.addEdge(adjListCollection,2,1,1);
    cout << "print my adj list \n";
    test.printGraph(adjListCollection);
    return 0;
}

tuple<double, vector<int>> BachelorCpp::shortestPathAlgo::shortestPath(int method, int source, int dest, adjListCollection &adjListCollection) {
    //dijkstra=0,astar=1 ect
    switch (method) {
        case 0:
            dijkstra dijkstra;
            return dijkstra.djikstraShortestPath(source,dest,adjListCollection);
        case 1:
            aStar aStar;
            return aStar.aStarShortestPath(source,dest,adjListCollection);
        default:
            cout << "case Unknown";
    }
}

void BachelorCpp::shortestPathAlgo::printVec(vector<long long int> const &input) {
        cout << "[";
        for (long long i : input) {
            cout << i << ' ';
        }
        cout << "]";
}
