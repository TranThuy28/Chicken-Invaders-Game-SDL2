
#include "GameManager.h"
#include "Sound.h"
#include "TextObject.h"
#include "SDL_ttf.h"
#include "EventHandle.h"
#include "GameObject.h"
using namespace std;
int main(int argc, char* argv[]) {
   GameManager::GetGame()->Init();
   SDL_AudioSpec wavSpec;
Uint32 wavLength;
Uint8* wavBuffer;

SDL_Init(SDL_INIT_AUDIO);

TTF_Init();
TextObject playButton;
TextObject quit;
TTF_Font* t_font3;
  t_font3 = TTF_OpenFont("./font//font3.ttf",26);
  playButton.SetColor(225,255,255);
  playButton.SetText("Play");
  quit.SetColor(128,255,0);
  quit.SetText("Quit");
  bool play = false;
   Vector2D t_Pos;
   while(true){
         SDL_RenderClear(GameManager::GetGame()->GetRenderer());
          if(!quit.LoadFromRenderText(t_font3,GameManager::GetGame()->GetRenderer())){
        SDL_Log("Khong load dc quit button");
       }
          quit.RenderText(GameManager::GetGame()->GetRenderer(),320,290);
   if(!playButton.LoadFromRenderText(t_font3,GameManager::GetGame()->GetRenderer())){
        SDL_Log("Khong load dc play button");
       }
          playButton.RenderText(GameManager::GetGame()->GetRenderer(),320,250);


           EventHandle::GetGame()->Input(t_Pos.X,t_Pos.Y);
           SDL_Point point = {t_Pos.X, t_Pos.Y};

           SDL_Rect temp; temp.x =320; temp.y =250; temp.w = 60; temp.h = 30;
           SDL_Rect temp2; temp2.x = 320; temp2.y = 290; temp2.w = 60; temp2.h = 30;
            if(SDL_PointInRect(&point,&temp2)){
                 quit.SetColor(255,0,0);
               if(EventHandle::GetGame()->GetMouseButtonDown){
                    GameManager::GetGame()->Quit();
                    quit.Free();
                    break;
                  }
           }
           else {
            quit.SetColor(255,255,255);
            //SDL_RenderPresent(GameManager::GetGame()->GetRenderer());
           }
           if(SDL_PointInRect(&point,&temp)){
                 playButton.SetColor(255,0,0);
               if(EventHandle::GetGame()->GetMouseButtonDown){
                    play = true;
                    playButton.Free();
                    break;
                  }
           }
           else {
            playButton.SetColor(255,255,255);
            //SDL_RenderPresent(GameManager::GetGame()->GetRenderer());
           }

   SDL_RenderPresent(GameManager::GetGame()->GetRenderer());
   }
if(play == true) {
TextObject level1;
level1.SetColor(255,255,255);
level1.SetText("Level 1");
 SDL_RenderClear(GameManager::GetGame()->GetRenderer());
          if(!level1.LoadFromRenderText(t_font3,GameManager::GetGame()->GetRenderer())){
        SDL_Log("Khong load dc quit button");
       }
          level1.RenderText(GameManager::GetGame()->GetRenderer(),300,290);
          SDL_RenderPresent(GameManager::GetGame()->GetRenderer());
          level1.Free();
          SDL_Delay(1000);
}
if(SDL_LoadWAV("./RunGameAudio.wav",&wavSpec, &wavBuffer, &wavLength)) {

SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL,0, &wavSpec,NULL, 0);
SDL_QueueAudio(deviceId, wavBuffer, wavLength);

SDL_PauseAudioDevice(deviceId,0);
}
else {
        cout << " Can not load audio:" << SDL_GetError() << endl;
}

   while(GameManager::GetGame()->IsRunning()){
        if(play == true) {
       GameManager::GetGame()->Events();
       GameManager::GetGame()->Update();
       GameManager::GetGame()->Render();}

   }
   GameManager::GetGame()->Clean();
    return 0;
}
