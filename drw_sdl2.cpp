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
    SDL_Texture* outputTexture = IMG_LoadTexture(_renderer, file.c_str());
    if (outputTexture == nullptr){
        _logerror("IMG_LoadTexture");
    }
    return outputTexture;
}

SDL_Texture* DrW_SDL2::_rendertextastexture(const std::string &message){
    if (_font == nullptr){
        return nullptr;
    }
    SDL_Surface* tempSurface = TTF_RenderText_Blended(_font, message.c_str(), color);
    if (tempSurface == nullptr){
        _logerror("TTF_RenderText_Blended")
        return nullptr;
    }
    SDL_Texture* outputTexture = SDL_CreateTextureFromSurface(_renderer, tempSurface);
    if (outputTexture == nullptr){
        _logerror("SDL_CreateTextureFromSurface");
    }
    SDL_FreeSurface(tempSurface);
    return outputTexture;
}

DrW_SDL2::~DrW_SDL2()
{
    //dtor
}
