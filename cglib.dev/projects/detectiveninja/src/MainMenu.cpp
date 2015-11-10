#include "MainMenu.h"

namespace proj {
	MainMenu::MainMenu() : Menu("MainMenu"){
		_commands->push_back(new NewGameCommand());	
		_commands->push_back(new LevelSelectMenuCommand());
		_commands->push_back(new ExitToDesktopCommand());
	}
	MainMenu::~MainMenu() {
	}

	void MainMenu::init() {
		//Menu::init();
		

	}

}