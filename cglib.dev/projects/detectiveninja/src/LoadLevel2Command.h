#ifndef LOAD_LEVEL2_COMMAND_H
#define LOAD_LEVEL2_COMMAND_H

#include "Command.h"
#include "Level2.h"
#include "LevelManager.h"
#include "cg/cg.h"

namespace proj {

    class LoadLevel2Command :  
		public Command
	{
    public:
        LoadLevel2Command();
        ~LoadLevel2Command();
		void execute();
	};
}

#endif