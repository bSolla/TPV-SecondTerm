#pragma once
#include "GraphicsComponent.h"
#include <string>

class GameManager;

class LivesViewer :
	public GraphicsComponent {
public:
	LivesViewer (GameManager *gameManager);
	virtual ~LivesViewer ();

	virtual void render (Container* c, Uint32 time);

private:
	GameManager* gm;
};

