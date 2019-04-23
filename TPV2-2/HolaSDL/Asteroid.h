#pragma once
#include <sstream>
#include "Logger.h"
#include "Container.h"

class Asteroid :
	public Container
{
public:
	Asteroid();
	virtual ~Asteroid();
	Asteroid(SDLGame* game);
	int getGenerations() { return generations_; }
	void setGenerations(int gen) { generations_ = gen; }

private:
	int generations_ = 3;

};

