#include "Graphics/GrapicalOutput.h"
#include "Graphics/Display.hpp"
#include "Graphics/UserInput.hpp"
#include "Graphics/MouseInput.h"
#include "Logic/Game.h"

Player* GameParts::player1;
Player* GameParts::player2;

Card* GameParts::p1stash[40];
Card* GameParts::p2stash[40];
Card* GameParts::board[100];

bool GameParts::okBtn;
bool GameParts::resetBtn;
bool GameParts::restartBtn;

int GameParts::selectedIndex;

int main( int argc, char* args[] ) {
    Game game;

    Display* display = new GrapicalOutput();
    UserInput* input = new MouseInput();

    game.setDisplay(display);
    game.setInput(input);

    game.start();

    display->close();

    return 0;
}
