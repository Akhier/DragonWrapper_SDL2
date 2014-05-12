#include "drw_sdl2.h"

const int SCREEN_WIDTH = 640, SCREEN_HEIGHT = 480;

int main(int argc, char **argv){
    DrW_SDL2 sdl;
    sdl.createWindow("test window", SCREEN_WIDTH, SCREEN_HEIGHT, true);
    int test = sdl.createTexture("TestTexture.png");
    int solidPink = sdl.setupTileset(test, Rect(1, 1, 20, 20));
    int halfandhalf = sdl.setupTileset(test, Rect(22, 1, 20, 20));
    int solidBlue = sdl.setupTileset(test, Rect(43, 1, 20, 20));
    sdl.renderclear();
    sdl.renderTexture(test, sdl.getSourceRect(test, solidPink), Rect(20, 20, 20, 20));
    sdl.renderTexture(test, sdl.getSourceRect(test, solidBlue), Rect(40, 40, 20, 20));
    sdl.renderTexture(test, sdl.getSourceRect(test, halfandhalf), Rect(40, 20, 20, 20));
    sdl.renderTexture(test, sdl.getSourceRect(test, halfandhalf), Rect(20, 40, 20, 20));
    sdl.setFont("fonts/freeserif.ttf", 16);
    int text = sdl.createText("test");
    sdl.renderTexture(text, 20, 20);
    sdl.renderpresent();
    SDL_Delay(2000);
    return 0;
}
