//
// Created by jeannie on 2017.11.11..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_MOUSEINPUT_H
#define CPP_STRATEGO_LOONYLEMMINGS_MOUSEINPUT_H

#include <SDL.h>
#include "UserInput.hpp"

class MouseInput : public UserInput {

public:
    MouseInput();
    virtual ~MouseInput();

    InputType getUserInput() override;
    unsigned getIndex() override;

private:
    unsigned index;
};


#endif //CPP_STRATEGO_LOONYLEMMINGS_MOUSEINPUT_H
