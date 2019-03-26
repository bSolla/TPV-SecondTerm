#include "GameStatusViewGC.h"
#include "GameManager.h"


GameStatusViewGC::GameStatusViewGC (GameManager *gameManager) {
	gm = gameManager;
}


GameStatusViewGC::~GameStatusViewGC () {
}

void GameStatusViewGC::render (Container * c, Uint32 time) {
	if (!gm->getRunning ()) {
		if (gm->getGameOver ()) {
			Texture text (c->getGame()->getRenderer(),
				"Game Over! Winner: " + gm->getWinner(),
				*(c->getGame()->getServiceLocator()->getFonts()->getFont(Resources::ARIAL24)), 
				{ COLOR(0xffffffff) });

			text.render(c->getGame()->getRenderer(),
				c->getGame()->getWindowWidth() / 2 - text.getWidth() / 2, c->getGame()->getWindowHeight()-150);
		}
		else {
			if (gm->getCurrentLives () == gm->getMaxLives ()) {
				Texture text (c->getGame()->getRenderer(),
					"Press ENTER to start a new game!",
					*(c->getGame()->getServiceLocator()->getFonts()->getFont(Resources::ARIAL24)), 
					{ COLOR(0xffffffff) });
				
				text.render(c->getGame()->getRenderer(),
					c->getGame()->getWindowWidth() / 2 - text.getWidth() / 2, c->getGame()->getWindowHeight()-150);
			}
			else {
				Texture text (c->getGame()->getRenderer(),
					"Press ENTER to continue",
					*(c->getGame()->getServiceLocator()->getFonts()->getFont(Resources::ARIAL24)), 
					{ COLOR(0xffffffff) });
				
				text.render(c->getGame()->getRenderer(),
					c->getGame()->getWindowWidth() / 2 - text.getWidth() / 2, c->getGame()->getWindowHeight()-150);
			}
			
		}
	}
}
