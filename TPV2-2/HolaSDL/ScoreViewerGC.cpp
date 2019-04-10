#include "ScoreViewerGC.h"
#include "GameManager.h"


ScoreViewerGC::ScoreViewerGC (GameManager *gameManager) {
	gm = gameManager;
}


ScoreViewerGC::~ScoreViewerGC () {
}

void ScoreViewerGC::render (Container * c, Uint32 time) {
	Texture text(c->getGame()->getRenderer(),
			"POINTS: ",
			*(c->getGame()->getServiceLocator()->getFonts()->getFont(Resources::ARIAL24)), 
			{ COLOR(0xffffffff) });
	Texture scoreText(c->getGame()->getRenderer(),
			to_string(gm->getScore()),
			*(c->getGame()->getServiceLocator()->getFonts()->getFont(Resources::ARIAL24)), 
			{ COLOR(0xffffffff) });

	text.render(c->getGame()->getRenderer(),
			30, scoreText.getHeight());
	scoreText.render(c->getGame()->getRenderer(),
			30 + text.getWidth() + scoreText.getWidth(), scoreText.getHeight());
}
