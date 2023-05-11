#include "Collision.h"
#include "TextureManager.h"
#include <ostream>
#include "SDL.h"
bool Collision(GameObject* player, GameObject* chicken)
{
SDL_Rect a,b;
  a.x= player->GetRect().x;
  a.w= player->GetRect().w;
  a.y = player->GetRect().y;
  a.h = player->GetRect().h ;

  b.x = chicken->GetRect().x;
  b.w =  chicken->GetRect().w;
  b.y = chicken->GetRect().y;
  b.h = chicken->GetRect().h;


 if(SDL_HasIntersection(&a,&b)){
    return true;
 }
 return false;


}
Colli::Colli(Element* ele) : Character(ele)
{
     t_Row =1;
    t_FrameCount =5;
    t_AnimaSpeed =90;
}

void Colli::Draw()
{
    TextureManager::GetGame()->DrawFrame(t_TextureID,t_Transform->X,t_Transform->Y,G_Width,G_Height,t_Row,t_Frame,G_Degree);
}

void Colli::Update(float dt)
{
     t_Frame = (SDL_GetTicks()/t_AnimaSpeed) % t_FrameCount;
}

void Colli::Clean()
{
    TextureManager::GetGame()->Drop(t_TextureID);
}

SDL_Rect Colli::GetRect()
{

}

