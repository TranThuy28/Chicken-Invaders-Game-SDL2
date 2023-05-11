#ifndef CHARACTER_H
#define CHARACTER_H
#include "GameObject.h"
class Character : public GameObject
{
    public:
        Character(Element* ele) : GameObject(ele) {};

       virtual void Draw()=0;
       virtual void Update(float dt) =0;
       virtual void Clean()=0;

        std::string Name;

};

#endif // CHARACTER_H
