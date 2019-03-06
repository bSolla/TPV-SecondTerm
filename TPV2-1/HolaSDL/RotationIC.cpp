#include "RotationIC.h"



RotationIC::RotationIC(SDL_Keycode clockwiseKey, SDL_Keycode counterClockwiseKey, double alpha) {
	clockwiseKey_ = clockwiseKey;
	counterClockwiseKey_ = counterClockwiseKey;
	alpha_ = alpha;
}


RotationIC::~RotationIC() {
}

void RotationIC::handleInput(Container * c, Uint32 time, const SDL_Event & event) {
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == counterClockwiseKey_) {
			c->setRotation(c->getRotation() - alpha_);
		}
		else if (event.key.keysym.sym == clockwiseKey_) {
			c->setRotation(c->getRotation() + alpha_);
		}
	}
}
