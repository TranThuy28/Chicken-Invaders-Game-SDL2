#include "EventHandle.h"
#include "GameManager.h"
#include "GameObject.h"
#include "SpaceShip.h"
#include "TextureManager.h"
#include "Bullet.h"
#include <ostream>
EventHandle* EventHandle::s_Game = nullptr;


void EventHandle::Input(float &x, float &y)
{

    while(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:{
            GameManager::GetGame()->Quit();
            break;
        }
        case SDL_MOUSEMOTION:
           x= event.motion.x;
           y= event.motion.y;
           break;
        case SDL_MOUSEBUTTONDOWN:
            GetMouseButtonDown = true;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym){
          case SDLK_SPACE:{
            KeyDown();
            break;
          }
            }

        }

    }
}
void EventHandle::KeyDown()
{
    t_KeyStates = SDL_GetKeyboardState(nullptr);
}
bool EventHandle::GetKeyDown(SDL_Scancode key)
{
    if(t_KeyStates[key] == 1){
        return true;
    }
    else return false;
}


EventHandle::EventHandle()
{
 t_KeyStates = SDL_GetKeyboardState(nullptr);
}
