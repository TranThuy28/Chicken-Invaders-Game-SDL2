#include "Sound.h"
#include<ostream>
Sound* Sound::s_game = nullptr;
Sound::Sound()
{
    if(Mix_OpenAudio(FREQ, MIX_DEFAULT_FORMAT,3,CHUNK_SIZE) <0) {

        std::cerr << Mix_GetError() << std::endl;
    }
}

void Sound::PlayMusic(std::string id)
{
    Mix_PlayMusic(t_MusicMap[id],-1);
 if(Mix_PlayMusic(t_MusicMap[id],-1)== -1) {
    std::cerr << Mix_GetError() << ": " << id << std::endl;
 }
}

void Sound::LoadMusic(std::string id, std::string source)
{
Mix_Music* music = Mix_LoadMUS(source.c_str());
if(music != nullptr) {
    t_MusicMap[id] = music;
}
else {
    std::cerr << Mix_GetError() << ": " <<source << std::endl;
}
}

/// effect sound
void Sound::PlayEffect(std::string id)
{
if(Mix_PlayChannel(-1,t_EffectMap[id],0)== -1) {
    std::cerr << Mix_GetError() << ": " << id << std::endl;
}
}

void Sound::LoadEffect(std::string id, std::string source)
{
Mix_Chunk* effect = Mix_LoadWAV(source.c_str());
if(effect != nullptr) {
    t_EffectMap[id] = effect;
}
else{
    std::cerr << Mix_GetError() << " :" << source << std::endl;
}
}
void Sound::Clean()
{
    for(MusicMap::iterator iter = t_MusicMap.begin(); iter != t_MusicMap.end();iter++) {
        Mix_FreeMusic(iter->second);
    }
    for(EffectMap::iterator iter = t_EffectMap.begin(); iter != t_EffectMap.end();iter++) {
        Mix_FreeChunk(iter->second);
    }
    t_MusicMap.clear();
    t_EffectMap.clear();
    std::cout << "sound system cleared" << std::endl;
}
