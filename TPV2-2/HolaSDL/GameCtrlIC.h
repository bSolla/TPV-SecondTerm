#pragma once
#include "InputComponent.h"

class GameManager;

class GameCtrlIC :
	public InputComponent {
public:
	GameCtrlIC (GameManager* gameManager);
	virtual ~GameCtrlIC ();

	virtual void handleInput(Container* c, Uint32 time);

private:
	GameManager* gm = nullptr;
};

