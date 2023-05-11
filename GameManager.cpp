#include "GameManager.h"



#include "SpaceShip.h"
#include "TextureManager.h"
#include "Transform.h"
#include "SpaceShip.h"
#include "EventHandle.h"
#include "Chicken.h"
#include "Bullet.h"
#include "BackGround.h"
#include "Collision.h"
#include "Sound.h"
#include "Heart.h"
#include "TextObject.h";
#include "Egg.h"
#include<iostream>
#include<vector>
std::vector<Bullet*> bullet;
using namespace std;

GameManager* GameManager::s_game = nullptr;
SpaceShip* player = nullptr;

Chicken* enemy;
Chicken* enemy2;
Chicken* enemy3;
Chicken* enemy4;
Chicken* enemy5;
Chicken* enemy6;
Egg* egg = nullptr;
BackGround* background = nullptr;
Colli* collision = nullptr;
Heart* heart = nullptr;
TextObject text;
TextObject gameTime;
TTF_Font* t_font = NULL;
TTF_Font* t_font2 = NULL;
int score = 0;
bool GameManager::Init()
{
if(SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0){
    SDL_Log("Loi khong khoi tao duoc SDL", SDL_GetError());
    return false;
}
if(SDL_Init(SDL_INIT_AUDIO) != 0) {
    SDL_Log("SDL can not initialize audio", SDL_GetError());
    return false;
}

if(TTF_Init()== -1) {
    SDL_Log("SDL_ttf could not initialize!", TTF_GetError());
    return false;
}
t_window = SDL_CreateWindow("Chicken Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH, SCREEN_HEIGHT,0);

if(t_window == nullptr) {
    SDL_Log("Khong tao duoc cua so :", SDL_GetError());
    return false;
}

t_renderer = SDL_CreateRenderer(t_window,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

if(t_renderer == nullptr) {
    SDL_Log("Loi khong khoi tao duoc renderer :", SDL_GetError());
    return false;
}
TextureManager::GetGame()->Load("Spaceship","./pictures//space_ship.png");
player = new SpaceShip(new Element("Spaceship",100,500,394,316,8));

TextureManager::GetGame()->Load("chicken","./pictures//chickensprite.png");
enemy = new Chicken(new Element("chicken",100,200,183,199,4.5));

TextureManager::GetGame()->Load("chicken2","./pictures//chickensprite.png");
enemy2 = new Chicken(new Element("chicken2",100+50,200,183,199,4.5));

TextureManager::GetGame()->Load("chicken3","./pictures//chickensprite.png");
enemy3 = new Chicken(new Element("chicken3",100+100,200 ,183,199,4.5));

TextureManager::GetGame()->Load("chicken4","./pictures//chickensprite.png");
enemy4 = new Chicken(new Element("chicken4",100+150,200,183,199,4.5));

TextureManager::GetGame()->Load("chicken5","./pictures//chickensprite.png");
enemy5 = new Chicken(new Element("chicken5",100+200,200 ,183,199,4.5));

TextureManager::GetGame()->Load("chicken6","./pictures//chickensprite.png");
enemy6 = new Chicken(new Element("chicken6",100+250,200 ,183,199,4.5));


TextureManager::GetGame()->Load("background","./pictures//background.png");
background = new BackGround(new Element("background",60,60,180,178,0.3));

TextureManager::GetGame()->Load("collision","./pictures//collision.png");


TextureManager::GetGame()->Load("heart","./pictures//heart.png");
heart = new Heart(new Element("heart",690,10,225,225,8));

t_font = TTF_OpenFont("./font//font3.ttf",24);
t_font2 = TTF_OpenFont("./font//font2.ttf",22);

if(t_font == NULL) {
    SDL_Log("Khong tai dc font chu");
    return false;
}
text.SetColor(255,255,255);
gameTime.SetColor(224,224,224);

 TextureManager::GetGame()->Load("egg","./pictures//egg.png");

return t_isRunning = true;
}

bool GameManager::Clean()
{
  TextureManager::GetGame()->Clean();

  SDL_DestroyRenderer(t_renderer);
  SDL_DestroyWindow(t_window);
  IMG_Quit();
  SDL_Quit();
}

 void GameManager::Update()
{
    //EventHandle::GetGame()->GetMouseMotion(player->GetPosX(),player->GetPosY());
    background->Update(0);
    player->Update(0);
    heart->Update(0);
    if(level1 == true ) {
    enemy->Update(2);
     enemy2->Update(2);  enemy3->Update(2);  enemy4->Update(2);  enemy5->Update(2);  enemy6->Update(2);
    }
    if(level2) {
        enemy->Update2(2);
        egg->Update(2);
    }
    player->GetRect();
    enemy->GetRect();
    if(Collision(player,enemy)== true){
        cout << " Collision\n";

    }

//SDL_Log("HEhe game chay duoc ne");
}

void GameManager::Render()
{
 SDL_RenderClear(t_renderer);

 background->Draw();
 string Score = "Your    Score    " +std::to_string(score);
 text.SetText(Score);

if(!text.LoadFromRenderText(t_font,t_renderer)){
    SDL_Log("khong tai texture dc cho chu");
}
 text.RenderText(t_renderer,270,5);

// std::string t_time = "Time  :";
 //Uint32 timeValue = SDL_GetTicks()/1000;
 std::string timeValue ="Time:"+ std::to_string(110-SDL_GetTicks()/1000);
 gameTime.SetText(timeValue);
 if(!gameTime.LoadFromRenderText(t_font2,t_renderer)){
    SDL_Log("khong tai texture dc cho chu");
}
 gameTime.RenderText(t_renderer,595,40);

 heart->Draw();
 player->Draw();
 if(level1 = true) {
 enemy->Draw();
 enemy2->Draw();
 enemy3->Draw();
 enemy4->Draw();
 enemy5->Draw();
 enemy6->Draw();}
  for(int i =0; i< bullet.size();i++) {
        if(Collision(bullet[i],enemy)){
        cout << "va cham\n";
        collision = new Colli(new Element("collision",enemy->GetTransform()->X,enemy->GetTransform()->Y,33,33,0.8));
        collision->Draw();
        collision->Update(0);
        enemy->GetTransform()->X = -40;
        enemy->GetTransform()->Y = 0;

        bullet[i]->Clean();

         Sound::GetGame()->LoadEffect("ChickenSound","./ChickenSoundEffect.wav");
         Sound::GetGame()->PlayEffect("ChickenSound");

         score += 10;
        }
             if(Collision(bullet[i],enemy2)){
        cout << "va cham\n";
        collision->Draw();
        collision = new Colli(new Element("collision",enemy2->GetTransform()->X,enemy2->GetTransform()->Y,33,33,0.8));
        collision->Update(0);
        enemy2->GetTransform()->X = -40;
        enemy2->GetTransform()->Y = 1000;
        bullet[i]->Clean();

         Sound::GetGame()->LoadEffect("ChickenSound","./ChickenSoundEffect.wav");
         Sound::GetGame()->PlayEffect("ChickenSound");
        }
             if(Collision(bullet[i],enemy3)){
        cout << "va cham\n";

        collision = new Colli(new Element("collision",enemy3->GetTransform()->X,enemy3->GetTransform()->Y,33,33,0.8));
        collision->Draw();
        collision->Update(0);
        enemy3->GetTransform()->X = -40;
        enemy3->GetTransform()->Y = 1000;
        bullet[i]->Clean();

         Sound::GetGame()->LoadEffect("ChickenSound","./ChickenSoundEffect.wav");
         Sound::GetGame()->PlayEffect("ChickenSound");

          score += 10;
        }
             if(Collision(bullet[i],enemy4)){
        cout << "va cham\n";

        collision = new Colli(new Element("collision",enemy4->GetTransform()->X,enemy4->GetTransform()->Y,33,33,0.8));
        collision->Draw();
        collision->Update(0);
        enemy4->GetTransform()->X = -40;
        enemy4->GetTransform()->Y = 1000;
        bullet[i]->Clean();

         Sound::GetGame()->LoadEffect("ChickenSound","./ChickenSoundEffect.wav");
         Sound::GetGame()->PlayEffect("ChickenSound");

          score += 10;
        }
             if(Collision(bullet[i],enemy5)){
        cout << "va cham\n";

        collision = new Colli(new Element("collision",enemy5->GetTransform()->X,enemy5->GetTransform()->Y,33,33,0.8));
        collision->Draw();
        collision->Update(0);
      enemy5->GetTransform()->X = -40;
        enemy5->GetTransform()->Y = 1000;
        bullet[i]->Clean();

         Sound::GetGame()->LoadEffect("ChickenSound","./ChickenSoundEffect.wav");
         Sound::GetGame()->PlayEffect("ChickenSound");

          score += 10;
        }
             if(Collision(bullet[i],enemy6)){
        cout << "va cham\n";

        collision = new Colli(new Element("collision",enemy6->GetTransform()->X,enemy6->GetTransform()->Y,33,33,0.8));
        collision->Draw();
        collision->Update(0);
        enemy6->GetTransform()->X = -40;
        enemy6->GetTransform()->Y = 1000;
        bullet[i]->Clean();

         Sound::GetGame()->LoadEffect("ChickenSound","./ChickenSoundEffect.wav");
         Sound::GetGame()->PlayEffect("ChickenSound");

          score += 10;
        }
    }
     if(score == 50) {

            TextObject endgame;
            TextObject quit;
quit.SetColor(255,0,0);
quit.SetText("Press Enter to Quit");
endgame.SetColor(255,255,255);
endgame.SetText("You     win !!!");

          if(!endgame.LoadFromRenderText(t_font,t_renderer)){
        SDL_Log("Khong load dc quit button");
       }
       if(!quit.LoadFromRenderText(t_font2,t_renderer)){
        SDL_Log("Khong load dc quit button");}
          endgame.RenderText(t_renderer,300,290);
          text.RenderText(t_renderer,290,310);
          quit.RenderText(t_renderer,250,330);
    if(EventHandle::GetGame()->GetKeyDown(SDL_SCANCODE_RETURN)) {
        GameManager::GetGame()->Quit();
    }
        }

 for( int i =0; i<bullet.size();i++) {
    bullet[i]->Draw();

    bullet[i]->Update(0);
  }
 SDL_RenderPresent(t_renderer);
}

void GameManager::Events()
{
    if(EventHandle::GetGame()->GetKeyDown(SDL_SCANCODE_SPACE)&& (SDL_GetTicks()% 4 ==0)){
      cout << "bullet"+index << endl;
    TextureManager::GetGame()->Load("bullet"+index,"./pictures//dan1.png");
    bullet.push_back(new Bullet(new Element("bullet"+index,player->GetTransform()->X,player->GetTransform()->Y,30,39,1.5)));
    count++;
    index[0]++;
    Sound::GetGame()->LoadEffect("Shoot","./shoot.wav");
    Sound::GetGame()->PlayEffect("Shoot");

 //EventHandle::GetGame()->Input();
    }

}
bool GameManager::COLLISION()
{
    if(Collision(player,enemy)) {
        return true;
    }
    if(Collision(player,enemy2)) {
        return true;
    }
    if(Collision(player,enemy3)) {
        return true;
    }
    if(Collision(player,enemy4)) {
        return true;
    }
    if(Collision(player,enemy5)) {
        return true;
    }
    if(Collision(player,enemy6)) {
        return true;
    }



     return false;
}



void GameManager::Quit() {
   t_isRunning =false;
}

