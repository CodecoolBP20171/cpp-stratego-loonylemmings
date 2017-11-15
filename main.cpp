#include "Graphics/GrapicalOutput.h"
#include "Graphics/Display.hpp"
#include "Graphics/UserInput.hpp"
#include "Graphics/MouseInput.h"
#include "Logic/Game.h"

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
