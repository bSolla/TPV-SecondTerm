#pragma once
#include "InputComponent.h"
class ThrustIC : public InputComponent {
private:
	// key_
	SDL_Keycode key_;
	double thrust_;
	double speedLimit_;

public:
	ThrustIC(SDL_Keycode key, double thrust, double speedLimit);
	virtual ~ThrustIC();

	void handleInput(Container* c, Uint32 time);
};

