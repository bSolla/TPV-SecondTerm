#include "GunIC.h"
#include "InputHandler.h"


GunIC::GunIC() {
}


GunIC::~GunIC() {
}


void GunIC::handleInput(Container * c, Uint32 time) {
	if (InputHandler::getInstance()->isKeyDown(key_))
	{
		Vector2D p = c->getPosition() + Vector2D(c->getWidth() / 2.0, c->getHeight() / 2.0) +
		Vector2D(0.0, -(c->getHeight() / 2.0 + 5.0)).rotate(c->getRotation());
		Vector2D d = Vector2D(0, -1).rotate(c->getRotation());
		int type = 0; // bullet type

		Logger::instance()->log( [p,d]()->string { stringstream s; s << "Shooting: " << p << " " << d; return s.str(); });
		c->globalSend(this, msg::Shoot(msg::ObjectId::FighterGun, msg::ObjectId::Broadcast, p, d, type));
	}
}

