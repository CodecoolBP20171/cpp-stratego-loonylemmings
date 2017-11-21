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

    std::unique_ptr<SDL_Window, sdl_deleter> window(
            SDL_CreateWindow("Startego Wars", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                             dParts.window.width, dParts.window.height, SDL_WINDOW_SHOWN),
            sdl_deleter());
    if( !window ) {
        printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
        return false;
    }

    gWindow = std::move(window);

    std::unique_ptr<SDL_Renderer, sdl_deleter> renderer(
            SDL_CreateRenderer( gWindow.get(), -1, SDL_RENDERER_ACCELERATED ),
            sdl_deleter());

    if( !renderer ) {
        printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
        return false;
    }

    gRenderer = std::move(renderer);

    SDL_SetRenderDrawColor( gRenderer.get(), 0xFF, 0xFF, 0xFF, 0xFF );

    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) ) {
        printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        return false;
    }
    return true;
}

bool GrapicalOutput::loadMedia() {
    Tileset set;
    set.loadBaseTheme();
    //set.loadSWTheme();
    SDL_Surface* loadedSurface = nullptr;

    for (auto &tiles : set.themeSet) {
        auto path = "../Tiles/" + tiles.second;
        loadedSurface = IMG_Load(path.c_str());

        std::unique_ptr<SDL_Texture, sdl_deleter> newTexture(
                                    SDL_CreateTextureFromSurface(gRenderer.get(), loadedSurface),
                                    sdl_deleter());

        pictures[tiles.first] = std::move(newTexture);
    }

    SDL_FreeSurface(loadedSurface);

    SDL_Rect bg = dParts.window.getRect();
    SDL_RenderCopy(gRenderer.get(), pictures["Splash"].get(), nullptr, &bg);
    SDL_RenderPresent(gRenderer.get());
    SDL_Delay(500);

    return true;
}

void GrapicalOutput::setResource(std::shared_ptr<GameParts> parts) {
    game = parts;
}

void GrapicalOutput::close() {
    pictures.clear();
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

    SDL_RenderClear(gRenderer.get());

    SDL_Rect bg = dParts.window.getRect();
    SDL_RenderCopy(gRenderer.get(), pictures["Board"].get(), nullptr, &bg);

    drawBoard();
    drawSelection();
    drawButtons();

    SDL_RenderPresent(gRenderer.get());

}

void GrapicalOutput::drawSelection() {
    if (game->selected < 0) return;
    int index = game->selected;
    DPBase obj = dParts.board.getCoords(index);
    if (index>99) obj = dParts.stash.getCoords(index-100);
    SDL_SetRenderDrawColor( gRenderer.get(), 0x00, 0xFF, 0x00, 0xFF );
    SDL_Rect sel = dParts.field.getRect(obj);
    SDL_RenderDrawRect(gRenderer.get(), &sel);
    sel.x++; sel.y++; sel.w -= 2; sel.h -= 2;
    SDL_RenderDrawRect(gRenderer.get(), &sel);
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
    SDL_RenderCopy(gRenderer.get(), pictures[name].get(), nullptr, &btn);
}

void GrapicalOutput::drawBoard() {

    for (int i= 0; i<40; i++) {
        if ((*game->stash)[i]) {
            std::string name = (*game->stash)[i]->getShortName();
            DPBase obj = dParts.stash.getCoords(i);
            SDL_Rect ins = dParts.field.getRect(obj);
            SDL_RenderCopy(gRenderer.get(), pictures[name].get(), nullptr, &ins);
        }
    }

    for (int i= 0; i<100; i++) {
        if ((*game->board)[i]) {
            std::string name = (*game->board)[i]->getShortName();
            DPBase obj = dParts.board.getCoords(i);
            SDL_Rect ins = dParts.field.getRect(obj);
            SDL_RenderCopy(gRenderer.get(), pictures[name].get(), nullptr, &ins);
        }
    }
}


