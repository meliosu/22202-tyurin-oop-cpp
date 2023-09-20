//
// Created by Alexander on 19.09.2023.
//

#include "Parser.h"

string Parser::toLower(string word) {
    for (int i = 0; i < word.size(); i++) {
        word[i] = std::tolower(word[i]);
    }

    return word;
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

        words.push_front(toLower(line.substr(i, j - i)));

        i = j;
    }

    return words;
}
