//
// Created by Alexander on 19.09.2023.
//

#include "FrequencyList.h"

FrequencyList::FrequencyList() {
    frequencyMap = {};
    wordCount = 0;
}

void FrequencyList::addWord(string word) {
    frequencyMap[word]++;
    wordCount++;
}

int FrequencyList::getWordCount() {
    return wordCount;
}

std::list<std::pair<string, int>> FrequencyList::getSortedList() {
    std::list<std::pair<string, int>> sortedList = {};
    for (auto pair : frequencyMap) {
        sortedList.push_front(std::pair<string, int>(pair.first, pair.second));
    }

    sortedList.sort([](std::pair<string, int> w1, std::pair<string, int> w2){
        return w1.second > w2.second;
    });

    return sortedList;
}
