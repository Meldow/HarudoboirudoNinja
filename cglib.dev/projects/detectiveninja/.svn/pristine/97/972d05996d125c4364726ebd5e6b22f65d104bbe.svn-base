#include "InGameMenu.h"

namespace proj {
	InGameMenu::InGameMenu() : Menu("InGameMenu"){
		_commands->push_back(new ResetLevelCommand());
		_commands->push_back(new ToggleDebugCommand());
		_commands->push_back(new ExitToMainMenuCommand());
		_commands->push_back(new ExitToDesktopCommand());
	}
	InGameMenu::~InGameMenu() {
	}

	void InGameMenu::init() {
		//Menu::init();
	}
}