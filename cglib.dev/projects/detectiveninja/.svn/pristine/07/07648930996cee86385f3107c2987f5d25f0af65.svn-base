#include "LoadLevel1Command.h"

namespace proj {
	
	LoadLevel1Command::LoadLevel1Command() : Command("LEVEL 1") {
	}
	LoadLevel1Command::~LoadLevel1Command(){
	}

	void LoadLevel1Command::execute() {
		LevelManager* lm = static_cast<LevelManager*>(cg::Registry::instance()->get("LevelManager"));
		lm->loadLevel(new Level1());
		dynamic_cast<MainApp*>(cg::Manager::instance()->getApp())->unpause();
	}
}
