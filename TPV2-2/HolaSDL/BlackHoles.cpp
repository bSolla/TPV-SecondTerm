#include "BlackHoles.h"



BlackHoles::BlackHoles(SDLGame* game):
	GameObjectPool(game),
	blackHoleImage_(game->getServiceLocator()->getTextures()->getTexture(Resources::BlackHole)),
	rotating_(ALPHA)
{
	for (BlackHole *a : getAllObjects()) {
		a->addC(&blackHoleImage_);
		a->addC(&rotating_);
	}

	setId(msg::BlackHoles);
	game_->addObserver(this);

	setActive(false);
}


BlackHoles::~BlackHoles()
{
}

void BlackHoles::receive(const void * senderObj, const msg::Message & msg)
{
	Container::receive(senderObj, msg);

	switch (msg.type_) {
	case msg::GAME_START:
		num_ = 2;
		globalSend(this, msg::BlackHolesInfo(msg::BlackHoles, msg::Broadcast, &getAllObjects()));
		break;
	case msg::ROUND_START:
		setActive(true);
		newRoundCreation();
		break;
	case msg::ROUND_OVER:
		deactiveAllObjects();
		setActive(false);
		num_ *= 2;
		break;
	default:
		break;
	}
}

void BlackHoles::newRoundCreation()
{
	Vector2D pos;
	int x, y;

	for (int i = 0; i < num_; i++) {
		int rand = (game_->getServiceLocator()->getRandomGenerator()->nextInt(1, 5));

		switch (rand) {
		case 1:
			x = game_->getServiceLocator()->getRandomGenerator()->nextInt(BLACK_HOLE_SIZE, (game_->getWindowWidth() / 2) - 100);
			y = game_->getServiceLocator()->getRandomGenerator()->nextInt(BLACK_HOLE_SIZE, (game_->getWindowHeight() / 2) - 100);
			pos = Vector2D(x, y);
			break;
		case 2:
			x = game_->getServiceLocator()->getRandomGenerator()->nextInt((game_->getWindowWidth() / 2) + 100, game_->getWindowWidth() - BLACK_HOLE_SIZE);
			y = game_->getServiceLocator()->getRandomGenerator()->nextInt(BLACK_HOLE_SIZE, (game_->getWindowHeight() / 2) - 100);
			pos = Vector2D(x, y);
			break;
		case 3:
			x = game_->getServiceLocator()->getRandomGenerator()->nextInt(BLACK_HOLE_SIZE, (game_->getWindowWidth() / 2) - 100);
			y = game_->getServiceLocator()->getRandomGenerator()->nextInt((game_->getWindowHeight() / 2) + 100, game_->getWindowHeight() - BLACK_HOLE_SIZE);
			pos = Vector2D(x, y);
			break;
		case 4:
			x = game_->getServiceLocator()->getRandomGenerator()->nextInt((game_->getWindowWidth() / 2) + 100, game_->getWindowWidth() - BLACK_HOLE_SIZE);
			y = game_->getServiceLocator()->getRandomGenerator()->nextInt((game_->getWindowHeight() / 2) + 100, game_->getWindowHeight() - BLACK_HOLE_SIZE);
			pos = Vector2D(x, y);
			break;
		default:
			break;
		}

		create(pos);
	}
}

void BlackHoles::create(Vector2D pos)
{
	BlackHole *a = getUnusedObject();
	a->setWidth(BLACK_HOLE_SIZE);
	a->setHeight(BLACK_HOLE_SIZE);
	a->setPosition(pos);

	Vector2D c = Vector2D(getGame()->getWindowWidth() / 2, getGame()->getWindowHeight() / 2);

	a->setActive(true);
}
