#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include<string>
#include<SDL_mixer.h>
#define SCREEN_WIDTH 700
#define SCREEN_HEIGHT 600

//SpaceShip* player = nullptr;
class GameManager
{
    public:

        static GameManager* GetGame() {
          return s_game = (s_game != nullptr) ? s_game
                                              : new GameManager();
        }

        bool Init();
        bool Clean();
        void Quit();
        void Update();
        void Render();
        void Events();
        bool COLLISION();

         std::string index = "0";
         int count =0;
     inline bool IsRunning() { return t_isRunning;}

     inline SDL_Renderer* GetRenderer(){
        return t_renderer;
    }

        GameManager(){};
        bool t_isRunning;
        SDL_Window* t_window;
        SDL_Renderer* t_renderer;
        bool level1 = true;
        bool level2 = false;
        static  GameManager* s_game;
};

#endif // GAMEMANAGER_H
