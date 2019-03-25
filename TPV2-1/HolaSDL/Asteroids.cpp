#include "Asteroids.h"


Asteroids::Asteroids(SDLGame* game) :
	GameObjectPool(game),
	asteroidImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::Asteroid)),
	rotating_(ALPHA)
{
	for (Asteroid *a : getAllObjects()) {
		a->addC(&asteroidImage_);
		a->addC(&naturalMove_);
		a->addC(&showUpAtOppositeSide_);
		a->addC(&rotating_);
	}

	setId(msg::Asteroids);
	game_->addObserver(this);
}


Asteroids::~Asteroids()
{
}

void Asteroids::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);

	switch (msg.type_)
	{
	case msg::GAME_START:
		globalSend(this, msg::AsteroidsInfo(msg::Asteroids, msg::Broadcast, &getAllObjects()));
		break;
	case msg::ROUND_START:
		// TODO: clean, maybe make a create10asteroids method
		for (int i = 0; i < 10; i++)
		{
			int rand = (game_->getServiceLocator()->getRandomGenerator()->nextInt() % 4);
			switch (rand)
			{
			case 0:
				create(20, game_->getServiceLocator()->getRandomGenerator()->nextInt(), 20, 0.2, 3);
				break;
			case 1:
				create(20, game_->getServiceLocator()->getRandomGenerator()->nextInt(), game_->getWindowHeight() - 20, 0.2, 3);
				break;
			case 2:
				create(20, 20, game_->getServiceLocator()->getRandomGenerator()->nextInt(), 0.2, 3);
				break;
			case 3:
				create(20, game_->getWindowWidth() - 20, game_->getServiceLocator()->getRandomGenerator()->nextInt(), 0.2, 3);
				break;
			default:
				break;
			}
		}
		break;
	case msg::ROUND_OVER:
		deactiveAllObjects();
		setActive(false);
		break;
	case msg::BULLET_ASTEROID_COLLISION:
	{
		// set asteroid inactive
		const msg::BulletAsteroidCollision& m = static_cast<const msg::BulletAsteroidCollision&>(msg);
		m.asteroid_->setActive(false);
		globalSend(this, msg::AsteroidDestroyed(msg::Asteroids, msg::Broadcast, (4 - m.asteroid_->getGenerations())));
		/*if (m.asteroid_->getGenerations() > 1)
		{
			TODO: create 2 asteroids with one less generation, smaller and faster
		}*/
		if (countActiveAsteroids() == 0)
		{
			globalSend(this, msg::Message(msg::NO_MORE_ASTEROIDS, msg::Asteroids, msg::Broadcast));
		}
		// TODO: play explosion sound
		break;
	}
	default:
		break;
	}
}

void Asteroids::create(int size, int x, int y, int speedModule, int gen)
{
	Asteroid *a = getUnusedObject();
	a->setWidth(size);
	a->setHeight(size);
	a->setPosition(Vector2D(x, y));
	Vector2D c = Vector2D(getGame()->getWindowWidth() / 2, getGame()->getWindowHeight() / 2);
	Vector2D v = (c - Vector2D(x, y).normalize() * (getGame()->getServiceLocator()->getRandomGenerator()->nextInt(1, 10) / 20.0));
	a->setVelocity(v*speedModule);
	a->setGenerations(gen);
	a->setActive(true);
}

int Asteroids::countActiveAsteroids()
{
	int count = 0;
	for (Asteroid* a : getAllObjects())
	{
		if (a->isActive()) {
			count++;
		}
	}
	return count;
}
