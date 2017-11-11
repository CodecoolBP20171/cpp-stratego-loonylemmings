//
// Created by jeannie on 2017.11.11..
//

#ifndef CPP_STRATEGO_LOONYLEMMINGS_GRAPICALOUTPUT_H
#define CPP_STRATEGO_LOONYLEMMINGS_GRAPICALOUTPUT_H

#include <SDL.h>
#include <SDL_image.h>
#include <cstdio>
#include <string>
#include <map>

#include "Display.hpp"
#include "../GameObjects/Tileset.hpp"

class GrapicalOutput : public Display {

public:
    GrapicalOutput();

    void printOut() override;
    void close();

private:
    const int SCREEN_WIDTH = 600;
    const int SCREEN_HEIGHT = 600;

    SDL_Window* gWindow = nullptr;
    SDL_Renderer* gRenderer = nullptr;

    std::map<std::string, SDL_Texture*> pictures;

    bool init();
    SDL_Texture* loadTexture(std::string path);
    bool loadMedia();
};


#endif //CPP_STRATEGO_LOONYLEMMINGS_GRAPICALOUTPUT_H
