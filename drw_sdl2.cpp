#include "drw_sdl2.h"

DrW_SDL2::DrW_SDL2()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
       _logerror("SDL_Init");
    }
    if (IMG_Init(IMG_INIT_PNG) != 0){
        _logerror("IMG_Init");
    }
    if (TTF_Init() != 0){
       _logerror("TTF_Init");
    }
}

void DrW_SDL2::_logerror(const std::string &message){
    std::cout << message << " Error: " << SDL_GetError() << std::endl;
}

SDL_Texture* DrW_SDL2::_loadtexture(const std::string &file){
    SDL_Texture* outputTexture = IMG
}

DrW_SDL2::~DrW_SDL2()
{
    //dtor
}
