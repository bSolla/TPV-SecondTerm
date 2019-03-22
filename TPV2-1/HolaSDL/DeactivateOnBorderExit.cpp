#include "DeactivateOnBorderExit.h"



DeactivateOnBorderExit::DeactivateOnBorderExit()
{
}


DeactivateOnBorderExit::~DeactivateOnBorderExit()
{
}

void DeactivateOnBorderExit::update(Container * c, Uint32 time)
{
	if (c->getPosition().getX() > c->getGame()->getWindowWidth() || c->getPosition().getX() < 0
		|| c->getPosition().getY() < 0 || c->getPosition().getY() > c->getGame()->getWindowHeight()) {
		c->setActive(false);
	}
}
