#include "TextObject.h"
#include "GameManager.h"
#include <ostream>

void TextObject::Free(){
    if(texture_ != NULL){
        SDL_DestroyTexture(texture_);
        texture_ = NULL;

    }
}
void TextObject::SetColor(Uint8 red, Uint8 green, Uint8 blue){
    text_color_.r = red ;
    text_color_.g = green;
    text_color_.b = blue;
}
/*
void TextObject::SetColor(int type){
    if(type == RED_TEXT){
        SDL_Color color ={255, 0,0};
        text_color_= color;
    }
    else if(type == WHITE_TEXT){
        SDL_Color color ={255,255,255};
        text_color_=color;
    }
    else if(type == BLACK_TEXT){
        SDL_Color color ={0,0,0};
        text_color_ = color ;
    }
}
*/
bool TextObject::LoadFromFile(string path)
{

}
