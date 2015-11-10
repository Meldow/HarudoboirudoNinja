#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "Menu.h"
#include "NewGameCommand.h"
#include "ExitToDesktopCommand.h"
#include "LevelSelectMenuCommand.h"

namespace proj {

    class MainMenu :
		public Menu
	{	
    public:
        MainMenu();
        ~MainMenu();
        void init();
  		
	};
}

#endif
