//
// Created by Alexander on 19.09.2023.
//

#ifndef TASK_0_PARSER_H
#define TASK_0_PARSER_H

#include <list>
#include <string>

using std::string;

class Parser {
private:
    // converts all letters in a string to lowercase
    string toLower(string word);
public:
    // converts a string to a list of words
    std::list<string> parse(string line);
};


#endif //TASK_0_PARSER_H
