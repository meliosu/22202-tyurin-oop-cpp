//
// Created by Alexander on 25.10.2023.
//

#ifndef TASK_2_GAME_H
#define TASK_2_GAME_H

#include <string>

#include "State.h"
#include "Rule.h"
#include "Renderer.h"

class Game {
private:
    State state;
    Rule rule;
    Renderer renderer;
    std::string universe_name;
    int tick_count;

    void update();

    void render();

public:
    Game();

    Game(std::string filename);

    void tick(int n = 1);

    void dump(std::string filename);

    void help();
};


#endif //TASK_2_GAME_H
