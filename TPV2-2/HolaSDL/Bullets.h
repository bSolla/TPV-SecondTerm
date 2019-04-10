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
	
	void createBullet (Vector2D position = Vector2D (400.0, 300.0), Vector2D direction = Vector2D (0.0, -1.0), double rotation = 0.0);
	virtual void receive(const void* senderObj, const msg::Message& msg);
private:
	// components for Bullet
	NaturalMovePC naturalMove_;
	DeactivateOnBorderExit deactivate_;
	ImageGC bulletImage_;

};

