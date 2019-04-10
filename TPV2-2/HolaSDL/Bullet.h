#pragma once
#include "Container.h"
class Bullet :
	public Container
{
public:
	Bullet();
	virtual ~Bullet();
	Bullet(SDLGame* game);
};

