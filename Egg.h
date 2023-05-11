#ifndef EGG_H
#define EGG_H
#include "Character.h"

class Egg : public Character
{ public:
        Egg(Element* ele);

       virtual void Draw();
       virtual void Update(float dt);
       virtual void Clean();

       virtual SDL_Rect GetRect();


};
#endif // EGG_H
