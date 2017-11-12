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
    //Set texture filtering to linear
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
        printf( "Warning: Linear texture filtering not enabled!" );
    }
    //Create window
    gWindow = SDL_CreateWindow("Startego Wars",
                                SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED,
                                DisplayParts::windowWidth,
                                DisplayParts::windowHeight,
                                SDL_WINDOW_SHOWN);
    if( !gWindow ) {
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
        return false;
    }
    //Create renderer for window
    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( !gRenderer ) {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        return false;
    }
    //Initialize renderer color
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return false;
    }
    return true;
}

SDL_Texture* GrapicalOutput::loadTexture(std::string path) {
    //The final texture
    SDL_Texture* newTexture = nullptr;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if(!loadedSurface) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    } else {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
        if(!newTexture) {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

bool GrapicalOutput::loadMedia() {

    Tileset swset;

    for (auto &tiles : swset.themeSet) {
        SDL_Texture* card = loadTexture("../Tiles/" + tiles.second);
        if(!card) {
            printf("Failed to load picture!\n");
        } else {
            pictures[tiles.first] = card;
        }
    }

    return true;
}

void GrapicalOutput::close() {

    SDL_Delay(500);

    for (const auto &picture : pictures) { SDL_DestroyTexture(pictures[picture.first]); }
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

    SDL_RenderClear( gRenderer );

    //set bg coordinates and render bg into it
    SDL_Rect bg = {0, 0, DisplayParts::windowHeight, DisplayParts::windowWidth};
    SDL_RenderCopy(gRenderer, pictures["Board"], nullptr, &bg);

    int index[2];
    for (int i= 0; i<100; i++) {
        if (GameParts::board[i]) {
        CoordinateConverter::getCoordinates(i, index);
        SDL_Rect ins = {index[0], index[1], DisplayParts::cardWidth, DisplayParts::cardHeight};
        SDL_RenderCopy(gRenderer, pictures[GameParts::board[i]->getShortName()], nullptr, &ins);
        }
    }

    //show
    SDL_RenderPresent( gRenderer );

}
