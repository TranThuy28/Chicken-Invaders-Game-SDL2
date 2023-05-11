#include "Chicken.h"
#include "TextureManager.h"
#include "GameManager.h"
#include "EventHandle.h"
#include "SDL.h"
Chicken* Chicken::s_game = nullptr;
Chicken::Chicken(Element* ele)  : Character(ele)
{
    demR =0;
    demL = 0;
     t_Row =1;
    t_FrameCount =7;
    t_AnimaSpeed =70;

}

void Chicken::Draw()
{
    TextureManager::GetGame()->DrawFrame(t_TextureID,t_Transform->X, t_Transform->Y,G_Width, G_Height,t_Row,t_Frame, G_Degree);
}

void Chicken::Update(float dt)
{

   t_Frame = (SDL_GetTicks()/t_AnimaSpeed) % t_FrameCount;
   if(t_Transform->X >=0) {
    if((demR ==0) || (demL ==1)) {
    t_Transform->TranslateX(dt);
    demR =0;}
    else {
        t_Transform->Reverse(dt);
        demL=0;
    }
    if(t_Transform->X <= 0) {demL =1;}
    if(t_Transform->X >= 650) {
        demR =1;
        demL =0;
    }
   }
 //  t_Transform->Log();
}
void Chicken::Update2(float dt)
{
     t_Frame = (SDL_GetTicks()/t_AnimaSpeed) % t_FrameCount;
    t_Transform->TranslateX(dt);
}

void Chicken::Chickens()
{

     TextureManager::GetGame()->DrawFrame(t_TextureID,t_Transform->X, t_Transform->Y,G_Width, G_Height,t_Row,t_Frame, G_Degree);
}

SDL_Rect Chicken::GetRect()
{
          SDL_Rect a;
a.x = t_Transform->X;
a.y = t_Transform->Y;
a.w = G_Width/G_Degree;
a.h = G_Height/G_Degree;

return a;
}
bool Chicken::Collision2(GameObject* smt)
{
    SDL_Rect a = smt->GetRect();
    std::cout << a.x << " " << a.y << std::endl;
    SDL_Rect b = Chicken::GetRect();
    if(SDL_HasIntersection(&a,&b)){
        std::cout << "da va cham" << std::endl;
        return true;
    }
    return false;
}


void Chicken::Clean()
{
    TextureManager::GetGame()->Drop(t_TextureID);
}
