//
// Created by jeannie on 2017.11.12..
//

#include <map>
#include <iostream>
#include "Game.h"

Game::Game()
    : player1(1), player2(2), gameObjects(new GameParts())
{}

Game::~Game() {}

void Game::start() {

    fillStashes();
    display->setResource(gameObjects);
    display->printOut();

    bool quit = false;
    while(!quit) {

        switch (input->getUserInput()) {

            case UserInput::SELECT : {
                int index = input->getIndex();
                if (index>99) {
                    break;
                }
                if (gameObjects->board[index]) {
                    gameObjects->selected = index;
                    std::cout << "Selected " << gameObjects->board[index]->getShortName() << std::endl;
                    display->printOut();
                } else if (gameObjects->selected >= 0) {
                    std::cout << gameObjects->board[gameObjects->selected]->getShortName() << " moved here " << std::endl;
                    gameObjects->board[index].swap(gameObjects->board[gameObjects->selected]);
                    gameObjects->selected = -1;
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
            gameObjects->board[index+60].reset(new Card(piece.first, player2));
            gameObjects->board[index++].reset(new Card(piece.first, player1));
        }
    }
}


