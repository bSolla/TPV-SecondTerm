#pragma once

#include <vector>
#include "Vector2D.h"
#include "GameObject.h"

// you can replace these lines by corresponding
// includes once the classes are defined

class Asteroid;
class Bullet;
class BlackHole;

namespace msg {

struct Message {
	Message(msg::MessageType type, msg::ObjectId sender, msg::ObjectId destination) :
			type_(type), sender_(sender), destination_(destination) {
	}

	msg::MessageType type_;
	msg::ObjectId sender_;
	msg::ObjectId destination_;
};

struct Shoot: public msg::Message {
	Shoot(msg::ObjectId sender, msg::ObjectId destination, Vector2D pos, Vector2D dir, int type) :
	Message(msg::FIGHTER_SHOOT, sender, destination), pos_(pos), dir_(dir), type_(type) {
	}

	Vector2D pos_;
	Vector2D dir_;
	int type_;
};

struct BulletAsteroidCollision: public msg::Message {
	BulletAsteroidCollision(msg::ObjectId sender, msg::ObjectId destination, Bullet* bullet, Asteroid* asteroid) :
	Message(msg::BULLET_ASTEROID_COLLISION, sender, destination), bullet_(bullet), asteroid_(asteroid)  {
	}

	Bullet* bullet_;
	Asteroid* asteroid_;
};

struct FighterAsteroidCollisionMsg: public msg::Message {
	FighterAsteroidCollisionMsg(msg::ObjectId sender, msg::ObjectId destination, GameObject* fighter, Asteroid* asteroid) :
	Message(msg::FIGHTER_ASTEROID_COLLISION, sender, destination), fighter_(fighter), asteroid_(asteroid)  {
	}

	GameObject* fighter_;
	Asteroid* asteroid_;
};

struct AsteroidDestroyed: public msg::Message {
	AsteroidDestroyed(msg::ObjectId sender, msg::ObjectId destination, int points) :
	Message(msg::ASTEROID_DESTROYED, sender, destination), points_(points)  {
	}

	int points_;
};

struct FighterInfo: public msg::Message {
	FighterInfo(msg::ObjectId sender, msg::ObjectId destination, GameObject* fighter) :
	Message(msg::FIGHTER_INFO, sender, destination), fighter_(fighter)  {
	}

	GameObject*  fighter_;
};

struct BulletsInfoMsg: public msg::Message {
	BulletsInfoMsg(msg::ObjectId sender, msg::ObjectId destination, const std::vector<Bullet*>* bullets) :
	Message(msg::BULLETS_INFO, sender, destination), bullets_(bullets)  {
	}
	const std::vector<Bullet*>*  bullets_;
};

struct AsteroidsInfo: public msg::Message {
	AsteroidsInfo(msg::ObjectId sender, msg::ObjectId destination, const std::vector<Asteroid*>* asteroids) :
	Message(msg::ASTEROIDS_INFO, sender, destination), asteroids_(asteroids)  {
	}
	const std::vector<Asteroid*>*  asteroids_;
};

struct AsteroidBlackHoleCollision : public msg::Message {
	AsteroidBlackHoleCollision(msg::ObjectId sender, msg::ObjectId destination, BlackHole* blackHole, Asteroid* asteroid) :
	Message(msg::ASTEROID_BLACK_HOLE_COLLISION, sender, destination), blackHole_(blackHole), asteroid_(asteroid)  {
	}

	BlackHole* blackHole_;
	Asteroid* asteroid_;
};

struct BulletBlackHoleCollision : public msg::Message {
	BulletBlackHoleCollision(msg::ObjectId sender, msg::ObjectId destination, BlackHole* blackHole, Bullet* bullet) :
		Message(msg::BULLET_BLACK_HOLE_COLLISION, sender, destination), blackHole_(blackHole), bullet_(bullet) {
	}

	BlackHole* blackHole_;
	Bullet* bullet_;
};

struct FighterBlackHoleCollision : public msg::Message {
	FighterBlackHoleCollision(msg::ObjectId sender, msg::ObjectId destination, BlackHole* blackHole, GameObject* fighter) :
		Message(msg::FIGHTER_BLACK_HOLE_COLLISION, sender, destination), blackHole_(blackHole), fighter_(fighter) {
	}

	BlackHole* blackHole_;
	GameObject* fighter_;
};

struct BlackHolesInfo : public msg::Message {
	BlackHolesInfo(msg::ObjectId sender, msg::ObjectId destination, const std::vector<BlackHole*>* blackHoles) :
		Message(msg::BLACK_HOLES_INFO, sender, destination), blackHoles_(blackHoles) {
	}
	const std::vector<BlackHole*>*  blackHoles_;
};

};
