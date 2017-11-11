//
// Created by jeannie on 2017.11.11..
//

#include <iostream>
#include "MouseInput.h"

MouseInput::MouseInput() {}

MouseInput::~MouseInput() {}

MouseInput::InputType MouseInput::getUserInput() {
    bool quit = false;
    SDL_Event e;

    while(!quit) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                std::cout << x << ", " << y << std::endl;
                return MOVE;
            }

            if (e.type == SDL_QUIT) {
                std::cout << "Quit\n";
                quit = true;
                break;
            }
        }
    }
    return QUIT;
}

unsigned MouseInput::getIndex() { return index;}
