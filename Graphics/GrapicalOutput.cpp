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
                                DisplayParts::windowWidth, DisplayParts::windowHeight, SDL_WINDOW_SHOWN);
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
    for (auto &tiles : set.themeSet) {
        SDL_Texture* card = loadTexture("../Tiles/" + tiles.second);
        if(card) { pictures[tiles.first] = card; }
    }
    return true;
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

GrapicalOutput::GrapicalOutput() {
    if( !init() ) { printf( "Failed to initialize!\n" ); }
    if( !loadMedia() ) { printf( "Failed to load media!\n" );}
}

void GrapicalOutput::printOut() {

    SDL_RenderClear(gRenderer);

    SDL_Rect bg = {0, 0, DisplayParts::windowWidth, DisplayParts::windowHeight};
    SDL_RenderCopy(gRenderer, pictures["Board"], nullptr, &bg);

    drawBoard();
    drawSelection();
    drawButtons();

    SDL_RenderPresent(gRenderer);

}

void GrapicalOutput::drawSelection() {
    if (GameParts::selected < 0) return;
    int index[2];
    Converter::getBoardCoords(GameParts::selected, index);
    SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF );
    SDL_Rect selection = {index[0]-2, index[1]-2, DisplayParts::cellWidth, DisplayParts::cellHeight};
    SDL_RenderDrawRect(gRenderer, &selection);
    selection = {index[0]-1, index[1]-1, DisplayParts::cellWidth-2, DisplayParts::cellHeight-2};
    SDL_RenderDrawRect(gRenderer, &selection);
}

void GrapicalOutput::drawButtons() {
    if (GameParts::okBtn) {
        drawBtn("OkBTN", DisplayParts::okStartX, DisplayParts::okStartY, DisplayParts::okWidth, DisplayParts::okHeight);
    }
    if (GameParts::resetBtn) {
        drawBtn("ResetBTN", DisplayParts::rStartX, DisplayParts::rstStartY, DisplayParts::rWidth, DisplayParts::rHeight);
    }
    if (GameParts::restartBtn) {
        drawBtn("RestartBTN", DisplayParts::rStartX, DisplayParts::rStartY, DisplayParts::rWidth, DisplayParts::rHeight);
    }
}

void GrapicalOutput::drawBtn(std::string name, int x, int y, int Width, int Height) {
    SDL_Rect btn = {x, y, Width, Height};
    SDL_RenderCopy(gRenderer, pictures[name], nullptr, &btn);
}

//TODO: this should also handle stashes
void GrapicalOutput::drawBoard() {
    int index[2];
    for (int i= 0; i<100; i++) {
        if (GameParts::board[i]) {
            Converter::getBoardCoords(i, index);
            SDL_Rect ins = {index[0], index[1], DisplayParts::cardWidth, DisplayParts::cardHeight};
            SDL_RenderCopy(gRenderer, pictures[GameParts::board[i]->getShortName()], nullptr, &ins);
        }
    }
}
