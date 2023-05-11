#include "Bullet.h"
#include "TextureManager.h"
Bullet::Bullet(Element* ele) : Character(ele)
{

}

void Bullet::Draw()
{
    TextureManager::GetGame()->Draw(t_TextureID,t_Transform->X,t_Transform->Y,G_Width,G_Height,G_Degree);
}

void Bullet::Update(float dt)
{

    t_Transform->TranslateBullet(5);

}
SDL_Rect Bullet::GetRect()
{
    SDL_Rect a;
a.x = t_Transform->X;
a.y = t_Transform->Y;
a.w = G_Width/1.5;
a.h = G_Height/1.5;

return a;
}


void Bullet::Clean()
{
TextureManager::GetGame()->Drop(t_TextureID);
}
