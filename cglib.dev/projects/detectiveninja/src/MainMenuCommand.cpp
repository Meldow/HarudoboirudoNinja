#include "MainMenuCommand.h"

namespace proj {
	
	MainMenuCommand::MainMenuCommand() : Command("BACK TO MAIN MENU") {
	}
	MainMenuCommand::~MainMenuCommand(){
	}

	void MainMenuCommand::execute() {
		static_cast<MenuManager*>(cg::Registry::instance()->get("MenuManager"))->goToMenuByName("MainMenu");
		//static_cast<MainApp*>(cg::Manager::instance()->getApp())->pause();
	}
}
