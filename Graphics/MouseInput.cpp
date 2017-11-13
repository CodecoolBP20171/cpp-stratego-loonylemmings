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
                        index = CoordinateConverter::getBoardIndex(x, y);
                        std::cout << " clicked on BOARD @" << index << std::endl;
                        return SELECT;
                    }
                    case DisplayParts::DisplayPart::STASH : {
                        index = CoordinateConverter::getStashIndex(x, y);
                        std::cout << " clicked on STASH @" << index << std::endl;
                        index += 100;
                        return SELECT;
                    }
                    case DisplayParts::DisplayPart::OK : {
                        std::cout << " clicked on OK\n";
                        break;
                    }
                    case DisplayParts::DisplayPart::RESET : {
                        std::cout << " clicked on RESET\n";
                        break;
                    }
                    case DisplayParts::DisplayPart::RESTART : {
                        std::cout << " clicked on RESTART\n";
                        break;
                    }
                    default: {
                        std::cout << " nothing here\n";
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
