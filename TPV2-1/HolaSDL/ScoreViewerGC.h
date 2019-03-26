#pragma once
#include "GraphicsComponent.h"

class GameManager;

class ScoreViewerGC :
	public GraphicsComponent {
public:
	ScoreViewerGC (GameManager *gameManager);
	virtual ~ScoreViewerGC ();

	virtual void render (Container* c, Uint32 time);

private:
	GameManager* gm;
};

