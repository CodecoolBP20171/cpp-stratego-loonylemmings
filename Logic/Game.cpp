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

void Game::initGame() {
    fillStash();
    gameObjects->switchPlayers();
    fillStash();
    gameObjects->switchPlayers();
    gameObjects->hideButtons();
}

UserInput::InputType Game::start() {

    initGame();

    auto display = out.lock();
    auto input = in.lock();

    display->setResource(gameObjects);
    display->printOut();

    UserInput::InputType result = placeCards();
    if (result != UserInput::OK) return result;

    result = placeCards();
    if (result != UserInput::OK) return result;
    input->getUserInput();
}

UserInput::InputType Game::placeCards() {
    auto display = out.lock();
    auto input = in.lock();

    bool quit = false;
    while(!quit) {
        gameObjects->setError(-1);

        switch (input->getUserInput()) {

            case UserInput::SELECT : {
                int index = input->getIndex();
                if (validator.checkPlacement(index)) {
                    step(index);
                    if (gameObjects->isActualStashEmpty()) { gameObjects->showOk(); }
                    gameObjects->showReset(); }

                break;
            }

            case UserInput::QUIT : { return UserInput::QUIT; }

            case UserInput::RESTART : { return UserInput::RESTART; }

            case UserInput::RESET : {
                gameObjects->hideButtons();
                reset();
                break;
            }

            case UserInput::OK : {
                if (gameObjects->isActualStashEmpty()) {
                    gameObjects->flipCardsDown();
                    gameObjects->switchPlayers();
                    gameObjects->hideButtons();
                    display->printOut();
                    return UserInput::OK;
                }
                break;
            }
        }
        display->printOut();
    }
}

void Game::fillStash() {

    std::map<int, int> pieces = {{0, 1}, {1, 1}, {2, 8}, {3, 5}, {4, 4}, {5, 4},
                                 {6, 4}, {7, 3}, {8, 2}, {9, 1}, {10, 1}, {11, 6}};
    for (auto piece : pieces ) {
        int amount = piece.second;
        for (;amount > 0; amount--) {
            gameObjects->createCardInActualStash(piece.first);
        }
    }
}

void Game::reset() {
    gameObjects->destroyPlayerCards();
    gameObjects->clearPlayerStash();
    fillStash();
}

void Game::step(int index) {
    auto card = gameObjects->getSelected();
    gameObjects->setSelected(-1);

    if (card < 100) {
        gameObjects->boardSwap(index, card);
        return;
    }
    card -= 100;
    gameObjects->moveCardFromStashToBoard(card, index);
}


