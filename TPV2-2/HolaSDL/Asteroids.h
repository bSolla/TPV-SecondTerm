#pragma once
#include "GameObjectPool.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "RotationIC.h"
#include "ShowUpAtOppositeSidePC.h"
#include "RotatingPC.h"
#include "Asteroid.h"


class Asteroids : public GameObjectPool<Asteroid, 50> {
public:
	Asteroids(SDLGame* game);
	virtual ~Asteroids();
	virtual void receive(const void* senderObj, const msg::Message& msg);
	
	int countActiveAsteroids();
	// ...
private:
	int generationalSize[4] = { 0, 10, 15, 20 };
	// component for Asteroid
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOppositeSide_;

	void create(int size, Vector2D pos, int gen);
	void newRoundCreation ();
	void bulletCollision (const msg::Message & msg);
	void blackHoleCollision(const msg::Message & msg);

	Vector2D fighterPos_ = Vector2D(getGame()->getWindowWidth() / 2 - 6, getGame()->getWindowHeight() / 2 - 6);
};
