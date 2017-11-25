//
// Created by jeannie on 2017.11.22..
//

#include "StepValidator.h"

StepValidator::StepValidator() {}

StepValidator::~StepValidator() {}

bool StepValidator::checkPlacement(int index) {

    auto game = gameObjects.lock();

    if (index>99 && game->isCardInStashAt(index-100)) {
        game->setSelected(index);
        return false;
    }

    if (game->isInPlayerArea(index)) {
        if (game->getCardFromBoard(index)) {
            game->setSelected(index);
            return false;
        }
        if (game->getSelected() >= 0) {
            return true;
        }
    }
    game->setError(index);
    return false;
}