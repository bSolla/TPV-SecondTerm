#include "GameCtrlIC.h"
#include "GameManager.h"

#include "InputHandler.h"

GameCtrlIC::GameCtrlIC (GameManager* gameManager) {
	gm = gameManager;
}


GameCtrlIC::~GameCtrlIC () {
}


void GameCtrlIC::handleInput (Container * c, Uint32 time) {
	if (!gm->getRunning ()) {
		if (InputHandler::getInstance()->isKeyDown(SDLK_RETURN))
		{
			if (gm->getCurrentLives() == gm->getMaxLives() || gm->getCurrentLives() == 0) {
				c->globalSend(this, msg::Message(msg::GAME_START, msg::ObjectId::Broadcast, msg::ObjectId::Broadcast));
			}
			// always send round start
			c->globalSend(this, msg::Message(msg::ROUND_START, msg::ObjectId::Broadcast, msg::ObjectId::Broadcast));
		}
		//if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_RETURN) {
		//	// if the game is starting, send ROUND_START
		//	if (gm->getCurrentLives () == gm->getMaxLives () || gm->getCurrentLives() == 0) {
		//		c->globalSend (this, msg::Message (msg::GAME_START, msg::ObjectId::Broadcast, msg::ObjectId::Broadcast));
		//	}

		//	// always send round start
		//	c->globalSend (this, msg::Message (msg::ROUND_START, msg::ObjectId::Broadcast, msg::ObjectId::Broadcast));
		//}
	}
}
