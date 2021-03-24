//
// Created by abg on 22-03-2021.
//

#ifndef BACHELORCPP_FILEREADER_H
#define BACHELORCPP_FILEREADER_H
#include <string>
#include <vector>

using namespace std;

class FileReader {
public:
    int readFile(string Path, vector<vector<pair<int, double>>> &adjlst);
};


#endif //BACHELORCPP_FILEREADER_H
