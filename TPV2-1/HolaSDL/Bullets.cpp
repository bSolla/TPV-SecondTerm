#include "Bullets.h"



Bullets::Bullets(SDLGame* game):
	GameObjectPool(game),
	bulletImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::WhiteRect))
{
	for (Bullet *b : getAllObjects()) {
		b->addC(&bulletImage_);
		b->addC(&naturalMove_);
		b->addC(&deactivate_);
	}

	createBullet ();
}


Bullets::~Bullets()
{
}

void Bullets::createBullet (Vector2D position, Vector2D direction) {
	Bullet *a = getUnusedObject();

	if (a != nullptr) {
		a->setWidth (10);
		a->setHeight (10);
		a->setPosition (position);
		a->setVelocity (direction);
		a->setActive (true);
	}
}


void Bullets::handleInput (Uint32 time, const SDL_Event & event) {
	if (event.type == SDL_KEYUP && event.key.keysym.sym == key_) {
		createBullet ();
	}

	GameObjectPool::handleInput (time, event);
}

