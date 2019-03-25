#include "FighterAsteroidCollision.h"
#include "GameManager.h"
#include "Asteroid.h"
#include "Collisions.h"

FighterAsteroidCollision::FighterAsteroidCollision (GameManager* gameManager) {
	gm = gameManager;
}


FighterAsteroidCollision::~FighterAsteroidCollision () {
}

void FighterAsteroidCollision::update (Container * c, Uint32 time) {
	if (fighter_ != nullptr && asteroids_ != nullptr) {
		for (auto it = asteroids_->begin (); it != asteroids_->end (); ++it) {
			if (!gm->getRunning ())
				return;
			else if (fighter_->isActive() && (*it)->isActive () && Collisions::collidesWithRotation(fighter_, (*it))){
				//c->globalSend (this, msg::FighterAsteroidCollisionMsg (msg::ObjectId::None, msg::ObjectId::Broadcast, fighter_, (*it)));
				c->getGame ()->send (this, msg::FighterAsteroidCollisionMsg (msg::ObjectId::None, msg::ObjectId::Broadcast, fighter_, (*it)));
			}
		}
	}
}
