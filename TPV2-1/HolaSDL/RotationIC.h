#pragma once
#include "InputComponent.h"
class RotationIC : public InputComponent {
private:
	SDL_Keycode clockwiseKey_;
	SDL_Keycode counterClockwiseKey_;
	double alpha_;

public:
	RotationIC(SDL_Keycode clockwiseKey, SDL_Keycode counterClockwiseKey, double alpha);
	virtual ~RotationIC();

	void handleInput(Container* c, Uint32 time, const SDL_Event& event);

	virtual void receive (const void* senderObj, const msg::Message& msg) {
		cout << "bullet\n";
	}
};

