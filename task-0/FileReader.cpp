//
// Created by Alexander on 19.09.2023.
//

#include "FileReader.h"

FileReader::FileReader(std::string filename) {
    this->filename = filename;
}

void FileReader::open() {
    file.open(filename);
}

void FileReader::close() {
    file.close();
}

bool FileReader::hasNext() {
    return !file.eof();
}

string FileReader::getNext() {
    if (!hasNext()) {
        return "";
    }

    std::string next_line;
    std::getline(file, next_line);
    return next_line;
}

void FileReader::reset() {
    file.seekg(std::ios_base::beg);
}
