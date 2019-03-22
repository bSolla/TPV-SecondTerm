#pragma once
#include "GameObjectPool.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "Bullet.h"
#include "DeactivateOnBorderExit.h"

class Bullets : public GameObjectPool<Bullet, 10> {
public:
	Bullets(SDLGame* game);
	virtual ~Bullets();
	// …
private:
	// …
	// components for Bullet
	NaturalMovePC naturalMove_;
	DeactivateOnBorderExit deactivate_;
	ImageGC bulletImage_;
};

