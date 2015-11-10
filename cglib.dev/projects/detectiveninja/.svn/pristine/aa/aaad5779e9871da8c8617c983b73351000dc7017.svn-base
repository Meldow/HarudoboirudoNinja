#include "LoadLevel2Command.h"

namespace proj {
	
	LoadLevel2Command::LoadLevel2Command() : Command("LEVEL 2") {
	}
	LoadLevel2Command::~LoadLevel2Command(){
	}

	void LoadLevel2Command::execute() {
		LevelManager* lm = static_cast<LevelManager*>(cg::Registry::instance()->get("LevelManager"));
		lm->loadLevel(new Level2());
		dynamic_cast<MainApp*>(cg::Manager::instance()->getApp())->unpause();
	}
}