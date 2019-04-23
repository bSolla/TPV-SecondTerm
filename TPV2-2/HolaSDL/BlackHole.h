#pragma once
#include "Container.h"
class BlackHole :
	public Container
{
public:
	BlackHole();
	virtual ~BlackHole();
	BlackHole(SDLGame* game);
};

