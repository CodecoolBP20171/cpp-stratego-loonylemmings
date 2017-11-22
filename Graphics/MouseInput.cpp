//
// Created by jeannie on 2017.11.11..
//

#include <iostream>
#include "MouseInput.h"

MouseInput::InputType MouseInput::getUserInput() {
    bool quit = false;
    index = -1;
    SDL_Event e;

    while(!quit) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                DPBase click(0, 0);
                SDL_GetMouseState(&click.startX, &click.startY);
                std::cout << click.startX << ", " << click.startY;
                switch (gOutput.getPart(click)) {
                    case DisplayParts::DisplayPart::BOARD : {
                        index = gOutput.board.getIndex(click);
                        std::cout << " clicked on BOARD @" << index << std::endl;
                        return SELECT;
                    }
                    case DisplayParts::DisplayPart::STASH : {
                        index = gOutput.stash.getIndex(click)+100;
                        std::cout << " clicked on STASH @" << index << std::endl;
                        return SELECT;
                    }
                    case DisplayParts::DisplayPart::OK : {
                        std::cout << " clicked on OK\n";
                        return OK;
                    }
                    case DisplayParts::DisplayPart::RESET : {
                        std::cout << " clicked on RESET\n";
                        return RESET;
                    }
                    case DisplayParts::DisplayPart::RESTART : {
                        std::cout << " clicked on RESTART\n";
                        break;
                    }
                    default: {
                        std::cout << " nothing here\n";
                        return NOTHING;
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