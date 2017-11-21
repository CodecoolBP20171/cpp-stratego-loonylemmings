//
// Created by jeannie on 2017.11.12..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_GAME_H
#define CPP_STRATEGO_LOONYLEMMINGS_GAME_H

#include <memory>
#include <bits/unique_ptr.h>
#include <bits/shared_ptr.h>

#include "../GameObjects/Player.hpp"
#include "../GameObjects/Card.hpp"
#include "../GameObjects/GameParts.hpp"
#include "../Graphics/Display.hpp"
#include "../Graphics/UserInput.hpp"

class Game {

public:
    Game();
    virtual ~Game();

    void setDisplay(std::shared_ptr<Display> screen) { display = screen; }
    void setInput(std::shared_ptr<UserInput> user) { input = user; }

    void start();

private:
    std::shared_ptr<Display> display;
    std::shared_ptr<UserInput> input;

    Player player1;
    Player player2;
    std::shared_ptr<GameParts> gameObjects;

    void fillStashes();
};


#endif //CPP_STRATEGO_LOONYLEMMINGS_GAME_H
