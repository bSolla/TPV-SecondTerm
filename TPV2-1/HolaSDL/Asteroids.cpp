#include "Asteroids.h"


Asteroids::Asteroids(SDLGame* game) :
	GameObjectPool(game),
	asteroidImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)),
	rotating_(ALPHA)
{
	for (Asteroid *a : getAllObjects()) {
		a->addC(&asteroidImage_);
		a->addC(&naturalMove_);
		a->addC(&showUpAtOppositeSide_);
		a->addC(&rotating_);
	}

	Asteroid *a = getUnusedObject();
	a->setWidth(20);
	a->setHeight(20);
	a->setPosition(Vector2D(34, 200));
	a->setVelocity(Vector2D(1, 1));
	a->setActive(true);
}


Asteroids::~Asteroids()
{
}