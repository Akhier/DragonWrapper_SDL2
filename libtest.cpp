#include "drw_sdl2.h"

const int SCREEN_WIDTH = 640, SCREEN_HEIGHT = 480;

int main(int argc, char **argv){
    DrW_SDL2 sdl;
    sdl.createWindow("test window", SCREEN_WIDTH, SCREEN_HEIGHT, true);
    int test = sdl.createTexture("TestTexture.png");
    sdl.renderclear();
    sdl.renderTexture(test, 10, 10);
    sdl.renderpresent();
    SDL_Delay(2000);
    return 0;
}
