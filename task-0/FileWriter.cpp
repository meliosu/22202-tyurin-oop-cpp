//
// Created by Alexander on 19.09.2023.
//

#include "FileWriter.h"

FileWriter::FileWriter(string filename) {
    this->filename = filename;
}

void FileWriter::open() {
    file.open(filename);
}

void FileWriter::close() {
    file.close();
}

void FileWriter::writeVec(const std::vector<string>& strings, char delim) {
    for (int i = 0; i < strings.size() - 1; i++) {
        file << strings[i] << delim;
    }

    file << strings[strings.size() - 1] << '\n';
}
