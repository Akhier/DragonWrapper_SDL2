#ifndef RECT_H
#define RECT_H

#include <SDL.h>

class Rect{
    public:
        Rect(int x, int y, int w, int h);
        Rect(int x, int y);
        int X, Y, W, H;
    private:
        SDL_Rect getSDLRect();
    friend class DrW_SDL2;
};

#endif // RECT_H
