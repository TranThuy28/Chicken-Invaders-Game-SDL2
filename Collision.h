#ifndef COLLISION_H
#define COLLISION_H
#include "SDL.h"
#include "TextureManager.h"
#include "SpaceShip.h"
#include "Chicken.h"
#include "Character.h"
bool Collision (GameObject* player, GameObject* chicken);
class Colli : public Character
{
    public:
        Colli(Element* ele);

       virtual void Draw();
       virtual void Update(float dt);
       virtual void Clean();

       virtual SDL_Rect GetRect();

        int t_Row, t_Frame, t_FrameCount;
       int t_AnimaSpeed;
};


#endif // COLLISION_H
