#ifndef BULLET_H
#define BULLET_H

#include "Character.h"
#include "SDL.h"
class Bullet : public Character
{
    public:
        //vector<Bullet*> bullet;
        Bullet(Element* ele) ;
       virtual void Draw();
       virtual void Update(float dt);
       virtual void Clean();
       virtual SDL_Rect GetRect();

};

#endif // BULLET_H
