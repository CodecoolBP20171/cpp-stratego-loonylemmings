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

        p1stash = std::make_shared<std::array <std::unique_ptr<Card>, 40>>();
        p2stash = std::make_shared<std::array <std::unique_ptr<Card>, 40>>();

        board.reset(new(std::array<std::unique_ptr<Card>, 100>));

        player1 = std::make_shared<Player>(1);
        player2 = std::make_shared<Player>(2);

        player = player1;

        for (auto i = 0; i<40; i++) {
            (*p1stash)[i].reset();
            (*p2stash)[i].reset();
        }

        for (auto i = 0; i<100; i++) {
            (*board)[i].reset();
        }

        stash = p1stash;
        selected = -1;

        okBtn = true;
        resetBtn = true;
        restartBtn = true;
    }

    virtual ~GameParts() {}

    std::shared_ptr<Player> player1;
    std::shared_ptr<Player> player2;

    std::shared_ptr<std::array<std::unique_ptr<Card>, 40>> p1stash;
    std::shared_ptr<std::array<std::unique_ptr<Card>, 40>> p2stash;
    std::unique_ptr<std::array<std::unique_ptr<Card>, 100>> board;

    int selected;
    int wrong;

    std::shared_ptr<std::array<std::unique_ptr<Card>, 40>> stash;
    std::shared_ptr<Player> player;

    bool okBtn;
    bool resetBtn;
    bool restartBtn;
};

#endif //CPP_STRATEGO_LOONYLEMMINGS_GAMEPARTS_HPP
