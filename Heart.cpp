#include "Heart.h"
#include "TextureManager.h"
#include "GameManager.h"
#include "SDL.h"
#include "TextObject.h"
#include "SDL_ttf.h"

Heart::Heart(Element* ele) : Character(ele)
{
  HeartNum = 3;
  }

void Heart::Update(float dt)
{
if(GameManager::GetGame()->COLLISION()== true) {
        count++;
        if(count <10) {
    HeartNum =2;}
    if(count >10 && count <20) {HeartNum =1;}
    if(count >20) {HeartNum =0;}
    if(HeartNum ==0) {
            SDL_RenderClear(GameManager::GetGame()->GetRenderer());
        TextObject lose;
        TTF_Font* font = NULL;
        font = TTF_OpenFont("./font//font3.ttf",24);
        lose.SetColor(255,0,0);
        lose.SetText("You    lose !!!");
         if(!lose.LoadFromRenderText(font,GameManager::GetGame()->GetRenderer())){
    SDL_Log("khong tai texture dc cho chu");
}
    lose.RenderText(GameManager::GetGame()->GetRenderer(),300,290);
SDL_RenderPresent(GameManager::GetGame()->GetRenderer());

    }
}

}

void Heart::Draw()
{
    for(int i =1; i<= HeartNum; i++) {
    TextureManager::GetGame()->Draw(t_TextureID,t_Transform->X -i*G_Width/7,t_Transform->Y,G_Width,G_Height,G_Degree); }
}

void Heart::Clean()
{
    TextureManager::GetGame()->Drop(t_TextureID);
}
