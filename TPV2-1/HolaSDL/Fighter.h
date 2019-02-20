#pragma once
#include "Container.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "RotationIC.h"
#include "ThrustIC.h"
#include"ReduceSpeedPC.h"
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

	// TODO: revisar constructoras ------------------ 
	RotationIC rotation_;
	ThrustIC thrust_;
	ReduceSpeedPC reduceSpeed_;
	//GunIC normalGun_;
};

