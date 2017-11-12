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
#include "DisplayParts.hpp"
#include "CoordinateConverter.hpp"
#include "../GameObjects/Tileset.hpp"
#include "../GameObjects/GameParts.hpp"

class GrapicalOutput : public Display {

public:
    GrapicalOutput();

    void printOut() override;
    void close() override;

private:

    SDL_Window* gWindow = nullptr;
    SDL_Renderer* gRenderer = nullptr;

    std::map<std::string, SDL_Texture*> pictures;

    bool init();
    SDL_Texture* loadTexture(std::string path);
    bool loadMedia();
};


#endif //CPP_STRATEGO_LOONYLEMMINGS_GRAPICALOUTPUT_H
