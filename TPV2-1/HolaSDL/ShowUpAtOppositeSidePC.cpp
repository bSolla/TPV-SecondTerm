#include "ShowUpAtOppositeSidePC.h"



ShowUpAtOppositeSidePC::ShowUpAtOppositeSidePC()
{
}


ShowUpAtOppositeSidePC::~ShowUpAtOppositeSidePC()
{
}

void ShowUpAtOppositeSidePC::update(Container * c, Uint32 time)
{
	if (c->getPosition().getX() >= c->getGame()->getWindowWidth()) {
		c->setPosition({1 - c->getWidth(), c->getPosition().getY() });
	}
	else if (c->getPosition().getX() + c->getWidth() <= 0) {
		c->setPosition({ double(c->getGame()->getWindowWidth()), c->getPosition().getY() });
	}
	if (c->getPosition().getY() >= c->getGame()->getWindowHeight()) {
		c->setPosition({ c->getPosition().getX(), 1 - c->getHeight() });
	}
	else if (c->getPosition().getY() + c->getHeight() <= 0) {
		c->setPosition({ c->getPosition().getX(), double(c->getGame()->getWindowHeight()) });
	}
}