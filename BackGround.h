#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Character.h"
class BackGround : public Character
{

    public:
        BackGround(Element* ele);

       virtual void Draw();
       virtual void Update(float dt);
       virtual void Clean();



        int t_Row, t_Frame, t_FrameCount;
       int t_AnimaSpeed;

};

#endif // BACKGROUND_H
