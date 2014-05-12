#include "drw_sdl2_rect.h"

Rect::Rect(int x, int y, int w, int h){
    X = x;
    Y = y;
    W = w;
    H = h;
}

Rect::Rect(int x, int y){
    X = x;
    Y = y;
    W = -1;
    H = -1;
}

SDL_Rect Rect::getSDLRect(){
    SDL_Rect output;
    output.x = X;
    output.y = Y;
    output.w = W;
    output.h = H;
    return output;
}
