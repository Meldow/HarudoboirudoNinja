#include "NewGameCommand.h"

namespace proj {
	
	NewGameCommand::NewGameCommand() : Command("NEW GAME") {
	}
	NewGameCommand::~NewGameCommand(){
	}

	void NewGameCommand::execute() {
		printf("EXECUTING COMMAND NEW GAME\n");
		LevelManager* lm = static_cast<LevelManager*>(cg::Registry::instance()->get("LevelManager"));
		lm->loadLevel(new Level1());
		dynamic_cast<MainApp*>(cg::Manager::instance()->getApp())->unpause();
	}
}
