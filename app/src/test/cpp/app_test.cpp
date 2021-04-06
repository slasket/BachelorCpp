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
    djikstra = 0,
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
    result = shortestPath.shortestPath(djikstra, from ,to,adjCol);
    idvec = listConveter.spVectorToLongId(adjCol, get<1>(result));
    cout << "testing short distance in malta \n" ;
    cout << "from node: 146885871, to node: 1498913919 \n";
    cout << "distance: " << get<0>(result) << "\n";
    cout << "path: ";
    shortestPath.printVec(idvec);
    cout << "\n";

    int maltaNorth = adjCol.longIdToIntID.find(3593516725)->second;
    int maltaSouth = adjCol.longIdToIntID.find(5037683804)-> second;
    result = shortestPath.shortestPath(djikstra,maltaNorth,maltaSouth,adjCol);
    idvec = listConveter.spVectorToLongId(adjCol, get<1>(result));
    cout << "testing long distance in malta \n" ;
    cout << "from node: 3593516725, to node: 5037683804 \n";
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
    result = shortestPath.shortestPath(djikstra,maltaNorth,maltaSouth,adjCol);
    idvec = listConveter.spVectorToLongId(adjCol, get<1>(result));
    cout << "testing long distance in malta \n" ;
    cout << "from node: 3593516725, to node: 5037683804 \n";
    cout << "distance: " << get<0>(result) << "\n";
    cout << "path: ";
    shortestPath.printVec(idvec);
}

void testDjikstraToyExample(){
    BachelorCpp::createAdjList listMaker;

    adjListCollection adjCol;
    listMaker.createList("C:/Users/a/CLionProjects/BachelorCpp/app/src/resources/djikstraTest","file",adjCol);
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
    result = shortestPath.shortestPath(djikstra,aNode,bNode,adjCol);
    adjacencyList listConveter;
    idvec = listConveter.spVectorToLongId(adjCol, get<1>(result));
    //testing a->b gives path a,e,b with distance 4
    assert(idvec[0] == 0);
    assert(idvec[1] == 4);
    assert(idvec[2] == 1);
    assert(get<0>(result) == 4);

    result = shortestPath.shortestPath(djikstra,aNode,eNode,adjCol);
    idvec = listConveter.spVectorToLongId(adjCol, get<1>(result));
    assert(idvec[0]==0);
    assert(idvec[1]==4);
    assert(get<0>(result) == 3);

    result = shortestPath.shortestPath(djikstra,aNode,cNode,adjCol);
    idvec = listConveter.spVectorToLongId(adjCol, get<1>(result));
    assert(idvec[0]==0);
    assert(idvec[1]==4);
    assert(idvec[2]==1);
    assert(idvec[3]==2);
    assert(get<0>(result) == 6);


    result = shortestPath.shortestPath(djikstra,aNode,dNode,adjCol);
    idvec = listConveter.spVectorToLongId(adjCol, get<1>(result));
    assert(idvec[0]==0);
    assert(idvec[1]==4);
    assert(idvec[2]==3);
    assert(get<0>(result) == 5);
}

void communicateWithJava() {
    map<string, commands> mapStringToEnum =
            {
                    {"makeAdjecencyList", makeAdjecencyList},
                    {"runDijkstra", runDijkstra}
            };
    string line;
    while(getline(cin, line)) {
        commands switchType = mapStringToEnum[line];
        switch (switchType) {
            case makeAdjecencyList: {
                BachelorCpp::createAdjList listMaker;
                adjListCollection adjCol;
                listMaker.createList("", "java", adjCol);
                break;
            }
            case runDijkstra: {
                //do stuff
                cout << "Test" << endl;
                break;
            }
        }
    }
    cout << "OutOfLoop error" << endl;
    //BachelorCpp::createAdjList listMaker;
    //adjListCollection adjCol;
    //listMaker.createList("", "java", adjCol);


}


//test methods
int main() {

    //testFileIntoAdjLst();
    //testVectorImplementation();
    //testFileWLongs();
    //testFileDenmark();
    //communicateWithJava();
    //testMiniDenmarkValues();
    //testMiniDenmarkValues();
    testMaltaSmall();
    testMaltaLarge();
    testDjikstraToyExample();
    return 0;
}







