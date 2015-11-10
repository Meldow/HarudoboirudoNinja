#ifndef LEVEL_SELECT_COMMAND_H
#define LEVEL_SELECT_COMMAND_H

#include "Command.h"
#include "LevelSelectMenu.h"
#include "MenuManager.h"
#include "cg/cg.h"

namespace proj {

    class LevelSelectMenuCommand :  
		public Command
	{
    public:
        LevelSelectMenuCommand();
        ~LevelSelectMenuCommand();
		void execute();
	};
}

#endif
