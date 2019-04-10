#include "LivesViewer.h"
#include "GameManager.h"


LivesViewer::LivesViewer (GameManager *gameManager) {
	gm = gameManager;
}


LivesViewer::~LivesViewer () {
}

void LivesViewer::render (Container * c, Uint32 time) {
	Texture text(c->getGame()->getRenderer(),
			"LIVES: ",
			*(c->getGame()->getServiceLocator()->getFonts()->getFont(Resources::ARIAL24)), 
			{ COLOR(0xffffffff) });
	Texture livesText(c->getGame()->getRenderer(),
			to_string(gm->getCurrentLives()),
			*(c->getGame()->getServiceLocator()->getFonts()->getFont(Resources::ARIAL24)), 
			{ COLOR(0xffffffff) });

	text.render(c->getGame()->getRenderer(),
			30, 2 * livesText.getHeight());
	livesText.render(c->getGame()->getRenderer(),
			30 + text.getWidth() + livesText.getWidth(),  2 * livesText.getHeight());
}
