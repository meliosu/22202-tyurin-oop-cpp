//
// Created by Alexander on 25.10.2023.
//

#ifndef TASK_2_RULE_H
#define TASK_2_RULE_H

#include <string>

class Rule {
private:
    std::string rule;

public:
    Rule(std::string rule);

    // return 2 x 9 table, each table element tells if a cell with n neighbours
    // lives, dies or is created
    bool** get_transition_table();
};


#endif //TASK_2_RULE_H
