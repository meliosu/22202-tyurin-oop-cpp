//
// Created by Alexander on 25.10.2023.
//

#ifndef TASK_2_STATE_H
#define TASK_2_STATE_H

#include <vector>

class State {
private:
    bool** cells;

public:
    State();

    State(std::vector<int, int> cell_coords);

    std::vector<int, int> get_cells();
};


#endif //TASK_2_STATE_H
