#pragma once
#include "Container.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "ShowUpAtOppositeSidePC.h"

class Fighter :
	public Container
{
public:
	Fighter(SDLGame* game);
	virtual ~Fighter();
	void reset();
private:
	//…
	// components
	ImageGC fighterImage_;
	NaturalMovePC naturalMove_;
	ShowUpAtOppositeSidePC oppositeSide_;
	/*RotationIC rotation_;
	ThrustIC thrust_;
	ReduceSpeedPC reduceSpeed_;
	GunIC normalGun_;*/
};

