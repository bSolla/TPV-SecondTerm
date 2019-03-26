#include "GameCtrlIC.h"
#include "GameManager.h"


GameCtrlIC::GameCtrlIC (GameManager* gameManager) {
	gm = gameManager;
}


GameCtrlIC::~GameCtrlIC () {
}


void GameCtrlIC::handleInput (Container * c, Uint32 time, const SDL_Event & event) {
	if (!gm->getRunning ()) {
		if (event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_RETURN) {
			// if the game is starting, send ROUND_START
			if (gm->getCurrentLives () == gm->getMaxLives ()) {
				//c->globalSend (this, msg::Message (msg::GAME_START, msg::ObjectId::Broadcast, msg::ObjectId::Broadcast));
				c->getGame ()->send (this, msg::Message (msg::GAME_START, msg::ObjectId::Broadcast, msg::ObjectId::Broadcast));
			}

			// always send round start
			c->globalSend (this, msg::Message (msg::ROUND_START, msg::ObjectId::Broadcast, msg::ObjectId::Broadcast));
			//c->getGame ()->send (this, msg::Message (msg::ROUND_START, msg::ObjectId::Broadcast, msg::ObjectId::Broadcast));
		}
	}
}
