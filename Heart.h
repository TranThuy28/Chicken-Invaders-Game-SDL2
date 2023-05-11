#ifndef HEART_H
#define HEART_H
#include "Character.h"
#include "SDL.h"
#include <iostream>

class Heart : public Character
{
    public:

        Heart(Element* ele);
    virtual void Update(float dt);
    virtual void Draw();
    int count =0;
   virtual void Clean();
     int HeartNum;

};

#endif // HEART_H
