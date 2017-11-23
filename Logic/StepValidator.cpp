//
// Created by jeannie on 2017.11.22..
//

#include "StepValidator.h"

StepValidator::StepValidator() {}

StepValidator::~StepValidator() {}

bool StepValidator::checkPlacement(int index) {

    auto game = gameObjects.lock();
    auto stash = game->stash.lock();
    auto player = game->player.lock();

    if (index>99 && index<=stash->size()+99) {
        game->selected = index;
        return false;
    }

    if (player->isInMyArea(index)) {
        if ((*game->board)[index]) {
            game->selected = index;
            return false;
        }
        if (game->selected >= 0) {
            return true;
        }
    }
    game->wrong = index;
    return false;
}