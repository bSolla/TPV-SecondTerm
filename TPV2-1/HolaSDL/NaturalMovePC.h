#pragma once

#include "PhysicsComponent.h"

/*
 *
 */
class NaturalMovePC: public PhysicsComponent {
public:
	NaturalMovePC();
	virtual ~NaturalMovePC();
	virtual void update(Container* c, Uint32 time);

	// TODO: clean when debugging is done
	virtual void receive (Container* c, const msg::Message& msg) {
		cout << "got to NaturalMove::receive\n";
	}
};

