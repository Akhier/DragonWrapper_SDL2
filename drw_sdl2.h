#ifndef DRW_SDL2_H
#define DRW_SDL2_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <map>
#include <vector>
#include "drw_sdl2_rect.h"

class DrW_SDL2
{
    public:
        DrW_SDL2();
        void createWindow(const std::string windowtitle, int x, int y, int width, int height, bool resizable);
        void createWindow(const std::string windowtitle, int width, int height, bool resizable);
        int createText(const std::string &message);
        int createTexture(const std::string &file);
        void renderTexture(const int textureid, Rect destination);
        void renderTexture(const int textureid, int x, int y);
        void renderTexture(const int textureid, Rect source, Rect destination);
        void renderTexture(const int textureid, Rect source, int x, int y);
        void renderclear();
        void renderpresent();
        int setupTileset(const int textureid, Rect source);
        Rect getSourceRect (const int textureid, const int tileid);
        virtual ~DrW_SDL2();
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;
        TTF_Font* _font;
        std::vector<SDL_Texture*> _textures;
        void _logerror (const std::string &message);
        SDL_Texture* _loadtexture (const std::string &file);
        SDL_Texture* _rendertextastexture (const std::string &message, SDL_Color color);
        void _rendertexture(const int textureid, const SDL_Rect* source, const SDL_Rect* destination);
        Rect _gettexturesize(const int textureid, int x, int y);
        std::map<int, std::vector<Rect>> _tilesetdefinition;
};

#endif // DRW_SDL2_H
