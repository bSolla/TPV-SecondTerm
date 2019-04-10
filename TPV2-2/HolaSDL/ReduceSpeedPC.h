#pragma once
#include "PhysicsComponent.h"
class ReduceSpeedPC : public PhysicsComponent {
private:
	double factor_;

public:
	ReduceSpeedPC(double factor);
	virtual ~ReduceSpeedPC();

	void  update(Container* c, Uint32 time);
};

