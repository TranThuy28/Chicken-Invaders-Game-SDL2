#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Vector 2D.h"
#include"SDL.h"
class Transform
{
    public:
         float X,Y;
    public:
        Transform(float x =0, float y=0):X(x), Y(y) {;}
        void Log(std::string tmp ="" ) {
        cout << tmp << "(x y) = (" << X << " "<< Y<< ")"<< endl;
        }

        inline void TranslateY(float x) {X +=X;Y += x;}
        inline void Translate(float x){X += x;
             Y= 120 - 70*cos(X*3.14/180);
        }
        inline void TranslateX(float x){
             X += x;
             Y = 100-60*sin(X*3.14/180);


        }
        inline void Reverse(float x) {

           X -= x;
           Y = 100-60*sin(X*3.14/180);
        }
        inline void TranslateBullet(float y) {Y -= y;}

};

#endif // TRANSFORM_H
