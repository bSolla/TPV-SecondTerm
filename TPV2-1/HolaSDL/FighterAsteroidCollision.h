#pragma once
#include "PhysicsComponent.h"

class GameManager;
class Asteroid;

class FighterAsteroidCollision :
	public PhysicsComponent {
public:
	FighterAsteroidCollision (GameManager* gameManager);
	virtual ~FighterAsteroidCollision ();

	virtual void update (Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message& msg);

private:
	GameManager *gm;
	GameObject* fighter_ = nullptr;
	const vector<Asteroid*>* asteroids_ = nullptr;
};

