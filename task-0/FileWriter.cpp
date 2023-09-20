//
// Created by Alexander on 19.09.2023.
//

#include "FileWriter.h"

#define CSV_HEADER "word,absFrequency,relFrequency"

FileWriter::FileWriter(string filename) {
    this->filename = filename;
}

void FileWriter::open() {
    file.open(filename);
}

void FileWriter::close() {
    file.close();
}

void FileWriter::writeFrequencyList(FrequencyList* frequencyList) {
    std::vector<std::pair<string, int>> sortedList = frequencyList->getSortedList();
    int wordCount = frequencyList->getWordCount();

    file << CSV_HEADER << "\n";
    for (auto const &pair : sortedList) {
        string word = pair.first;
        int absFrequency = pair.second;
        float relFrequency = 100 * (float)absFrequency/wordCount;

        file << word << "," << absFrequency << "," << relFrequency << "\n";
    }
}
