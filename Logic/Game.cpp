//
// Created by jeannie on 2017.11.12..
//

#include <map>
#include <iostream>
#include <algorithm>
#include "Game.h"

Game::Game()
    : gameObjects(new GameParts())
{}

Game::~Game() {}

void Game::nextPlayer() {

    gameObjects->player1->setState(!gameObjects->player1->getState());
    gameObjects->player2->setState(!gameObjects->player2->getState());

    gameObjects->stash = gameObjects->player1->getState() ? gameObjects->p1stash : gameObjects->p2stash;
    gameObjects->player = gameObjects->player1->getState() ? gameObjects->player1 : gameObjects->player2;

    for (auto i=0; i<100; i++) { if ((*gameObjects->board)[i]) { (*gameObjects->board)[i]->flip(); }}
}

void Game::start() {

    fillStashes();
    display->setResource(gameObjects);
    display->printOut();

    bool quit = false;
    while(!quit) {

        switch (input->getUserInput()) {

            case UserInput::SELECT : {
                int index = input->getIndex();
                gameObjects->wrong = -1;

                if (index>99&&index<=gameObjects->stash->size()+99) {
                        gameObjects->selected = index;
                        std::cout << "Selected " << (*gameObjects->stash)[index-100]->getShortName() << std::endl;
                        display->printOut();
                        break;
                    }

                if (gameObjects->player->isInMyArea(index)) {

                    if ((*gameObjects->board)[index]) {
                        gameObjects->selected = index;
                        std::cout << "Selected " << (*gameObjects->board)[index]->getShortName() << std::endl;
                        display->printOut();
                        break;
                    }

                    if (gameObjects->selected >= 0) {

                            if (gameObjects->selected > 99) {
                                auto card = gameObjects->selected - 100;
                                std::cout << (*gameObjects->stash)[card]->getShortName() << " moved here " << std::endl;
                                (*gameObjects->board)[index] = std::move((*gameObjects->stash)[card]);
                                gameObjects->stash->erase(gameObjects->stash->begin()+card);
                            } else {
                                std::cout << (*gameObjects->board)[gameObjects->selected]->getShortName() << " moved here " << std::endl;
                                (*gameObjects->board)[index].swap((*gameObjects->board)[gameObjects->selected]);
                            }
                        gameObjects->selected = -1;
                        display->printOut();
                        break;
                    }
                }
                gameObjects->wrong = index;
                display->printOut();
                break;
            }

            case UserInput::QUIT : {
                quit = true;
                break;
            }

            case UserInput::OK : {
                nextPlayer();
                display->printOut();
                break;
            }
        }
    }
}

void Game::fillStashes() {
    std::map<int, int> pieces = {{0, 1}, {1, 1}, {2, 8}, {3, 5}, {4, 4}, {5, 4},
                                 {6, 4}, {7, 3}, {8, 2}, {9, 1}, {10, 1}, {11, 6}};
    for (auto piece : pieces ) {
        int amount = piece.second;
        for (;amount > 0; amount--) {

            std::unique_ptr<Card> card (new Card(piece.first, gameObjects->player1));
            gameObjects->p1stash->push_back(std::move(card));
            std::unique_ptr<Card> card2 (new Card(piece.first, gameObjects->player2));
            gameObjects->p2stash->push_back(std::move(card2));
        }
    }

    gameObjects->player1->setState(true);
    gameObjects->stash = gameObjects->p1stash;
    gameObjects->player2->setState(false);
}


