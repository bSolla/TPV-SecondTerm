#include "GunIC.h"



GunIC::GunIC() {
}


GunIC::~GunIC() {
}


void GunIC::handleInput(Container * c, Uint32 time, const SDL_Event & event) {
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == key_) {
		Vector2D p = c->getPosition() + Vector2D(c->getWidth() / 2.0, c->getHeight() / 2.0) +
					 Vector2D(0.0, -(c->getHeight() / 2.0 + 5.0)).rotate(c->getRotation());
		Vector2D d = Vector2D(0, -1).rotate(c->getRotation());
 		int type = 0; // bullet type

		// TODO: fix msgs
		c->globalSend (this, msg::Shoot ( msg::ObjectId::FighterGun, msg::ObjectId::Broadcast, p, d, type ));
		//c->getGame ()->send (this, msg::Shoot ( msg::ObjectId::FighterGun, msg::ObjectId::Broadcast, p, d, type ));
	}
}

void GunIC::receive (Container* c, const msg::Message & msg) {
	cout << "got to GunIC receive\n";
}
