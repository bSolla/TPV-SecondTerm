#pragma once
#include "GameObjectPool.h"
#include "BlackHole.h"
#include "RotatingPC.h"
#include "ImageGC.h"

class BlackHoles : public GameObjectPool<BlackHole, 8>
{
public:
	BlackHoles(SDLGame* game);
	~BlackHoles();
	virtual void receive(const void* senderObj, const msg::Message& msg);


private:
	ImageGC blackHoleImage_;
	RotatingPC rotating_;

	void newRoundCreation();
	void create(Vector2D pos);

	int num_;
	bool roundLost = true;
};

