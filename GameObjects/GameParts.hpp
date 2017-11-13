//
// Created by jeannie on 2017.11.12..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_GAMEPARTS_HPP
#define CPP_STRATEGO_LOONYLEMMINGS_GAMEPARTS_HPP

#include "Player.hpp"
#include "Card.hpp"

class GameParts {

public:
    static Player* player1;
    static Player* player2;

    static Card* p1stash[40];
    static Card* p2stash[40];
    static Card* board[100];

    static int selectedIndex;

    static bool okBtn;
    static bool resetBtn;
    static bool restartBtn;
};

#endif //CPP_STRATEGO_LOONYLEMMINGS_GAMEPARTS_HPP
