//
// Created by jeannie on 2017.11.12..
//

#include <map>
#include <iostream>
#include <algorithm>
#include "Game.h"

Game::Game()
    : gameObjects(new GameParts()), validator()
{
    validator.setGameObjects(gameObjects);
}

Game::~Game() {}

void Game::nextPlayer() {

    gameObjects->player1->setActive(!gameObjects->player1->isActive());
    gameObjects->player2->setActive(!gameObjects->player2->isActive());

    gameObjects->stash = gameObjects->player1->isActive() ? gameObjects->p1stash : gameObjects->p2stash;
    gameObjects->player = gameObjects->player1->isActive() ? gameObjects->player1 : gameObjects->player2;

    for (auto i=0; i<100; i++) { if ((*gameObjects->board)[i]) { (*gameObjects->board)[i]->flip(); }}

    gameObjects->okBtn = false;
}

void Game::start() {

    auto display = out.lock();
    auto input = in.lock();

    display->printPause();
    fillStash();
    nextPlayer();
    fillStash();
    nextPlayer();
    display->setResource(gameObjects);
    setDemoBoard(0);
    input->getUserInput();
    display->printOut();

    if (!placeCards()) return;
    display->printPause();
    nextPlayer();
    setDemoBoard(60);
    input->getUserInput();
    display->printOut();

    if (!placeCards()) return;
    display->printPause();
    nextPlayer();
    input->getUserInput();
    display->printOut();
    input->getUserInput();
}

bool Game::placeCards() {
    auto display = out.lock();
    auto input = in.lock();
    auto stash = gameObjects->stash.lock();
    auto player = gameObjects->player.lock();

    bool quit = false;
    gameObjects->okBtn = false;
    gameObjects->resetBtn = true;


    while(!quit) {
        gameObjects->wrong = -1;
        switch (input->getUserInput()) {
            case UserInput::SELECT : {
                int index = input->getIndex();
                if (validator.checkPlacement(index)) {
                    step(index);
                    //if (gameObjects->stash->empty()) { gameObjects->okBtn = true; }
                    if (stash->empty()) { gameObjects->okBtn = true; }
                    //if (stash->size()==5) { gameObjects->resetBtn = true; }
                };
                break;
            }
            case UserInput::QUIT : {
                return false;
            }
            case UserInput::RESET : {
                gameObjects->okBtn = false;
                //gameObjects->resetBtn = false;
                reset();
                break;
            }
            case UserInput::RESTART : {
                if (stash->size()==40) {
                    int index = player->isInMyArea(0) ? 0 : 60;
                    setDemoBoard(index);
                }
                break;
            }

            case UserInput::OK : {
                //gameObjects->resetBtn = false;
                if (stash->empty()) return true;
                break;
            }
        }
        display->printOut();
    }
}

void Game::fillStash() {

    auto stash = gameObjects->stash.lock();
    auto player = gameObjects->player.lock();

    std::map<int, int> pieces = {{0, 1}, {1, 1}, {2, 8}, {3, 5}, {4, 4}, {5, 4},
                                 {6, 4}, {7, 3}, {8, 2}, {9, 1}, {10, 1}, {11, 6}};
    for (auto piece : pieces ) {
        int amount = piece.second;
        for (;amount > 0; amount--) {
            std::unique_ptr<Card> card (new Card(piece.first, player));
            stash->push_back(std::move(card));
        }
    }
}

void Game::setDemoBoard(int index) {
    int end = index+37;
    auto stash = gameObjects->stash.lock();

    for (; index<end; index++) {
        (*gameObjects->board)[index] = std::move((*stash)[0]);
        stash->erase(stash->begin());
    }
}

void Game::reset() {

    auto stash = gameObjects->stash.lock();
    auto player = gameObjects->player.lock();

    auto i = (player->isInMyArea(0)) ? 0 : 60;
    auto end = i+40;
    for (;i<end;i++) {
        if ((*gameObjects->board)[i]) (*gameObjects->board)[i].reset();
    }
    stash->clear();
    fillStash();
}

void Game::step(int index) {

    auto stash = gameObjects->stash.lock();
    auto player = gameObjects->player.lock();
    auto card = gameObjects->selected;

    gameObjects->selected = -1;
    if (card < 100) {
        (*gameObjects->board)[index].swap((*gameObjects->board)[card]);
        return;
    }
    card -= 100;
    (*gameObjects->board)[index] = std::move((*stash)[card]);
    stash->erase(stash->begin()+card);
}


