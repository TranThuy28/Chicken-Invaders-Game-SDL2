/*
#ifndef ANIMATION_H
#define ANIMATION_H

#include "SDL.h"
#include<bits/stdc++.h>
class Animation
{
    public:
        Animation(){};

       void Update();
       void Draw(float x, float y, int spriteWidth, int spriteHeight );
       void SetElement(std::string textureID, int spriteRow, int FrameCount, int animaSpeed, SDL_RendererFlip flip = SDL_FLIP_NONE);

    private:
       int t_SpriteRow, t_SpriteFrame;
        int t_AnimaSpeed, t_FrameCount;
        std::string t_TextureID;
        SDL_RendererFlip t_Flip;

#endif // ANIMATION_H
*/
