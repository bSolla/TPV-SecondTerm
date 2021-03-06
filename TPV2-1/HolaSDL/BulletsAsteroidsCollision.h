#pragma once
#include "PhysicsComponent.h"

class GameManager;

class BulletsAsteroidsCollision :
	public PhysicsComponent {
public:
	BulletsAsteroidsCollision (GameManager* gameManager);
	virtual ~BulletsAsteroidsCollision ();

	virtual void update (Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message& msg);

private:
	const vector<Asteroid*>* asteroids_ = nullptr;
	const vector<Bullet*>* bullets_ = nullptr;
	GameManager *gm;
};

