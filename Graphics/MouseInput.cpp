//
// Created by jeannie on 2017.11.11..
//

#include <iostream>
#include "MouseInput.h"
#include "DisplayParts.hpp"
#include "CoordinateConverter.hpp"

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
                std::cout << x << ", " << y;
                switch (DisplayParts::getScreenPart(x, y)) {
                    case DisplayParts::DisplayPart::BOARD : {
                        index = CoordinateConverter::getIndex(x, y);
                        std::cout << " @index: " << index << std::endl;
                        return SELECT;
                    }
                    default: {
                        std::cout << " no clickable item here\n";
                    }
                }
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

int MouseInput::getIndex() { return index;}
