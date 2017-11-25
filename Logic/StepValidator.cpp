//
// Created by jeannie on 2017.11.22..
//

#include <iostream>
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

bool StepValidator::isInside(int x, int y) { return (x >= 0)&&(x < 10)&&(y >= 0)&&(y<10); }

bool StepValidator::isMovableCard(int index) {
    auto game = gameObjects.lock();

    //check if card not bomb or flag
    if (game->getCardFromBoard(index)->getMaxMove() == 0) return false;

    //check if card has space to move
    int x = index%10;
    int y = (index >= 10) ? (index-x)/10 : 0;

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (!isInside(x+j, y+i)) continue;
            if (!game->isCardInBoardAt(index+10*i+j) && !isInTheLake(index+10*i+j)) {
                return true;
            }
        }
    }
    return false;
}

bool StepValidator::isInTheLake(int index) {
    return index == 42 || index == 43 || index == 52 || index == 53
            || index == 46 || index == 47 || index == 56 || index == 57;
}

bool StepValidator::isValidRange(int from, int to) {
    if (isInTheLake(to)) return false;
    auto dist = from-to;
    return dist == 1 || (dist>=9 && dist<=11)
           || dist == -1 || (dist>=-11 && dist<=-9);
}

bool StepValidator::isReacheableForAScout(int from, int to) {
    if (isInTheLake(to)) return false;

    int sx = from%10;
    int sy = (from>=10) ? (from-sx)/10 : 0;
    int ex = to%10;
    int ey = (to>=10) ? (to-ex)/10 : 0;
    int step;

    if (sx == ex) {
        step = 10;
    } else if (sy == ey) {
        step = 1;
    } else {
        return false;
    }
    auto game = gameObjects.lock();
    if (from>to) { step = 0-step; }

    for (auto i = from+step; i != to; i += step) {
        if (isInTheLake(i)) return false;
        if (game->isCardInBoardAt(i)) return false;
    }
    return true;
}

bool StepValidator::checkStep(int index) {
    battle = false;
    auto game = gameObjects.lock();

    // clicked on stash = error
    if (index>99) {
        game->setError(index);
        return false;
    }

    auto owner = game->getOwnerAt(index);
    auto player = game->getActualPlayer();

    // clicked on own movable card = select
    if (owner == player && isMovableCard(index)) {
        game->setSelected(index);
        return false;
    }

    auto selected = game->getSelected();

    // nothing selected = error
    if (selected < 0) {
        game->setError(index);
        return false;
    }

    // reacheable range for scout = true
    if (game->getCardFromBoard(selected)->getMaxMove() == 10
        && isReacheableForAScout(selected, index)) {
        battle = owner && owner != player;
        return true;
    }

    // any other cards 1 step range valid field = true
    if (isValidRange(selected, index)) {
        battle = owner && owner != player;
        return true;
    }

    // invalid field
    game->setError(index);
    return false;
}


