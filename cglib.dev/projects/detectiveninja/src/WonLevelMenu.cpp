#include "WonLevelMenu.h"

namespace proj {
	WonLevelMenu::WonLevelMenu() : Menu("WonLevelMenu"){
		_commands->push_back(new LevelSelectMenuCommand());
		_commands->push_back(new ResetLevelCommand());
		_commands->push_back(new ExitToMainMenuCommand());
		_commands->push_back(new ExitToDesktopCommand());
	}
	WonLevelMenu::~WonLevelMenu() {
	}

	void WonLevelMenu::init() {
		//Menu::init();
	}
}