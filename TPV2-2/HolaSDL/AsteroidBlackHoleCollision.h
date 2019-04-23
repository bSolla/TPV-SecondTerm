#pragma once
#include "PhysicsComponent.h"

class GameManager;

class AsteroidBlackHoleCollision :
	public PhysicsComponent
{
public:
	AsteroidBlackHoleCollision(GameManager* gameManager);
	virtual ~AsteroidBlackHoleCollision();

	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message& msg);

private:
	const vector<Asteroid*>* asteroids_ = nullptr;
	const vector<BlackHole*>* blackHoles_ = nullptr;
	GameManager *gm;
};

