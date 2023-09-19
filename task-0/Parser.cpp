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

    std::regex r("[[:alnum:]']+");
    std::sregex_iterator i(line.begin(), line.end(), r);
    std::sregex_iterator end;
    while (i != end) {
        string word = i->str();
        toLower(word);
        words.push_front(toLower(word));
        i++;
    }

    return words;
}
