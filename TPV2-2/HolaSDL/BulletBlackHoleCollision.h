#pragma once
#include "PhysicsComponent.h"

class GameManager;

class BulletBlackHoleCollision :
	public PhysicsComponent
{
public:
	BulletBlackHoleCollision(GameManager* gameManager);
	virtual ~BulletBlackHoleCollision();

	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message& msg);

private:
	const vector<BlackHole*>* blackHoles_ = nullptr;
	const vector<Bullet*>* bullets_ = nullptr;
	GameManager *gm;
};

