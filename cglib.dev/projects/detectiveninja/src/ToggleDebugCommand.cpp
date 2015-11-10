#include "ToggleDebugCommand.h"

namespace proj {
	
	ToggleDebugCommand::ToggleDebugCommand() : Command("TOGGLE DEBUG") {
	}
	ToggleDebugCommand::~ToggleDebugCommand(){
	}

	void ToggleDebugCommand::execute() {
		DebugManager* dm = dynamic_cast<DebugManager*>(cg::Registry::instance()->get("DebugManager"));
		Camera* camera = dynamic_cast<Camera*>( cg::Registry::instance()->get("Camera"));
		if(dm->isDebugModeActive())
			camera->mainCamera();
		else
			camera->freeCamera();
		dm->toggleDebugMode();
		static_cast<Scene*>(cg::Registry::instance()->get("Scene"))->switchDebug();
		static_cast<MainApp*>(cg::Manager::instance()->getApp())->unpause();
	}
}
