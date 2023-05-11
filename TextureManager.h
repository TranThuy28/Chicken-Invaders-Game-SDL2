#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
#include<bits/stdc++.h>
#include "SDL.h"
#include "SDL_ttf.h"
#include<bits/stdc++.h>
using namespace std;
class TextureManager
{
    public:
      static TextureManager* GetGame() {
          return s_game = (s_game != nullptr) ? s_game
                                              : new TextureManager();
                }
      bool Load(std::string id, std::string filePath);

      void Drop(std::string id); /// remove texture from map
      void Clean();

      void Draw(std::string id, int x, int y, float width, float height,float degree, SDL_RendererFlip flip = SDL_FLIP_NONE);
      void DrawFrame(std::string id, int x, int y, float width, float height, int row, int frame, float degree,SDL_RendererFlip flip = SDL_FLIP_NONE);
       SDL_Rect GetRect() {
          return destinRect;
          }


        TextureManager(){};
     SDL_Rect destinRect;
        std::vector<SDL_Texture*> Texture;
        std::map<std::string, SDL_Texture*> t_TextureMap;
        static TextureManager* s_game;
};

#endif // TEXTUREMANAGER_H
