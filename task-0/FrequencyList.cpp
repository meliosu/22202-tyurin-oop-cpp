//
// Created by Alexander on 19.09.2023.
//

#include "FrequencyList.h"

FrequencyList::FrequencyList() {
    frequencyMap = {};
    wordCount = 0;
}

void FrequencyList::addWord(const string& word) {
    frequencyMap[word]++;
    wordCount++;
}

int FrequencyList::getWordCount() {
    return wordCount;
}

std::vector<pair<string, int>> FrequencyList::getSortedList() {
    std::vector<pair<string, int>> sortedList = {};
    sortedList.resize(frequencyMap.size());
    std::copy(frequencyMap.begin(), frequencyMap.end(), sortedList.begin());

    std::sort(sortedList.begin(), sortedList.end(),
              [](const pair<string, int>& w1, const pair<string, int>& w2){
        return w1.second > w2.second;
    });

    return sortedList;
}
