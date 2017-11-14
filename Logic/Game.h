//
// Created by jeannie on 2017.11.12..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_GAME_H
#define CPP_STRATEGO_LOONYLEMMINGS_GAME_H

#include "../GameObjects/Player.hpp"
#include "../GameObjects/Card.hpp"
#include "../GameObjects/GameParts.hpp"
#include "../Graphics/Display.hpp"
#include "../Graphics/UserInput.hpp"

class Game {

public:
    Game();
    virtual ~Game();

    void setDisplay(Display* screen) { display = screen; }
    void setInput(UserInput* user) { input = user; }

    void start();

private:
    Display* display;
    UserInput* input;

    void fillStashes();
};


#endif //CPP_STRATEGO_LOONYLEMMINGS_GAME_H
