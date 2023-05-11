#include "BackGround.h"
#include "TextureManager.h"
#include "SDL.h"
BackGround::BackGround(Element* ele) : Character(ele)
{
    t_Row =1;
    t_FrameCount =6;
    t_AnimaSpeed =70;
}

void BackGround::Draw()
{
    TextureManager::GetGame()->DrawFrame(t_TextureID,t_Transform->X,t_Transform->Y,G_Width,G_Height,t_Row,t_Frame,G_Degree);
}

void BackGround::Update(float dt)
{
     t_Frame = (SDL_GetTicks()/t_AnimaSpeed) % t_FrameCount;
}

void BackGround::Clean()
{
    TextureManager::GetGame()->Clean();
}
