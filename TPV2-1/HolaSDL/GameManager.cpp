#include "GameManager.h"



GameManager::GameManager (SDLGame* game) :
		gameCtrl_(this){
	game_ = game;
	running_ = false;
	gameOver_ = true;
	score_ = 0;
	lives_ = maxLives_; 
	winner_ = 0;

	addC (&gameCtrl_);

	setId (msg::ObjectId::None);
	game_->addObserver (this);
}


GameManager::~GameManager () {
}
