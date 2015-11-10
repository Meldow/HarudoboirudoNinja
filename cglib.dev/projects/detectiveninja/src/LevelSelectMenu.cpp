#include "LevelSelectMenu.h"

namespace proj {
	LevelSelectMenu::LevelSelectMenu() : Menu("LevelSelectMenu"){
		_commands->push_back(new LoadLevel1Command());
		_commands->push_back(new LoadLevel2Command());
		_commands->push_back(new MainMenuCommand());
	}
	LevelSelectMenu::~LevelSelectMenu() {
	}

	void LevelSelectMenu::init() {
		//Menu::init();
	}
}