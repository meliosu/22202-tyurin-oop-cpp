//
// Created by Alexander on 19.09.2023.
//

#ifndef TASK_0_FREQUENCYLIST_H
#define TASK_0_FREQUENCYLIST_H

#include <unordered_map>
#include <list>
#include <string>

using std::string;

class FrequencyList {
private:
    std::unordered_map<string, int>  frequencyMap;
    int wordCount;
public:
    FrequencyList();

    void addWord(string word);

    int getWordCount();

    std::list<std::pair<string, int>> getSortedList();
};


#endif //TASK_0_FREQUENCYLIST_H
