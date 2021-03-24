//
// Created by abg on 22-03-2021.
//

#include <FileReader.h>
#include <adjacencyList.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iterator>
#include <map>

//"C:/Users/abg/CLionProjects/BachelorCpp/app/src/main/cpp/adjlist"
using namespace std;

int idSoFar = 0;
map<long long int, int> longIdToIntID;
map<int, long long int> intIdToLongID;


int insertInMaps(long long int id){
    //if the key doesnt already exsist
    int newId;
    if(longIdToIntID.count(id) ==0){

        longIdToIntID.insert(make_pair(id, idSoFar));

        intIdToLongID.insert(make_pair(idSoFar,id));

        newId = idSoFar;
        idSoFar ++;
    }else{
        newId = longIdToIntID.find(id)->second;
    }
    return newId;
}


int FileReader::readFile(string path, vector<vector<pair<int, double>>> &adjlst) {
    adjacencyList listMutator;

    string line;
    ifstream myfile(path);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            if(line =="!"){
                //cout << "eof";
                myfile.close();
                return 0;
            }
            istringstream buf(line);
            istream_iterator<string> beg(buf), end;
            vector<string> lineAsTokens(beg, end);

            int source;
            int dest;
            double weight;
            for(auto& value: lineAsTokens){
                char firstChar = value[0];
                if(firstChar == '#'){
                    long long int sourceID = stoll(value.substr(1,value.size()-1));
                    source = insertInMaps(sourceID);
                    //cout << source << '\n';
                } else if (firstChar == ';'){
                    long long int destID = stoll(value.substr(1,value.size()-1));
                    dest = insertInMaps(destID);
                    //cout << dest << '\n';
                } else if (firstChar == ','){
                    weight = stod(value.substr(1,value.size()-1));
                    //cout << "adj pair: "<< source << "->" << dest << "," << weight << " \n";
                    listMutator.addEdge(adjlst,source, dest,weight);
                }
                //cout << "outside of statements??" << "\n";
                //cout << value;
            }

        }
        myfile.close();
    } else cout << "Error reading file\n";
    return 0;
}


