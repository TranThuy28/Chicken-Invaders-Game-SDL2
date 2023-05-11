#include "Egg.h"
#include "TextureManager.h"
Egg::Egg(Element* ele) : Character(ele)
{

}

void Egg::Draw()
{
    TextureManager::GetGame()->Draw(t_TextureID,t_Transform->X, t_Transform->Y,G_Width,G_Height,G_Degree);
}

void Egg::Update(float dt)
{
    t_Transform->TranslateY(dt);
}

void Egg::Clean()
{

}

SDL_Rect Egg::GetRect()
{

}
