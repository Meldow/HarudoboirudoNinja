#include "LevelSelectMenuCommand.h"

namespace proj {
	
	LevelSelectMenuCommand::LevelSelectMenuCommand() : Command("LEVEL SELECT") {
	}
	LevelSelectMenuCommand::~LevelSelectMenuCommand(){
	}

	void LevelSelectMenuCommand::execute() {
		static_cast<MenuManager*>(cg::Registry::instance()->get("MenuManager"))->goToMenuByName("LevelSelectMenu");
	}
}
