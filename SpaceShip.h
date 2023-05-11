#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Character.h"
#include "SDL.h"
//#include "Animation.h"
class SpaceShip : public Character
{
    public:
       SpaceShip(Element* ele) ;

       virtual void Draw();
       virtual void Update(float dt);
       virtual void Clean();

       virtual Transform* GetTransform(){
         return t_Transform;
         }
      static SpaceShip* s_Game;

       int t_Row, t_Frame, t_FrameCount;
       int t_AnimaSpeed;
        //Animation* t_Animation;
};


#endif // SPACESHIP_H
