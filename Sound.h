#ifndef SOUND_H
#define SOUND_H

#include <map>
#include <string>
#include<iostream>
#include "SDL_mixer.h"

#define FREQ 44100
#define CHUNK_SIZE 2048

using EffectMap = std::map<std::string, Mix_Chunk*>;
using MusicMap = std::map<std::string,Mix_Music*>;

class Sound
{
    public:

       void Clean();

       void PlayMusic(std::string id);
       void LoadMusic(std::string id, std::string source);

       void PlayEffect(std::string id);
       void LoadEffect(std::string id, std::string source);

       inline static Sound* GetGame(){
         return s_game = (s_game != nullptr) ? s_game : new Sound();
       }



    private:
         Sound();
         MusicMap t_MusicMap;
         EffectMap t_EffectMap;
         static Sound* s_game;
};

#endif // SOUND_H
