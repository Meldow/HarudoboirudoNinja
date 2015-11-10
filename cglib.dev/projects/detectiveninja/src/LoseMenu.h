#ifndef LOSE_MENU_H
#define LOSE_MENU_H

#include "Menu.h"
#include "ExitToMainMenuCommand.h"
#include "ExitToDesktopCommand.h"
#include "ResetLevelCommand.h"

namespace proj {

    class LoseMenu :
		public Menu
	{	
    public:
        LoseMenu();
        ~LoseMenu();
        void init();
  		
	};
}

#endif