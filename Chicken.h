#ifndef CHICKEN_H
#define CHICKEN_H
#include "Character.h"
#include "SDL.h"
class Chicken : public Character
{
    public:
        Chicken(Element* ele);

       virtual void Draw();
       virtual void Update(float dt);
       virtual void Clean();
       virtual void Chickens();
       virtual void Update2(float dt);
       virtual SDL_Rect GetRect();
       virtual bool Collision2 (GameObject* smt);
        static Chicken* s_game;
        int t_Row, t_Frame, t_FrameCount;
        int demR = 0;
        int demL = 0;
       int t_AnimaSpeed;
};

#endif // CHICKEN_H
