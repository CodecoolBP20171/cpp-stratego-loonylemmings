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
    gameObjects->stash = player1.getState()? gameObjects->p1stash : gameObjects->p2stash;

        switch (input->getUserInput()) {

            case UserInput::SELECT : {
                int index = input->getIndex();

                if (index>99) {
                    if ((*gameObjects->stash)[index-100]) {
                        gameObjects->selected = index;
                        std::cout << "Selected " << (*gameObjects->stash)[index-100]->getShortName() << std::endl;
                        display->printOut();
                    }
                    break;
                }

                if ((*gameObjects->board)[index]) {
                    gameObjects->selected = index;
                    std::cout << "Selected " << (*gameObjects->board)[index]->getShortName() << std::endl;
                    display->printOut();
                    break;
                }

                if (player1.getState()&&index>59||player2.getState()&&index<40) {

                    if (gameObjects->selected > 99) {
                        std::cout << (*gameObjects->stash)[gameObjects->selected-100]->getShortName() << " moved here " << std::endl;
                        (*gameObjects->board)[index].swap((*gameObjects->stash)[gameObjects->selected-100]);
                        gameObjects->selected = -1;
                        display->printOut();
                        break;
                    } else if (gameObjects->selected >= 0) {
                        std::cout << (*gameObjects->board)[gameObjects->selected]->getShortName() << " moved here " << std::endl;
                        (*gameObjects->board)[index].swap((*gameObjects->board)[gameObjects->selected]);
                        gameObjects->selected = -1;
                        display->printOut();
                    }
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
            (*gameObjects->p2stash)[index].reset(new Card(piece.first, player2));
            (*gameObjects->p1stash)[index++].reset(new Card(piece.first, player1));
        }
    }
    player1.setState(true);
    player2.setState(false);
}


