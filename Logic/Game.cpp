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
}

Game::~Game() {}

void Game::start() {

    std::map<int, int> pieces = {{0, 1}, {1, 1}, {2, 8}, {3, 5}, {4, 4}, {5, 4},
                                 {6, 4}, {7, 3}, {8, 2}, {9, 1}, {10, 1}, {11, 6}};

    int index = 0;
    for (auto piece : pieces ) {
        int amount = piece.second;
        for (;amount > 0; amount--) {
            GameParts::board[index++] = new Card(piece.first, GameParts::player1);
        }
    }

    display->printOut();

    bool quit = false;
    GameParts::selectedIndex = -1;
    while(!quit) {
        switch (input->getUserInput()) {
            case UserInput::SELECT : {
                int clickedIndex = input->getIndex();

                if (GameParts::board[clickedIndex]) {
                    GameParts::selectedIndex = clickedIndex;
                    std::cout << "Selected "
                              << GameParts::board[clickedIndex]->getShortName()
                              << " on index "
                              << clickedIndex
                              << std::endl;
                    display->printOut();
                } else if (GameParts::selectedIndex >= 0) {
                    std::cout << GameParts::board[GameParts::selectedIndex]->getShortName()
                              << " moved to "
                              << clickedIndex
                              << std::endl;
                    GameParts::board[clickedIndex] = GameParts::board[GameParts::selectedIndex];
                    GameParts::board[GameParts::selectedIndex] = nullptr;
                    GameParts::selectedIndex = -1;
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


