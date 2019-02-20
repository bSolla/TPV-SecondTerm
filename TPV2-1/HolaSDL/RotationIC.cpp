#include "RotationIC.h"



RotationIC::RotationIC()
{
}


RotationIC::~RotationIC()
{
}

void RotationIC::handleInput(Container * c, Uint32 time, const SDL_Event & event)
{
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_LEFT) {
			c->setRotation(c->getRotation() - 5);
		}
		else if (event.key.keysym.sym == SDLK_RIGHT) {
			c->setRotation(c->getRotation() + 5);
		}
	}
}
