#pragma once
#include "InputComponent.h"

class GunIC :
	public InputComponent
{
public:
	GunIC();
	virtual ~GunIC();
	void handleInput(Container* c, Uint32 time, const SDL_Event& event);
};

