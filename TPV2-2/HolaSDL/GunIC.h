#pragma once
#include "InputComponent.h"
#include "Messages_defs.h"
#include "Logger.h"
#include <sstream>

class GunIC : public InputComponent {
private:
	SDL_Keycode key_ = GUN_KEY;
public:
	GunIC();
	virtual ~GunIC();

	void handleInput(Container* c, Uint32 time);
};

