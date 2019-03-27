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

	setId (msg::ObjectId::GameManager);
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

void GameManager::receive (const void * senderObj, const msg::Message & msg) {
	Container::receive(senderObj, msg);

	switch (msg.type_) {
	case msg::GAME_START:
		gameOver_ = false;
		winner_ = 0;
		score_ = 0;
		lives_ = maxLives_;
		break;
	case msg::ROUND_START:
		running_ = true;
		game_->getServiceLocator ()->getAudios ()->playMusic (Resources::ImperialMarch);
		break;
	case msg::ASTEROID_DESTROYED: {
		const msg::AsteroidDestroyed& m1 = static_cast<const msg::AsteroidDestroyed&>(msg);
		score_ += m1.points_;
		break;
	}
	case msg::NO_MORE_ASTEROIDS: 
		running_ = false;
		gameOver_ = true;
		winner_ = 2;
		game_->getServiceLocator ()->getAudios ()->haltMusic ();
		globalSend (this, msg::Message (msg::ROUND_OVER, msg::ObjectId::GameManager, msg::ObjectId::Broadcast));
		globalSend (this, msg::Message (msg::GAME_OVER, msg::ObjectId::GameManager, msg::ObjectId::Broadcast));
		break;
	case msg::FIGHTER_ASTEROID_COLLISION: 
		game_->getServiceLocator ()->getAudios ()->playChannel (Resources::Explosion, 0);
		game_->getServiceLocator ()->getAudios ()->haltMusic ();
		running_ = false;
		lives_--;
		globalSend (this, msg::Message (msg::ROUND_OVER, msg::ObjectId::GameManager, msg::ObjectId::Broadcast));
		if (lives_ == 0) {
			gameOver_ = true;
			winner_ = 1;
			globalSend (this, msg::Message (msg::GAME_OVER, msg::ObjectId::GameManager, msg::ObjectId::Broadcast));
		}
	default:
		break;
	}
}
