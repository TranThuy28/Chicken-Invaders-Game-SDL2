#ifndef INTERFACEOJECT_H
#define INTERFACEOJECT_H
#include<bits/stdc++.h>

class InterfaceOject
{
   public:
       virtual void Draw()=0;
       virtual void Update(float dt) =0;
       virtual void Clean()=0;
};

#endif // INTERFACEOJECT_H
