#include "FighterBlackHoleCollision.h"
#include "GameManager.h"
#include "BlackHoles.h"
#include "Collisions.h"



FighterBlackHoleCollision::FighterBlackHoleCollision(GameManager* gameManager)
{
	gm = gameManager;
}


FighterBlackHoleCollision::~FighterBlackHoleCollision()
{
}

void FighterBlackHoleCollision::update(Container * c, Uint32 time)
{
	if (fighter_ != nullptr && blackHoles_ != nullptr) {
		for (auto it = blackHoles_->begin(); it != blackHoles_->end(); ++it) {
			if (!gm->getRunning())
				return;
			else if (fighter_->isActive() && (*it)->isActive() && Collisions::collidesWithRotation(fighter_, (*it))) {
				c->globalSend(this, msg::FighterBlackHoleCollision(msg::ObjectId::None, msg::ObjectId::Broadcast, (*it), fighter_));
			}
		}
	}
}

void FighterBlackHoleCollision::receive(Container * c, const msg::Message & msg)
{
	switch (msg.type_) {
	case msg::BLACK_HOLES_INFO: {
		const msg::BlackHolesInfo& m1 = static_cast<const msg::BlackHolesInfo&>(msg);
		blackHoles_ = m1.blackHoles_;
		break;
	}
	case msg::FIGHTER_INFO: {
		const msg::FighterInfo& m2 = static_cast<const msg::FighterInfo&>(msg);
		fighter_ = m2.fighter_;
		break;
	}
	default:
		break;
	}
}
