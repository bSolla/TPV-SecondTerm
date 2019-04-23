#include "AsteroidBlackHoleCollision.h"
#include "GameManager.h"
#include "Collisions.h"
#include "Asteroid.h"
#include "BlackHole.h"


AsteroidBlackHoleCollision::AsteroidBlackHoleCollision(GameManager* gameManager)
{
	gm = gameManager;
}


AsteroidBlackHoleCollision::~AsteroidBlackHoleCollision()
{
}

void AsteroidBlackHoleCollision::update(Container * c, Uint32 time)
{
	if (blackHoles_ != nullptr && asteroids_ != nullptr) {
		for (auto itBHoles = blackHoles_->begin(); itBHoles != blackHoles_->end(); ++itBHoles) {
			for (auto itAsteroids = asteroids_->begin(); itAsteroids != asteroids_->end(); ++itAsteroids) {
				if (!gm->getRunning())
					return;
				else if ((*itBHoles)->isActive() && (*itAsteroids)->isActive() && Collisions::collidesWithRotation((*itBHoles), (*itAsteroids))) { 
					c->globalSend(this, msg::AsteroidBlackHoleCollision(msg::ObjectId::None, msg::ObjectId::Broadcast, (*itBHoles), (*itAsteroids)));
				}
			}
		}
	}
}

void AsteroidBlackHoleCollision::receive(Container * c, const msg::Message & msg)
{
	switch (msg.type_) {
	case msg::ASTEROIDS_INFO: {
		const msg::AsteroidsInfo& m1 = static_cast<const msg::AsteroidsInfo&>(msg);
		asteroids_ = m1.asteroids_;
		break;
	}
	case msg::BLACK_HOLES_INFO: {
		const msg::BlackHolesInfo& m2 = static_cast<const msg::BlackHolesInfo&>(msg);
		blackHoles_ = m2.blackHoles_;
		break;
	}
	default:
		break;
	}
}
