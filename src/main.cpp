/*
 * It's probably not a good idea to mix wxWidgets and sdl, but here we go
 */

#include "SDL.h" // SDL has to be included before main(), well okay I guess there's a way but this works good enough
#include "GuiWx.hpp"

//we want these later and I'm lazy
int mainArgc;
char** mainArgv;

int main(int argc, char** argv) {
    GuiWx* gui = new GuiWx();
    wxApp::SetInstance(gui);

    mainArgc = argc;
    mainArgv = argv;

    return wxEntry(argc, argv);
}
