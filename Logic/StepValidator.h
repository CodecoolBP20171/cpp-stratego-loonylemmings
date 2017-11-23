//
// Created by jeannie on 2017.11.22..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_STEPVALIDATOR_HPP
#define CPP_STRATEGO_LOONYLEMMINGS_STEPVALIDATOR_HPP

#include <memory>
#include <bits/unique_ptr.h>
#include <bits/shared_ptr.h>

#include "../GameObjects/Player.hpp"
#include "../GameObjects/Card.hpp"
#include "../GameObjects/GameParts.hpp"

class StepValidator {

public:
    StepValidator();
    virtual ~StepValidator();

    void setGameObjects(std::shared_ptr<GameParts>& go) { gameObjects = go; }

    bool checkPlacement(int index);

private:
    std::weak_ptr<GameParts> gameObjects;
};


#endif //CPP_STRATEGO_LOONYLEMMINGS_STEPVALIDATOR_HPP
