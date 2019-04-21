#include "ThrustIC.h"
#include "InputHandler.h"


ThrustIC::ThrustIC(SDL_Keycode key, double thrust, double speedLimit) {
	key_ = key;
	thrust_ = thrust;
	speedLimit_ = speedLimit;
}


ThrustIC::~ThrustIC() {
}

void ThrustIC::handleInput(Container * c, Uint32 time) {
	if (InputHandler::getInstance()->isKeyDown(key_)) {
		c->setVelocity(c->getVelocity() + (Vector2D(0, -1).rotate(c->getRotation())*thrust_));

		if (c->getVelocity().magnitude() > speedLimit_) {
			c->setVelocity(c->getVelocity().normalize()*speedLimit_);
		}
	}
	/*if (event.type == SDL_KEYDOWN && event.key.keysym.sym == key_) {
		c->setVelocity(c->getVelocity() + (Vector2D(0, -1).rotate(c->getRotation())*thrust_));

		if (c->getVelocity().magnitude() > speedLimit_) {
			c->setVelocity(c->getVelocity().normalize()*speedLimit_);
		}
	}*/
}
