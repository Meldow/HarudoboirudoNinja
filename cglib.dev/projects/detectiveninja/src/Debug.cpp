#include "Debug.h"

namespace proj {

	Debug::Debug() {
		_debugMode = false;
	}
	Debug::~Debug() {}

	void Debug::enableDebug() {
		_debugMode = true;
	}
		
	void Debug::disableDebug() {
		_debugMode = false;
	}

	void Debug::switchDebug() {
		_debugMode = !_debugMode;
	}

	bool Debug::isDebug() {
		return _debugMode;
	}
}