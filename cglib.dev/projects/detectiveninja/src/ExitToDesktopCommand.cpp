#include "ExitToDesktopCommand.h"

namespace proj {
	
	ExitToDesktopCommand::ExitToDesktopCommand() : Command("EXIT TO DESKTOP") {
	}
	ExitToDesktopCommand::~ExitToDesktopCommand(){
	}

	void ExitToDesktopCommand::execute() {
		printf("EXECUTING COMMAND EXIT TO DESKTOP\n");
		cg::Manager::instance()->shutdownApp();
	}
}
