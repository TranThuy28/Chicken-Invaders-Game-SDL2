/*
#include "Animation.h"
#include "TextureManager.h"

void Animation::Update()
{
      t_SpriteFrame = (SDL_GetTicks()/t_AnimaSpeed) % t_FrameCount;
}

void Animation::Draw(float x, float y, int spriteWidth, int spriteHeight)
{
     TextureManager::GetGame()->DrawFrame(t_TextureID,x,y,spriteWidth,spriteHeight,t_SpriteRow,t_SpriteFrame,1);
}



void Animation::SetElement(std::string textureID, int spriteRow, int FrameCount, int animaSpeed, SDL_RendererFlip flip)
{
    t_TextureID = textureID;
    t_SpriteRow = spriteRow;
    t_FrameCount= FrameCount;
    t_AnimaSpeed = animaSpeed;
    t_Flip = flip;
}
*/
