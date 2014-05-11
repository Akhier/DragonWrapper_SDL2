#include "drw_sdl2.h"

DrW_SDL2::DrW_SDL2()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
       _logerror("SDL_Init");
    }
    if (TTF_Init() != 0){
       _logerror("TTF_Init");
    }
}

DrW_SDL2::~DrW_SDL2()
{
    //dtor
}
