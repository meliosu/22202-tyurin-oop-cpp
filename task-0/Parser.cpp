//
// Created by Alexander on 19.09.2023.
//

#include "Parser.h"

void Parser::toLower(string& word) {
    for (auto &c : word) {
        c = std::tolower(c);
    }
}

std::list<string> Parser::parse(string line) {
    std::list<string> words = {};

    int i = 0;
    int j = 0;
    while (j <= line.size()) {
        if (std::isalnum(line[j])) {
            j++;
            continue;
        }

        if (i == j) {
            i++;
            j++;
            continue;
        }

        string word = line.substr(i, j - i);
        toLower(word);
        words.push_front(word);

        i = j;
    }

    return words;
}
