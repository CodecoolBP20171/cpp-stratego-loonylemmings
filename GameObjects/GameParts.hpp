//
// Created by jeannie on 2017.11.12..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_GAMEPARTS_HPP
#define CPP_STRATEGO_LOONYLEMMINGS_GAMEPARTS_HPP

#include "Player.hpp"
#include "Card.hpp"

class GameParts {

public:

    GameParts() {
        p1stash.fill(nullptr);
        p2stash.fill(nullptr);
        board.fill(nullptr);

        selected = -1;
        stash = &p1stash;

        okBtn = true;
        resetBtn = true;
        restartBtn = true;
    }

    virtual ~GameParts() {}

    std::array<Card*, 40> p1stash;
    std::array<Card*, 40> p2stash;
    std::array<Card*, 100> board;

    int selected;
    std::array<Card*, 40>* stash;

    bool okBtn;
    bool resetBtn;
    bool restartBtn;
};

#endif //CPP_STRATEGO_LOONYLEMMINGS_GAMEPARTS_HPP
