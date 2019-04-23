#include "Fighter.h"



Fighter::Fighter(SDLGame* game):
		Container(game),
		fighterImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Airplanes), {47, 90, 207, 250}), 
		reduceSpeed_(REDUCE_SPEED_FACTOR),
		thrust_(THRUST_KEY, THRUST_VALUE, SPEED_LIMIT),
		rotation_(ROTATE_CLOCKWISE, ROTATE_COUNTERCLOCKWISE, ALPHA) {
	addC(&fighterImage_); 
	addC(&naturalMove_);
	addC(&oppositeSide_);
	addC(&rotation_);
	addC(&thrust_);
	addC(&reduceSpeed_);
	addC(&normalGun_);

	reset();
	setId (msg::Fighter);
	game_->addObserver (this);

	setActive (false);
}


Fighter::~Fighter()
{
}

void Fighter::reset()
{
	setWidth(100);
	setHeight(100);
	setPosition(Vector2D(getGame()->getWindowWidth() / 2 - 6, getGame()->getWindowHeight() / 2 - 6));

	RandomNumberGenerator* r =
		getGame()->getServiceLocator()->getRandomGenerator();
	int dx = 1 - 2 * r->nextInt(0, 2); // 1 or -1
	int dy = 1 - 2 * r->nextInt(0, 2); // 1 or -1
	Vector2D v(dx * r->nextInt(2, 7), // 2 to 6
		dy * r->nextInt(2, 7)  // 2 to 6
	);
	setVelocity(Vector2D(0.0, 0.0));
}

void Fighter::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);

	switch (msg.type_)
	{
		case msg::GAME_START:
			globalSend(this, msg::FighterInfo(msg::Fighter, msg::Broadcast, this));
			break;
		case msg::ROUND_START:
			reset();
			setActive(true);
			break;
		case msg::ROUND_OVER:
			setActive(false);
			break;
		case msg::BULLET_BLACK_HOLE_COLLISION:
			globalSend(this, msg::FighterInfo(msg::Fighter, msg::Broadcast, this));
			break;
		default:
			break;
	}
}
