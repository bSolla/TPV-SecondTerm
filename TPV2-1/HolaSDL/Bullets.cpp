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

	setId(msg::BulletsShooter);
	game_->addObserver(this);

	setActive (false);
}


Bullets::~Bullets()
{
}

void Bullets::createBullet (Vector2D position, Vector2D direction, double rotation) {
	Bullet *a = getUnusedObject();

	if (a != nullptr) {
		a->setWidth (1);
		a->setHeight (5);
		a->setPosition (position);
		a->setVelocity (direction);
		a->setRotation(rotation);
		a->setActive (true);
	}
}

void Bullets::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);

	switch (msg.type_)
	{
	case msg::GAME_START:
		globalSend(this, msg::BulletsInfoMsg(msg::BulletsShooter, msg::Broadcast, &getAllObjects()));
		break;
	case msg::ROUND_START:
		setActive(true);
		break;
	case msg::ROUND_OVER:
		deactiveAllObjects();
		setActive(false);
		break;
	case msg::BULLET_ASTEROID_COLLISION: {
		const msg::BulletAsteroidCollision& m = static_cast<const msg::BulletAsteroidCollision&>(msg);
		m.bullet_->setActive(false);
		break;
	}
	case msg::FIGHTER_SHOOT: {
		const msg::Shoot& m1 = static_cast<const msg::Shoot&>(msg);
		createBullet(m1.pos_ - Vector2D(1 / 2, 5), m1.dir_ * 5, Vector2D(0, -1).angle(m1.dir_));
		game_->getServiceLocator ()->getAudios ()->playChannel (Resources::GunShot, 0);
		break;
	}
	default:
		break;
	}
}