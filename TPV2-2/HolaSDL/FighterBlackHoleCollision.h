#pragma once
#include "PhysicsComponent.h"

class GameManager;

class FighterBlackHoleCollision :
	public PhysicsComponent
{
public:
	FighterBlackHoleCollision(GameManager* gameManager);
	virtual ~FighterBlackHoleCollision();

	virtual void update(Container* c, Uint32 time);
	virtual void receive(Container* c, const msg::Message& msg);

private:
	GameManager *gm;
	GameObject* fighter_ = nullptr;
	const vector<BlackHole*>* blackHoles_ = nullptr;
};

