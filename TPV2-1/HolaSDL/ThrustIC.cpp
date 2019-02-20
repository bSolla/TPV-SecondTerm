#include "ThrustIC.h"



ThrustIC::ThrustIC()
{
	key_ = SDLK_UP;
	thrust_ = 0.5;
	speedLimit_ = 2.0;
}


ThrustIC::~ThrustIC()
{
}

void ThrustIC::handleInput(Container * c, Uint32 time, const SDL_Event & event)
{
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == key_) {
		c->setVelocity(c->getVelocity() + (Vector2D(0, -1).rotate(c->getRotation())*thrust_));

		if (c->getVelocity().magnitude() > speedLimit_) {
			c->setVelocity(c->getVelocity().normalize()*speedLimit_);
		}
	}
}
