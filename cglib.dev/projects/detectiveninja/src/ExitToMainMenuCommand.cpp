#include "ExitToMainMenuCommand.h"

namespace proj {
	
	ExitToMainMenuCommand::ExitToMainMenuCommand() : Command("EXIT TO MAIN MENU") {
	}
	ExitToMainMenuCommand::~ExitToMainMenuCommand(){
	}

	void ExitToMainMenuCommand::execute() {
		static_cast<MenuManager*>(cg::Registry::instance()->get("MenuManager"))->goToMenuByName("MainMenu");
		static_cast<LevelManager*>(cg::Registry::instance()->get("LevelManager"))->loadLevel(new Level1());
		static_cast<MainApp*>(cg::Manager::instance()->getApp())->pause();
	}
}