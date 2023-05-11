#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "InterfaceOject.h"
#include "Transform.h"
#include "SDL.h"
struct Element {
    public:
    Element(std::string textureID, int x, int y, float width, float height, float degree,SDL_RendererFlip flip= SDL_FLIP_NONE){
            X = x;
            Y=y;
            Flip = flip;
            Width = width;
            Height = height;
            TextureID = textureID;
            Degree = degree;

    }
  public:
    std::string TextureID;
    float Width, Height;
    float Degree;
    float X,Y;
    SDL_RendererFlip Flip;
};

class GameObject : public InterfaceOject
{
    public:
        GameObject(Element* ele): t_TextureID(ele->TextureID),
        G_Width(ele->Width),G_Height(ele->Height),t_Flip(ele->Flip), G_Degree(ele->Degree){

              t_Transform = new Transform(ele->X,ele->Y);
        }

       virtual void Draw()=0;
       virtual void Update(float dt) =0;
       virtual void Clean()=0;
       virtual SDL_Rect GetRect(){
          SDL_Rect a;
a.x = t_Transform->X;
a.y = t_Transform->Y;
a.w = G_Width/G_Degree;
a.h = G_Height/G_Degree;

return a;
       }
       virtual Transform* GetTransform(){
             return t_Transform;
        }
        Transform* t_Transform;
        float G_Width, G_Height;
        float G_Degree;
        std::string t_TextureID;
        SDL_RendererFlip t_Flip;

};

#endif // GAMEOBJECT_H
