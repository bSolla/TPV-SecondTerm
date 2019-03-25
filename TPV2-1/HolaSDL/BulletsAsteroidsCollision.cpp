#include "BulletsAsteroidsCollision.h"
#include "GameManager.h"
#include "Collisions.h"
#include "Asteroid.h"
#include "Bullet.h"

BulletsAsteroidsCollision::BulletsAsteroidsCollision (GameManager* gameManager) {
	gm = gameManager;
}


BulletsAsteroidsCollision::~BulletsAsteroidsCollision () {
}


void BulletsAsteroidsCollision::update (Container * c, Uint32 time) {
	if (bullets_ != nullptr && asteroids_ != nullptr) {
		for (auto itAsteroids = asteroids_->begin (); itAsteroids != asteroids_->end (); ++itAsteroids) {
			for (auto itBullets = bullets_->begin (); itBullets != bullets_->end (); ++itBullets) {
				if (!gm->getRunning ())
					return;
				else if ((*itBullets)->isActive () && (*itAsteroids)->isActive () && Collisions::collidesWithRotation ((*itBullets), (*itAsteroids))) {
					//c->globalSend (this, msg::BulletAsteroidCollision (msg::ObjectId::None, msg::ObjectId::Broadcast, (*itBullets), (*itAsteroids)));
					c->getGame ()->send (this, msg::BulletAsteroidCollision (msg::ObjectId::None, msg::ObjectId::Broadcast, (*itBullets), (*itAsteroids)));
				}
			}
		}
	}
}
