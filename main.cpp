#include "Graphics/GrapicalOutput.h"
#include "Graphics/Display.hpp"
#include "Graphics/UserInput.hpp"
#include "Graphics/MouseInput.h"

int main( int argc, char* args[] ) {
    Display* display = new GrapicalOutput();
    UserInput* input = new MouseInput();

    display->printOut();

    bool quit = false;
    while(!quit) {
        if (input->getUserInput() == UserInput::QUIT) {
            quit = true;
        }
    }

    display->close();
    return 0;
}
