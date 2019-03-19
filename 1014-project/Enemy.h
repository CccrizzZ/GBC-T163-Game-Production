#pragma once
#include <iostream>
#include <vector>
#include "SDL_image.h"
#include "Vector2.h"
using namespace std;


// prototype for EnemyBullet
class Game;
class EnemyBullet;
class Enemy{
public:
	Enemy();
	~Enemy();

	// Constructor
	Enemy(float ex, float ey, int type){

		// Set enemy image according to enemyType
		SetType(type);

		// Set enemy position
		eDestR.x = ex;
		eDestR.y = ey;

	}

	// Enemy type
	int Etype;

	// Enemy rect
	SDL_Rect eDestR;

	// Enemy texture
	SDL_Surface* eSurf;
	SDL_Texture* eText;

	// Enemy speed
	int eSpeed;

	// Enemy dead bool
	bool shoot;

	// Enemy bullet
	vector<EnemyBullet*> eBullets;

	// Enemy location
	Vector2 eLocation;

	// Functions
	void SetType(int et);
	void SpawnBullet();
	void Render();
	void Update();
	void Clean();


};