#include "SpaceShip.h"
#include "TextureManager.h"
#include "EventHandle.h"
#include "SDL.h"
#include "Bullet.h"
#include "GameManager.h"
#include "Chicken.h"
#include <vector>

#include <ostream>
using namespace std;
SpaceShip* SpaceShip::s_Game = nullptr;
SpaceShip::SpaceShip(Element* ele) : Character(ele)
{
    t_Row =1;
    t_FrameCount =2;
    t_AnimaSpeed =80;

}

void SpaceShip::Draw()
{

   TextureManager::GetGame()->DrawFrame(t_TextureID,t_Transform->X,t_Transform->Y,G_Width,G_Height,t_Row,t_Frame,G_Degree);
}


void SpaceShip::Update(float dt)
{

   EventHandle::GetGame()->Input(t_Transform->X,t_Transform->Y);
   t_Frame = (SDL_GetTicks()/t_AnimaSpeed) % t_FrameCount;
}


void SpaceShip::Clean()
{
TextureManager::GetGame()->Clean();
}
