#pragma once
#include "GraphicsComponent.h"

class GameManager;

class GameStatusViewGC :
	public GraphicsComponent {
public:
	GameStatusViewGC (GameManager *gameManager);
	virtual ~GameStatusViewGC ();
	
	virtual void render (Container* c, Uint32 time);

private:
	GameManager* gm;
};

