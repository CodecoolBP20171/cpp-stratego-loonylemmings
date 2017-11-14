//
// Created by jeannie on 2017.11.12..
//

#include <map>
#include <iostream>
#include "Game.h"

Game::Game() {

    GameParts::player1 = new Player(1);
    GameParts::player2 = new Player(2);

    GameParts::p1stash[40] = {nullptr};
    GameParts::p2stash[40] = {nullptr};
    GameParts::board[100] = {nullptr};
    GameParts::stash = GameParts::p1stash;

    GameParts::selected = -1;

    GameParts::okBtn = true;
    GameParts::resetBtn = true;
    GameParts::restartBtn = true;
}

Game::~Game() {}

void Game::start() {

    fillStashes();
    display->printOut();

    bool quit = false;
    while(!quit) {

        switch (input->getUserInput()) {

            case UserInput::SELECT : {
                int index = input->getIndex();
                if (index>99) {
                    break;
                }
                if (GameParts::board[index]) {
                    GameParts::selected = index;
                    std::cout << "Selected " << GameParts::board[index]->getShortName() << std::endl;
                    display->printOut();
                } else if (GameParts::selected >= 0) {
                    std::cout << GameParts::board[GameParts::selected]->getShortName() << " moved here " << std::endl;
                    GameParts::board[index] = GameParts::board[GameParts::selected];
                    GameParts::board[GameParts::selected] = nullptr;
                    GameParts::selected = -1;
                    display->printOut();
                }
                break;
            }

            case UserInput::QUIT : {
                quit = true;
            }
        }
    }
}

void Game::fillStashes() {
    std::map<int, int> pieces = {{0, 1}, {1, 1}, {2, 8}, {3, 5}, {4, 4}, {5, 4},
                                 {6, 4}, {7, 3}, {8, 2}, {9, 1}, {10, 1}, {11, 6}};
    int index = 0;
    for (auto piece : pieces ) {
        int amount = piece.second;
        for (;amount > 0; amount--) {
            //TODO: the stashes should be filled here
            GameParts::board[index+60] = new Card(piece.first, GameParts::player2);
            GameParts::board[index++] = new Card(piece.first, GameParts::player1);
        }
    }
}


