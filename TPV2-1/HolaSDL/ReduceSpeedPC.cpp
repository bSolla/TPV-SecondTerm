#include "ReduceSpeedPC.h"



ReduceSpeedPC::ReduceSpeedPC()
{
	factor_ = 0.995;
}


ReduceSpeedPC::~ReduceSpeedPC()
{
}

void ReduceSpeedPC::update(Container * c, Uint32 time)
{
	c->setVelocity(c->getVelocity()*factor_);
}
