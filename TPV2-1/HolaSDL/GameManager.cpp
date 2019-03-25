#include "GameManager.h"



GameManager::GameManager (SDLGame* game) :
		gameCtrl_(this), 
		fighterAsteroidCollision_(this),
		bulletsAsteroidsCollision_(this){
	game_ = game;
	running_ = false;
	gameOver_ = true;
	score_ = 0;
	lives_ = maxLives_; 
	winner_ = 0;

	addC (&gameCtrl_);
	addC (&fighterAsteroidCollision_);
	addC (&bulletsAsteroidsCollision_);

	setId (msg::ObjectId::None);
	game_->addObserver (this);
}


GameManager::~GameManager () {
}
