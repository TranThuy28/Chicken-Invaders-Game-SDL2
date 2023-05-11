#ifndef MENU_H
#define MENU_H
#include "GameObject.h"
#include<string>
#include<vector>
#include "TextObject.h"
#include "GameManager.h"
#include "EventHandle.h"
#include "SDL.h"
class Menu : public GameObject
{
    public:

        Menu() {
           t_font3 = TTF_OpenFont("./font//font3.ttf",22);

         playButton.SetColor(255,255,255);
         playButton.SetText("Play");

        }

       virtual void Draw(){
             if(!playButton.LoadFromRenderText(t_font3,GameManager::GetGame()->GetRenderer()){
            SDL_Log("Khong load dc menu");
             }
       }
       virtual void Update(){
           Vector2D t_Pos;
           EventHandle::GetGame()->Input(t_Pos->X;t_Pos->Y);
           SDL_Point point = {t_Pos->X, t_Pos->Y};
           if(SDL_PointInRect(&point,&playButton.GetRect())){
               if(EventHandle::GetGame()->GetMouseButtonDown && is_Released){
                    is_Released = false;
                    play = true;
                    playButton.Free();
                 //playButton.SetColor(255,0,0);
                  }
                else if(!EventHandle::GetGame()->GetMouseButtonDown) {
                    is_Released = true;
                    playButton.SetColor(255,0,0);
                }
          }
       }
       virtual void Clean(){

       }

        TTF_Font* t_font3 = NULL;
        TextObject playButton;
        bool play= false;
        bool is_Released;
        SDL_Event t_event;
        static Menu* s_game = nullptr;
};

#endif // MENU_H
