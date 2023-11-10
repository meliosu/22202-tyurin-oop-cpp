//
// Created by Alexander on 25.10.2023.
//

#ifndef TASK_2_RULE_H
#define TASK_2_RULE_H

#include <string>
#include <vector>

class Rule {
private:
    std::string rule;

public:
    Rule(std::string rule);

    // return 2 x 9 table, each table element tells if a cell with n neighbours
    // lives, dies or is created
    std::vector<std::vector<bool>> get_transition_table() const;
};


#endif //TASK_2_RULE_H
