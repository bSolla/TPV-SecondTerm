#include "Asteroids.h"
#include "Bullet.h"

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

	setActive (false);
}


Asteroids::~Asteroids()
{
}

void Asteroids::receive(const void * senderObj, const msg::Message & msg) {
	Container::receive(senderObj, msg);

	switch (msg.type_) {
	case msg::GAME_START:
		globalSend(this, msg::AsteroidsInfo(msg::Asteroids, msg::Broadcast, &getAllObjects()));
		break;
	case msg::ROUND_START: 
		newRoundCreation ();
		break;
	case msg::ROUND_OVER:
		deactiveAllObjects();
		setActive(false);
		break;
	case msg::BULLET_ASTEROID_COLLISION:
		bulletCollision (msg);
		break;
	default:
		break;
	}
}

void Asteroids::create(int size, Vector2D pos, int gen)
{
	Asteroid *a = getUnusedObject();
	a->setWidth(size);
	a->setHeight(size);
	a->setPosition(pos);

	Vector2D c = Vector2D (getGame ()->getWindowWidth () / 2, getGame ()->getWindowHeight () / 2);

	Vector2D v;
	if (gen == 3) {
		v = (c - pos).normalize () * (getGame ()->getServiceLocator ()->getRandomGenerator ()->nextInt (1, 10) / 20.0);
	}
	else if (gen == 2) {
		v = (c - pos).normalize () * (getGame ()->getServiceLocator ()->getRandomGenerator ()->nextInt (1, 10) / 18.0);
	}
	else {
		v = (c - pos).normalize () * (getGame ()->getServiceLocator ()->getRandomGenerator ()->nextInt (1, 10) / 15.0);
	}
	a->setVelocity(v);

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


void Asteroids::newRoundCreation () {
	int size = 20;
	Vector2D pos = Vector2D (size, size);

	for (int i = 0; i < 10; i++) {
		int rand = (game_->getServiceLocator ()->getRandomGenerator ()->nextInt (1, 5));

		switch (rand) {
		case 0:
			pos = Vector2D (size, game_->getServiceLocator ()->getRandomGenerator ()->nextInt (1, game_->getWindowHeight () - size));
			break;
		case 1:
			pos = Vector2D (game_->getWindowWidth () - size, game_->getServiceLocator ()->getRandomGenerator ()->nextInt (1, game_->getWindowHeight () - size));
			break;
		case 2:
			pos = Vector2D (game_->getServiceLocator ()->getRandomGenerator ()->nextInt (1, game_->getWindowWidth () - size), size);
			break;
		case 3:
			pos = Vector2D (game_->getServiceLocator ()->getRandomGenerator ()->nextInt (1, game_->getWindowWidth () - size), game_->getWindowHeight () - size);
			break;
		default:
			break;
		}

		create (size, pos, 3);
	}
}


void Asteroids::bulletCollision (const msg::Message & msg) {
	// msg casting
	const msg::BulletAsteroidCollision& m = static_cast<const msg::BulletAsteroidCollision&>(msg);
	m.asteroid_->setActive(false);

	int currentGen = m.asteroid_->getGenerations ();

	//globalSend(this, msg::AsteroidDestroyed(msg::Asteroids, msg::Broadcast, (4 - m.asteroid_->getGenerations())));
	game_->send (this, msg::AsteroidDestroyed (msg::Asteroids, msg::Broadcast, (4 - m.asteroid_->getGenerations ())));
	
	if ( currentGen > 1) {
		create (generationalSize[currentGen - 1], m.asteroid_->getPosition(), currentGen - 1);
		create (generationalSize[currentGen - 1], m.bullet_->getPosition(), currentGen - 1);
	}
	if (countActiveAsteroids() == 0) {
		globalSend(this, msg::Message(msg::NO_MORE_ASTEROIDS, msg::Asteroids, msg::Broadcast));
	}
	// TODO: play explosion sound
}
