//
// Created by jeannie on 2017.11.12..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_GAMEPARTS_HPP
#define CPP_STRATEGO_LOONYLEMMINGS_GAMEPARTS_HPP

#include <memory>
#include <bits/unique_ptr.h>
#include <bits/shared_ptr.h>

#include "Player.hpp"
#include "Card.hpp"

class GameParts {

public:

    GameParts() {

        for (auto i = 0; i<40; i++) {
            p1stash[i].reset();
            p2stash[i].reset();
            board[i].reset();
        }

        for (auto i = 40; i<100; i++) {
            board[i].reset();
        }

        selected = -1;

        okBtn = true;
        resetBtn = true;
        restartBtn = true;
    }

    virtual ~GameParts() {}

    std::array<std::unique_ptr<Card>, 40> p1stash;
    std::array<std::unique_ptr<Card>, 40> p2stash;
    std::array<std::unique_ptr<Card>, 100> board;

    int selected;
    std::shared_ptr<std::array<std::unique_ptr<Card>, 40>> stash;

    bool okBtn;
    bool resetBtn;
    bool restartBtn;
};

#endif //CPP_STRATEGO_LOONYLEMMINGS_GAMEPARTS_HPP
