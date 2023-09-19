//
// Created by Alexander on 19.09.2023.
//

#ifndef TASK_0_FILEREADER_H
#define TASK_0_FILEREADER_H

#include <string>
#include <fstream>
#include <iostream>

using std::string;
using std::ifstream;

class FileReader {
private:
    string filename;
    ifstream file;
public:
    FileReader(string filename);

    void open();

    void close();

    string getNext();

    bool hasNext();

    void reset();
};


#endif //TASK_0_FILEREADER_H
