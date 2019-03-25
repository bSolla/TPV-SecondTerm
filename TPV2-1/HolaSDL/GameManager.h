#pragma once
#include "Container.h"
#include "GameCtrlIC.h"
#include "ScoreViewerGC.h"
#include "GameStatusViewGC.h"
#include "LivesViewer.h"
#include "FighterAsteroidCollision.h"
#include "BulletsAsteroidsCollision.h"

class GameManager :
	public Container {
public:
	GameManager(SDLGame* game);
	virtual ~GameManager();
	
	bool getRunning () const { return running_; }
	int getCurrentLives () const { return lives_; }
	int getMaxLives () const { return maxLives_; }

private:
	// �
	static int const maxLives_ = 3;
	bool running_;
	bool gameOver_;
	int score_;
	int lives_;
	int winner_; // 0=none, 1=asteroids, 2=fighter
	// components of GameManager
	GameCtrlIC gameCtrl_;
	//ScoreViewerGC scoreView_;
	//GameStatusViewGC gameStatusView_;
	//LivesViewer livesViewer_;
	//FighterAsteroidCollision fighterAsteroidCollision_;
	//BulletsAsteroidsCollision bulletsAsteroidsCollision_;
};
