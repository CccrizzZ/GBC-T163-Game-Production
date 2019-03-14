#pragma once
#include "IGameState.h"


class TitleState :	public IGameState {
public:
	TitleState();
	~TitleState();

	void Initialize();
	void Update();
	void Draw();
	void DeInitialize();

};
