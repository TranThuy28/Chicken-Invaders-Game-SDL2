#ifndef TEXTOBJECT_H
#define TEXTOBJECT_H
#include "Character.h"
#include "TextureManager.h"
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include<ostream>
#include <string>
class TextObject
{
    public:
         string str_val_;
    SDL_Color text_color_;
    SDL_Texture* texture_;
    int width_;
    int height_;
    SDL_Rect renderQuad;
    SDL_Surface* text_surface;
    TextObject(){
    text_color_.r = 255;
    text_color_.g = 255;
    text_color_.b = 255;
    texture_ = nullptr ;
    }
    ///~textObject();


    bool LoadFromFile(string path);
    bool LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen){
         text_surface = TTF_RenderText_Solid(font, GetText().c_str(), text_color_);
        if(text_surface)
        {
        texture_ = SDL_CreateTextureFromSurface(screen, text_surface);
        width_ = text_surface->w ;
        height_ = text_surface->h;
        SDL_FreeSurface(text_surface);
        }
    return texture_!= NULL;
    }
    void Free();
    void SetColor(Uint8 red, Uint8 green, Uint8 blue);
    void SetColor(int type);
    void RenderText(SDL_Renderer* screen,
                    int xp,int yp,
                    SDL_Rect* clip = NULL,
                    double angle = 0.0,
                    SDL_Point* center = NULL,
                    SDL_RendererFlip flip = SDL_FLIP_NONE){

          renderQuad = {xp,yp,GetWidth(), GetHeight()};
         if(clip != nullptr){
            renderQuad.w = clip->w ;
            renderQuad.h = clip->h;
         }
         SDL_RenderCopyEx(screen, texture_, clip, &renderQuad, angle, center, flip);

    }
    int GetWidth()const{
        return this->width_;
    }
    int GetHeight()const{
    return this->height_;
    }

    void SetText(const string& text){
        str_val_ = text ;
    }
    string GetText()const{
        return str_val_;
    }

   virtual SDL_Rect GetRect()const{
       SDL_Rect a;
       a.x = renderQuad.x;
       a.y = renderQuad.y;
       a.w = renderQuad.w;
       a.h = renderQuad.h;
    return a;
     }

};

#endif // TEXTOBJECT_H
