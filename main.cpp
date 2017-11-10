
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


SDL_Window* gWindow = nullptr;
SDL_Renderer* gRenderer = nullptr;

//Current displayed texture
SDL_Texture* board = nullptr;
SDL_Texture* bomb = nullptr;
SDL_Texture* bckgr = nullptr;

bool init() {
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        return false;
    }
    //Set texture filtering to linear
    if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) ) {
        printf( "Warning: Linear texture filtering not enabled!" );
    }
    //Create window
    gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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

SDL_Texture* loadTexture( std::string path ) {
    //The final texture
    SDL_Texture* newTexture = nullptr;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if(!loadedSurface) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    } else {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
        if(!newTexture) {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }
        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }
    return newTexture;
}

bool loadMedia() {
    board = loadTexture( "../Pics/Base_Board.png" );
    bomb = loadTexture( "../Pics/Selection_120.png" );
    bckgr = loadTexture("../Pics/BGR.jpg");
    if(!board) {
        printf( "Failed to load texture image!\n" );
    }
    return true;
}

void close()
{
    //Free loaded image
    SDL_DestroyTexture( board );
    board = nullptr;
    bomb = nullptr;
    bckgr = nullptr;

    //Destroy window
    SDL_DestroyRenderer( gRenderer );
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gRenderer = nullptr;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

int main( int argc, char* args[] ) {
    //Start up SDL and create window
    if( !init() ) {
        printf( "Failed to initialize!\n" );
    } else {
        //Load media
        if( !loadMedia() ) {
            printf( "Failed to load media!\n" );
        } else {
            //Clear screen
            SDL_RenderClear( gRenderer );

            //set bg coordinates and render bg into it
            SDL_Rect bg = { 0, 0, 600, 600 };
            SDL_RenderCopy( gRenderer, board, nullptr, &bg );

            //same for bomb
            SDL_Rect ins = {130, 130, 50, 50};
            SDL_RenderCopy( gRenderer, bomb, nullptr, &ins );

            //show
            SDL_RenderPresent( gRenderer );

            bool quit = false;
            bool flipped = true;

            //Event handler
            SDL_Event e;

            //While application is running
            while( !quit ) {
                //Handle events on queue
                while( SDL_PollEvent( &e ) != 0 ) {

                    //if clicked (mouse button released)
                    if( e.type == SDL_MOUSEBUTTONUP) {

                        //ask for mouse button coordinates
                        int x, y;
                        SDL_GetMouseState( &x, &y );

                        //check if clicked on bomb
                        if (x<180 && x>130 && y<180 && y>130) {

                            //kill'em all and render bg in its place
                            SDL_RenderClear( gRenderer );
                            SDL_RenderCopy( gRenderer, board, nullptr, &bg );


                            //render bomb or card_bg depend on flipped state
                            if (flipped) {
                                SDL_RenderCopy( gRenderer, bckgr, nullptr, &ins );
                            } else {
                                SDL_RenderCopy( gRenderer, bomb, nullptr, &ins );
                            }

                            flipped = !flipped;
                            //show
                            SDL_RenderPresent( gRenderer );
                        }
                    }

                    //User requests quit
                    if( e.type == SDL_QUIT ) {
                        quit = true;
                    }
                }
            }
            SDL_Delay(500);
        }
    }
    //Free resources and close SDL
    close();
    return 0;
}
