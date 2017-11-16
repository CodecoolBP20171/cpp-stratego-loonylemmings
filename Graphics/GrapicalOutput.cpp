//
// Created by jeannie on 2017.11.11..
//

#include <iostream>
#include "GrapicalOutput.h"

bool GrapicalOutput::init() {
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        return false;
    }
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
        printf( "Warning: Linear texture filtering not enabled!" );
    }
    gWindow = SDL_CreateWindow("Startego Wars", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                               dParts.window.width, dParts.window.height, SDL_WINDOW_SHOWN);
    if( !gWindow ) {
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
        return false;
    }
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( !gRenderer ) {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        return false;
    }

    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return false;
    }
    return true;
}

SDL_Texture* GrapicalOutput::loadTexture(std::string path) {
    SDL_Texture* newTexture = nullptr;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());

    if(!loadedSurface) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    } else {
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if(!newTexture) {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

bool GrapicalOutput::loadMedia() {
    Tileset set;
    //set.loadBaseTheme();
    set.loadSWTheme();
    for (auto &tiles : set.themeSet) {
        SDL_Texture* card = loadTexture("../Tiles/" + tiles.second);
        if(card) { pictures[tiles.first] = card; }
    }

    SDL_Rect bg = dParts.window.getRect();
    SDL_RenderCopy(gRenderer, pictures["Splash"], nullptr, &bg);
    SDL_RenderPresent(gRenderer);
    SDL_Delay(3000);

    return true;
}

void GrapicalOutput::setResource(GameParts* parts) {
    game = parts;
}

void GrapicalOutput::close() {
    for (const auto &picture : pictures) {
        SDL_DestroyTexture(pictures[picture.first]);
    }
    pictures.clear();
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;
    IMG_Quit();
    SDL_Quit();
}

GrapicalOutput::GrapicalOutput()
        : dParts()
{
    if( !init() ) { printf( "Failed to initialize!\n" ); }
    if( !loadMedia() ) { printf( "Failed to load media!\n" );}
}

void GrapicalOutput::printOut() {

    SDL_RenderClear(gRenderer);

    SDL_Rect bg = dParts.window.getRect();
    SDL_RenderCopy(gRenderer, pictures["Board"], nullptr, &bg);

    drawBoard();
    drawSelection();
    drawButtons();

    SDL_RenderPresent(gRenderer);

}

void GrapicalOutput::drawSelection() {
    if (game->selected < 0) return;
    int index = game->selected;
    DPBase obj = dParts.board.getCoords(index);
    SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF );
    SDL_Rect sel = dParts.field.getRect(obj);
    SDL_RenderDrawRect(gRenderer, &sel);
}

void GrapicalOutput::drawButtons() {
    if (game->okBtn) {
        drawBtn("OkBTN", dParts.okBTN);
    }
    if (game->resetBtn) {
        drawBtn("ResetBTN", dParts.resetBTN);
    }
    if (game->restartBtn) {
        drawBtn("RestartBTN", dParts.restartBTN);
    }
}

void GrapicalOutput::drawBtn(std::string name, DPElem button) {
    SDL_Rect btn = button.getRect();
    SDL_RenderCopy(gRenderer, pictures[name], nullptr, &btn);
}

//TODO: this should also handle stashes
void GrapicalOutput::drawBoard() {

    for (int i= 0; i<100; i++) {
        if (game->board[i]) {
            std::string name = game->board[i]->getShortName();
            DPBase obj = dParts.board.getCoords(i);
            SDL_Rect ins = dParts.field.getRect(obj);
            SDL_RenderCopy(gRenderer, pictures[name], nullptr, &ins);
        }
    }
}


