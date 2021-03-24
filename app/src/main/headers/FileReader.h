//
// Created by abg on 22-03-2021.
//

#ifndef BACHELORCPP_FILEREADER_H
#define BACHELORCPP_FILEREADER_H
#include <string>
#include <vector>
#include "adjacencyList.h"

using namespace std;

class FileReader {
public:
    int readFile(string Path, adjListCollection &adjListCollection);
};


#endif //BACHELORCPP_FILEREADER_H
