//
// Created by Alexander on 19.09.2023.
//

#ifndef TASK_0_FILEWRITER_H
#define TASK_0_FILEWRITER_H

#include <string>
#include <list>
#include <fstream>
#include <format>
#include "FrequencyList.h"

using std::string;
using std::ofstream;

class FileWriter {
private:
    string filename;
    ofstream file;
public:
    FileWriter(string filename);

    void open();

    void close();

    void writeFrequencyList(FrequencyList frequencyList);
};


#endif //TASK_0_FILEWRITER_H
