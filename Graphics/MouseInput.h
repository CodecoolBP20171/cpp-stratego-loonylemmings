//
// Created by jeannie on 2017.11.11..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_MOUSEINPUT_H
#define CPP_STRATEGO_LOONYLEMMINGS_MOUSEINPUT_H

#include <SDL.h>
#include "UserInput.hpp"

class MouseInput : public UserInput {

public:
    MouseInput() = default;
    ~MouseInput() = default;

    InputType getUserInput() override;
    int getIndex() override { return index;}

private:
    int index;
};


#endif //CPP_STRATEGO_LOONYLEMMINGS_MOUSEINPUT_H
