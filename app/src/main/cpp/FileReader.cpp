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

//"C:/Users/abg/CLionProjects/BachelorCpp/app/src/main/cpp/adjlist"
using namespace std;

int FileReader::readFile(string path, string strt) {
    adjacencyList adjlst;
    string line;
    ifstream myfile(path);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            if(line =="!"){
                cout << "eof";
                myfile.close();
                return 0;
            }
            istringstream buf(line);
            istream_iterator<string> beg(buf), end;
            vector<string> lineAsTokens(beg, end);

            long long int source;
            long long int dest;
            float weight;
            for(auto& value: lineAsTokens){
                char firstChar = value[0];
                if(firstChar == '#'){
                    source = stoll(value.substr(1,value.size()-1));
                    //cout << source << '\n';
                } else if (firstChar == ';'){
                    dest = stoll(value.substr(1,value.size()-1));
                    //cout << dest << '\n';
                } else if (firstChar == ','){
                    weight = stod(value.substr(1,value.size()-1));
                    cout << "adj pair: "<< source << "->" << dest << "," << weight << " \n";
                }
                //cout << "outside of statements??" << "\n";
                //cout << value;
            }

        }
        myfile.close();
    } else cout << "Error reading file\n";
    return 0;
}
