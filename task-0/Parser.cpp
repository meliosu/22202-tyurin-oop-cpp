//
// Created by Alexander on 19.09.2023.
//

#include "Parser.h"

std::list<string> Parser::parse(const string& line) {
    std::list<string> words = {};

    int word_len = 0;
    string word;
    for (const char& c : line) {
        if (std::isalnum(c)) {
            word += std::tolower(c);
            word_len++;
        }

        if (!std::isalnum(c) && word_len != 0) {
            words.push_back(word);
            word_len = 0;
            word.clear();
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}
