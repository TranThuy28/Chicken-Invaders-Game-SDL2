#include "TextureManager.h"
#include "GameManager.h"
#include "TextObject.h"
#include <ostream>
TextureManager* TextureManager::s_game = nullptr;
bool TextureManager::Load(string id, string filePath)
{
    SDL_Surface* surface = IMG_Load(filePath.c_str());

    if(surface == nullptr) {
        SDL_Log(" khong tai duoc texture :", filePath.c_str(), SDL_GetError());
        return false;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(GameManager::GetGame()->GetRenderer(),surface);

    if(texture == nullptr) {
          SDL_Log(" Loi khi tao texture tu surface: ",SDL_GetError());
        return false;
    }
    t_TextureMap[id] = texture;

    return true;
}


void TextureManager::Draw(string id, int x, int y, float width, float height,float degree, SDL_RendererFlip flip)
{
    SDL_Rect sourceRect = {0,0, width, height};
             destinRect =  {x,y,width/degree, height/degree};
    SDL_RenderCopyEx(GameManager::GetGame()->GetRenderer(),t_TextureMap[id],&sourceRect, &destinRect,0,nullptr,flip);
}

void TextureManager::Drop(string id)
{

    SDL_DestroyTexture(t_TextureMap[id]);
    t_TextureMap.erase(id);
}
void TextureManager::DrawFrame(string id, int x, int y, float width, float height, int row, int frame, float degree,SDL_RendererFlip flip)
{
    SDL_Rect sourceRect = {width*frame, height*(row-1), width, height};
             destinRect = {x,y,width/degree, height/degree};
    //std::cout << destinRect.x << "," << destinRect.x+ destinRect.w << "," << destinRect.y << "," <<destinRect.h << std::endl;
    SDL_RenderCopyEx(GameManager::GetGame()->GetRenderer(),t_TextureMap[id],&sourceRect,&destinRect,0, nullptr,flip);
}


void TextureManager::Clean()
{
    ///  clear everything in the map
    map<string,SDL_Texture*>::iterator it;
    for(it = t_TextureMap.begin(); it != t_TextureMap.end();it++) {
        SDL_DestroyTexture(it->second);
    }
    t_TextureMap.clear();
    SDL_Log("clean all texture from map");
}

