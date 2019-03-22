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

	Bullet *a = getUnusedObject();
	a->setWidth(10);
	a->setHeight(10);
	a->setPosition(Vector2D(game->getWindowWidth() / 2, game->getWindowHeight() / 2));
	a->setVelocity(Vector2D(1, 1));
	a->setActive(true);
}


Bullets::~Bullets()
{
}
