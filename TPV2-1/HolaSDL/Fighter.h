#pragma once
#include "Container.h"
#include "ImageGC.h"
#include "NaturalMovePC.h"
#include "RotationIC.h"
#include "ThrustIC.h"
#include"ReduceSpeedPC.h"
#include "ShowUpAtOppositeSidePC.h"
#include "GunIC.h"

class Fighter :
	public Container
{
public:
	Fighter(SDLGame* game);
	virtual ~Fighter();
	void reset();
	virtual void receive (const void* senderObj, const msg::Message& msg) { Container::receive (senderObj, msg); }

private:
	//…
	// components
	ImageGC fighterImage_;
	NaturalMovePC naturalMove_;
	ShowUpAtOppositeSidePC oppositeSide_;
	RotationIC rotation_;
	ThrustIC thrust_;
	ReduceSpeedPC reduceSpeed_;
	GunIC normalGun_;

};

