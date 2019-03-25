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
	void create(int size, int x, int y, int speedModule, int gen);
	int countActiveAsteroids();
	// ...
private:
	// …
	// component for Asteroid
	ImageGC asteroidImage_;
	NaturalMovePC naturalMove_;
	RotatingPC rotating_;
	ShowUpAtOppositeSidePC showUpAtOppositeSide_;
};
