#include "drw_sdl2.h"

DrW_SDL2::DrW_SDL2(){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
       _logerror("SDL_Init");
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

SDL_Texture* DrW_SDL2::_rendertextastexture(const std::string &message, SDL_Color color){
    if (_font == nullptr){
        return nullptr;
    }
    SDL_Surface* tempSurface = TTF_RenderText_Blended(_font, message.c_str(), color);
    if (tempSurface == nullptr){
        _logerror("TTF_RenderText_Blended");
        return nullptr;
    }
    SDL_Texture* outputTexture = SDL_CreateTextureFromSurface(_renderer, tempSurface);
    if (outputTexture == nullptr){
        _logerror("SDL_CreateTextureFromSurface");
    }
    SDL_FreeSurface(tempSurface);
    return outputTexture;
}

void DrW_SDL2::createWindow(const std::string windowtitle, int x, int y, int width, int height, bool resizable){
    _window = SDL_CreateWindow(windowtitle.c_str(), x >= 0 ? x : SDL_WINDOWPOS_UNDEFINED, y >= 0 ? y : SDL_WINDOWPOS_UNDEFINED, width, height, resizable ? SDL_WINDOW_RESIZABLE : (SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE));
    if (_window == nullptr){
        _logerror("SDL_CreateWindow");
    }
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_renderer == nullptr){
        _logerror("SDL_CreateRenderer");
    }
}
void DrW_SDL2::createWindow(const std::string windowtitle, int width, int height, bool resizable){
    createWindow(windowtitle, -1, -1, width, height, resizable);
}

int DrW_SDL2::createText(const std::string &message){
    SDL_Color color = {0, 0, 0, 255};
    _textures.push_back(_rendertextastexture(message, color));
    return _textures.size() - 1;
}

int DrW_SDL2::createTexture(const std::string &file){
    _textures.push_back(_loadtexture(file));
    return _textures.size() - 1;
}

void DrW_SDL2::_rendertexture(const int textureid, const SDL_Rect* source, const SDL_Rect* destination){
    SDL_RenderCopy(_renderer, _textures[textureid], source, destination);
}

Rect DrW_SDL2::_gettexturesize(const int textureid, int x, int y){
    Rect output(x, y);
    SDL_QueryTexture(_textures[textureid], NULL, NULL, &output.W, &output.H);
    return output;
}

void DrW_SDL2::renderTexture(const int textureid, Rect destination){
    _rendertexture(textureid, NULL, destination.getSDLRect());
}

void DrW_SDL2::renderTexture(const int textureid, int x, int y){
    renderTexture(textureid, _gettexturesize(textureid, x, y));
}

void DrW_SDL2::renderTexture(const int textureid, Rect source, Rect destination){
    _rendertexture(textureid, source.getSDLRect(), destination.getSDLRect());
}

void DrW_SDL2::renderTexture(const int textureid, Rect source, int x, int y){
    renderTexture(textureid, source, _gettexturesize(textureid, x, y));
}

void DrW_SDL2::renderclear(){
    SDL_RenderClear(_renderer);
}

void DrW_SDL2::renderpresent(){
    SDL_RenderPresent(_renderer);
}

DrW_SDL2::~DrW_SDL2(){
    for (size_t iter = 0; iter < _textures.size(); ++iter){
        SDL_DestroyTexture(_textures[iter]);
    }
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}
