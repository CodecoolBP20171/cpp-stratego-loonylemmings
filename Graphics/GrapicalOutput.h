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
#include <bits/unique_ptr.h>

#include "Display.hpp"
#include "Init/DisplayParts.hpp"
#include "Init/Tileset.hpp"
#include "../GameObjects/GameParts.hpp"

class GrapicalOutput : public Display {

public:
    GrapicalOutput();

    void setResource(GameParts* parts) override;
    void printOut() override;
    void close() override;

private:

    SDL_Window* gWindow = nullptr;
    SDL_Renderer* gRenderer = nullptr;
    const DisplayParts dParts;

    std::map<std::string, SDL_Texture*> pictures;

    bool init();
    SDL_Texture* loadTexture(std::string path);
    bool loadMedia();
    void drawBoard();
    void drawSelection();
    void drawButtons();
    void drawBtn(std::string name, DPElem button);
};


#endif //CPP_STRATEGO_LOONYLEMMINGS_GRAPICALOUTPUT_H
