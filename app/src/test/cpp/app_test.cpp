/*
 * This C++ source file was generated by the Gradle 'init' task.
 */
#include "chrono"
#include "app.h"
#include <cassert>
#include "adjacencyList.h"
#include <iostream>
#include <tuple>
using namespace std;

enum shortestPathMethods{
    dijkstra = 0,
    astar = 1
};

enum commands{
    makeAdjecencyList,
    runDijkstra
};

void testFileIntoAdjLst() {
    BachelorCpp::createAdjList listMaker;
    adjListCollection adjCol;
    listMaker.createList("C:/Users/aske-/CLionProjects/BachelorCpp/app/src/resources/adjlist", "file", adjCol);
    adjacencyList test;
    test.printGraph(adjCol);
}

void testFileWLongs() {
    BachelorCpp::createAdjList listMaker;
    adjListCollection adjCol;
    listMaker.createList("C:/Users/aske-/CLionProjects/BachelorCpp/app/src/resources/adjlistWLongs", "file",
                                adjCol);
    adjacencyList test;
    test.printGraph(adjCol);
}

void testFileDenmark(){
    BachelorCpp::createAdjList listMaker;
    adjListCollection adjCol;
    //this takes the entirety of denmark and prints it :C
    listMaker.createList("C:/Users/aske-/CLionProjects/BachelorCpp/app/src/resources/denmark", "file", adjCol);
    //insert tests from a -> b in denmark

}

void testMiniDenmarkValues(){
    BachelorCpp::createAdjList listMaker;
    adjListCollection adjCol;
    listMaker.createList("C:/Users/a/CLionProjects/BachelorCpp/app/src/resources/miniDenmark", "file", adjCol);
    //correct distance for a node
    assert(adjCol.adjlst[6761][1].second == 6.184578883958011);
    //node 7256183438(translated into 6761 is connected to 3688196181)
    assert(adjCol.intIdToLongID.find(adjCol.adjlst[6761][0].first)->second == 3688196181);
}

void testVectorImplementation() {
    BachelorCpp::createAdjList listMaker;
    adjListCollection adjCol;
    listMaker.dummyVector(adjCol);
}


void testMaltaSmall(){
    BachelorCpp::createAdjList listMaker;
    adjListCollection adjCol;
    adjacencyList listConveter;
    listMaker.createList("C:/Users/a/CLionProjects/BachelorCpp/app/src/resources/malta", "file", adjCol);

    //short area in malta
    BachelorCpp::shortestPathAlgo shortestPath;
    int from = adjCol.longIdToIntID.find(146885871)->second;
    int to = adjCol.longIdToIntID.find(1498913919)-> second;

    tuple<double,vector<int>> result;
    vector<long long int> idvec;
    result = shortestPath.shortestPath(dijkstra, from ,to,adjCol);
    idvec = listConveter.spVectorToLongId(adjCol, get<1>(result));
    cout << "testing short distance in malta \n" ;
    cout << "from node: 146885871, to node: 1498913919 \n";
    cout << "distance: " << get<0>(result) << "\n";
    cout << "path: ";
    shortestPath.printVec(idvec);
}

void testMaltaLarge(){
    BachelorCpp::createAdjList listMaker;
    adjListCollection adjCol;
    adjacencyList listConveter;
    listMaker.createList("C:/Users/a/CLionProjects/BachelorCpp/app/src/resources/malta", "file", adjCol);

    //short area in malta
    BachelorCpp::shortestPathAlgo shortestPath;

    tuple<double,vector<int>> result;
    vector<long long int> idvec;
    int maltaNorth = adjCol.longIdToIntID.find(3593516725)->second;
    int maltaSouth = adjCol.longIdToIntID.find(5037683804)-> second;
    result = shortestPath.shortestPath(dijkstra,maltaNorth,maltaSouth,adjCol);
    idvec = listConveter.spVectorToLongId(adjCol, get<1>(result));
    cout << "testing long distance in malta \n" ;
    cout << "from node: 3593516725, to node: 5037683804 \n";
    cout << "distance: " << get<0>(result) << "\n";
    cout << "path: ";
    shortestPath.printVec(idvec);
}

void testDijkstraToyExample(){
    BachelorCpp::createAdjList listMaker;

    adjListCollection adjCol;
    listMaker.createList("C:/Users/a/CLionProjects/BachelorCpp/app/src/resources/dijkstraTest","file",adjCol);
    BachelorCpp::shortestPathAlgo shortestPath;
    //testing that all the nodes in the toy graph has the smallest path
    enum toyExampleVals{
        //translation table to values after putting the
        aNode = 0,
        bNode = 1,
        cNode = 3,
        dNode = 4,
        eNode = 2
    };
    tuple<double,vector<int>> result;
    vector<long long int> idvec;
    result = shortestPath.shortestPath(dijkstra,aNode,bNode,adjCol);
    adjacencyList listConveter;
    idvec = listConveter.spVectorToLongId(adjCol, get<1>(result));
    //testing a->b gives path a,e,b with distance 4
    assert(idvec[0] == 0);
    assert(idvec[1] == 4);
    assert(idvec[2] == 1);
    assert(get<0>(result) == 4);

    result = shortestPath.shortestPath(dijkstra,aNode,eNode,adjCol);
    idvec = listConveter.spVectorToLongId(adjCol, get<1>(result));
    assert(idvec[0]==0);
    assert(idvec[1]==4);
    assert(get<0>(result) == 3);

    result = shortestPath.shortestPath(dijkstra,aNode,cNode,adjCol);
    idvec = listConveter.spVectorToLongId(adjCol, get<1>(result));
    assert(idvec[0]==0);
    assert(idvec[1]==4);
    assert(idvec[2]==1);
    assert(idvec[3]==2);
    assert(get<0>(result) == 6);

    result = shortestPath.shortestPath(dijkstra,aNode,dNode,adjCol);
    idvec = listConveter.spVectorToLongId(adjCol, get<1>(result));
    assert(idvec[0]==0);
    assert(idvec[1]==4);
    assert(idvec[2]==3);
    assert(get<0>(result) == 5);
}

void testAStarMapIsFilled(){
    BachelorCpp::createAdjList listMaker;
    adjListCollection adjCol;
    listMaker.createList("C:/Users/a/CLionProjects/BachelorCpp/app/src/resources/aStarTest","file",adjCol);
    //BachelorCpp::shortestPathAlgo shortestPath;
    //testing that all the nodes in the toy graph has the smallest path
    enum toyExampleVals{
        //translation table to values after putting the
        aNode = 0,
        bNode = 1,
        cNode = 3,
        dNode = 4,
        eNode = 2
    };
    //test that the euclidDist has been written correct
    assert(adjCol.euclidDistance.find(aNode)->second == 5.0);
    assert(adjCol.euclidDistance.find(bNode)->second == 9.0);
    assert(adjCol.euclidDistance.find(cNode)->second == 4.0);
    assert(adjCol.euclidDistance.find(dNode)->second == 0.0);
    assert(adjCol.euclidDistance.find(eNode)->second == 3.0);
}

void communicateWithJava() {
    map<string, commands> mapStringToEnum =
            {
                    {"makeAdjecencyList", makeAdjecencyList},
                    {"runDijkstra", runDijkstra}
            };
    string line;
    adjListCollection adjCol;
    while(getline(cin, line)) {
        commands switchType = mapStringToEnum[line];
        adjacencyList listConveter;
        BachelorCpp::createAdjList listMaker;
        switch (switchType) {
            case makeAdjecencyList: {
                listMaker.createList("", "java", adjCol);
                break;
            }
            case runDijkstra: {
                string nodeIdFrom;
                string nodeIdTo;
                cin >> nodeIdFrom;
                cin >> nodeIdTo;
                int from = adjCol.longIdToIntID[stoll(nodeIdFrom)];
                int to = adjCol.longIdToIntID[stoll(nodeIdTo)];
                BachelorCpp::shortestPathAlgo shortestPath;
                tuple<double,vector<int>> result = shortestPath.shortestPath(dijkstra, from, to, adjCol);
                vector<long long int> idvec = listConveter.spVectorToLongId(adjCol, get<1>(result));
                string listOfNodes;
                for(long long int nodeId: idvec) {
                    listOfNodes += " " + to_string(nodeId);
                }
                double distance = get<0>(result);
                cout << listOfNodes << endl;
                break;
            }
        }
    }
    cout << "OutOfLoop error" << endl;
    //BachelorCpp::createAdjList listMaker;
    //adjListCollection adjCol;
    //listMaker.createList("", "java", adjCol);


}
void testDijkstraAdjlist(){
    BachelorCpp::createAdjList listMaker;

    adjListCollection adjCol;
    adjacencyList listConveter;

    listMaker.createList("C:/proj/BachelorCpp/app/src/resources/adjlist","file",adjCol);
    BachelorCpp::shortestPathAlgo shortestPath;

    tuple<double,vector<int>> result; vector<long long int> idvec;
    int start = adjCol.longIdToIntID[1];
    int end = adjCol.longIdToIntID[5];

    result = shortestPath.shortestPath(dijkstra,start,end,adjCol);
    idvec = listConveter.spVectorToLongId(adjCol,get<1>(result));
    shortestPath.printVec(idvec);
}

//test methods
int main() {

    //testFileIntoAdjLst();
    //testVectorImplementation();
    //testFileWLongs();
    //testFileDenmark();
    //testDijkstraAdjlist();
    communicateWithJava();
    //testMiniDenmarkValues();
    //testMiniDenmarkValues();
    //testMaltaSmall();
    //testMaltaLarge();
    //testDijkstraToyExample();
    //testAStarMapIsFilled();
    return 0;
}







