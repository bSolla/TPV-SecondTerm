#pragma once
#include "InputComponent.h"
#include "Messages_defs.h"

class GunIC : public InputComponent {
private:
	SDL_Keycode key_ = GUN_KEY;
public:
	GunIC();
	virtual ~GunIC();

	void handleInput(Container* c, Uint32 time, const SDL_Event& event);

	virtual void receive(const void* senderObj, const msg::Message& msg);
};

