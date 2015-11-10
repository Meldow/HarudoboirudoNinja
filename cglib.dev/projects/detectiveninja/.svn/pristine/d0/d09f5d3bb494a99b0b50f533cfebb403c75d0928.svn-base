#include "ResetLevelCommand.h"

namespace proj {
	
	ResetLevelCommand::ResetLevelCommand() : Command("RESET LEVEL") {
	}
	ResetLevelCommand::~ResetLevelCommand(){
	}

	void ResetLevelCommand::execute() {
		static_cast<LevelManager*>(cg::Registry::instance()->get("LevelManager"))->restartLevel();
		dynamic_cast<MainApp*>(cg::Manager::instance()->getApp())->unpause();
	}
}
