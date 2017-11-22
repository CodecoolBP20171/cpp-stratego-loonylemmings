//
// Created by jeannie on 2017.11.22..
//

#include "StepValidator.h"

StepValidator::StepValidator() {}

StepValidator::~StepValidator() {}

bool StepValidator::checkPlacement(int index) {
    if (index>99&&index<=gameObjects->stash->size()+99) {
        gameObjects->selected = index;
        return false;
    }

    if (gameObjects->player->isInMyArea(index)) {
        if ((*gameObjects->board)[index]) {
            gameObjects->selected = index;
            return false;
        }
        if (gameObjects->selected >= 0) {
            return true;
        }
    }
    gameObjects->wrong = index;
    return false;
}



