#include "GameManager.h"



GameManager::GameManager (SDLGame* game) :
		gameCtrl_(this), 
		fighterAsteroidCollision_(this),
		bulletsAsteroidsCollision_(this), 
		livesViewer_(this),
		scoreView_(this),
		gameStatusView_(this) {
	game_ = game;
	running_ = false;
	gameOver_ = false;
	score_ = 0;
	lives_ = maxLives_; 
	winner_ = 0;

	addC (&gameCtrl_);
	addC (&fighterAsteroidCollision_);
	addC (&bulletsAsteroidsCollision_);
	addC (&livesViewer_);
	addC (&scoreView_);
	addC (&gameStatusView_);

	setId (msg::ObjectId::None);
	game_->addObserver (this);
}


GameManager::~GameManager () {
}

string GameManager::getWinner () const {
	string winner = "none";

	switch (winner_) {
	case 1:
		winner = "asteroids";
		break;
	case 2:
		winner = "fighter";
		break;
	default:
		break;
	}

	return winner;
}
