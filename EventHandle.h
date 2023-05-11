#ifndef EVENTHANDLE_H
#define EVENTHANDLE_H

#include "SDL.h"
#include "Vector 2D.h"
class EventHandle
{

    public:
        SDL_Event event;
     static EventHandle* GetGame() {
          return s_Game= (s_Game != nullptr) ? s_Game : new EventHandle();
     }
    void Input(float &x, float &y);
    void GetMouseMotion(float &x, float& y) {
      x = event.motion.x;
      y = event.motion.y;
    }
    bool PressSpace = false;
    bool GetKeyDown(SDL_Scancode key);
    bool GetMouseButtonDown = false;
        EventHandle();
        void KeyDown();
        const Uint8* t_KeyStates;
       // Uint32 buttons;
        static EventHandle* s_Game;
};

#endif // EVENTHANDLE_H
