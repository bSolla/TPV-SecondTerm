#pragma once
#include "InputComponent.h"
class RotationIC :
	public InputComponent
{
public:
	RotationIC();
	virtual ~RotationIC();
	void handleInput(Container* c, Uint32 time, const SDL_Event& event);
};

