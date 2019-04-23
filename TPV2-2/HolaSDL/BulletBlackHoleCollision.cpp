#include "BulletBlackHoleCollision.h"
#include "GameManager.h"
#include "Collisions.h"
#include "Bullet.h"
#include "BlackHole.h"



BulletBlackHoleCollision::BulletBlackHoleCollision(GameManager* gameManager)
{
	gm = gameManager;
}


BulletBlackHoleCollision::~BulletBlackHoleCollision()
{
}

void BulletBlackHoleCollision::update(Container * c, Uint32 time)
{
	if (blackHoles_ != nullptr && bullets_ != nullptr) {
		for (auto itBHoles = blackHoles_->begin(); itBHoles != blackHoles_->end(); ++itBHoles) {
			for (auto itBullets = bullets_->begin(); itBullets != bullets_->end(); ++itBullets) {
				if (!gm->getRunning())
					return;
				else if ((*itBHoles)->isActive() && (*itBullets)->isActive() && Collisions::collidesWithRotation((*itBHoles), (*itBullets))) {
					c->globalSend(this, msg::BulletBlackHoleCollision(msg::ObjectId::None, msg::ObjectId::Broadcast, (*itBHoles), (*itBullets)));
				}
			}
		}
	}
}

void BulletBlackHoleCollision::receive(Container * c, const msg::Message & msg)
{
	switch (msg.type_) {
	case msg::BULLETS_INFO: {
		const msg::BulletsInfoMsg& m1 = static_cast<const msg::BulletsInfoMsg&>(msg);
		bullets_ = m1.bullets_;
		break;
	}
	case msg::BLACK_HOLES_INFO: {
		const msg::BlackHolesInfo& m2 = static_cast<const msg::BlackHolesInfo&>(msg);
		blackHoles_ = m2.blackHoles_;
		break;
	}
	default:
		break;
	}
}
