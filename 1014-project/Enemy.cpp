#include "Enemy.h"
#include "Game.h"
#include "EnemyBullet.h"
using namespace std;


Enemy::Enemy(){
}


Enemy::~Enemy(){
}


void Enemy::SetType(int et) {
  if (et == 0) {
    eSurf = IMG_Load("img/Ghost.png");
    eText = SDL_CreateTextureFromSurface(Game::Instance()->GetRenderer(), eSurf);
    eSpeed = 5;
    Etype = 0;

  }else if (et == 1) {
    eSurf = IMG_Load("img/Ghost2.png");
    eText = SDL_CreateTextureFromSurface(Game::Instance()->GetRenderer(), eSurf);
    eSpeed = 8;
    Etype = 1;

  }else if (et == 2) {
    eSurf = IMG_Load("img/Ghost3.png");
    eText = SDL_CreateTextureFromSurface(Game::Instance()->GetRenderer(), eSurf);
    eSpeed = 12;
    Etype = 2;
    
  }



}

// Functions
void Enemy::SpawnBullet(){
  // Push a new EnemyBullet into the vector
  eBullets.push_back(new EnemyBullet(eLocation.x + 30, eLocation.y + 20));

}

void Enemy::Update(){
  // Update the Enemy size
  eDestR.h = 40;
	eDestR.w = 40;

  // Move Enemy
  eDestR.x -= eSpeed;

  // Update Enemy location according to its movement
  eLocation.x = eDestR.x;
  eLocation.y = eDestR.y;
}



void Enemy::Render(){
  // Render Enemy graphics
	SDL_RenderCopy(Game::Instance()->GetRenderer(), eText, NULL, &eDestR);

}



void Enemy::Clean(){
  // Delete player graphics
	SDL_FreeSurface(eSurf);
	SDL_DestroyTexture(eText);
}
