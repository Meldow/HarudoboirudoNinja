#include "DebugManager.h"

namespace proj {

	DebugManager::DebugManager() : Entity("DebugManager") {

		_debugModeActive = false;
		_mapDebugModeActive = _playerDebugModeActive = _enemyDebugModeActive = _staticObjectDebugModeActive = false;

		_debugMaps			= new std::list<Debug*>();
		_debugPlayers		= new std::list<Debug*>();
		_debugEnemies		= new std::list<Debug*>();
		_debugStaticObjects	= new std::list<Debug*>();		
	}
	DebugManager::~DebugManager() {}

	void DebugManager::init() {}

	bool DebugManager::isDebugModeActive() {
		return _debugModeActive;
	}

	void DebugManager::toggleDebugMode() {
		if(_debugModeActive)
			disableDebug();
		else
			enableDebug();
	}

	void DebugManager::switchDebugListOn(std::list<Debug*>* dlist) {

		std::list<Debug*>::iterator it;
		for(it = dlist->begin(); it != dlist->end(); it++) {
			(*it)->enableDebug();
		}
	}

	void DebugManager::switchDebugListOff(std::list<Debug*>* dlist) {

		std::list<Debug*>::iterator it;
		for(it = dlist->begin(); it != dlist->end(); it++) {
			(*it)->disableDebug();
		}
	}

	void DebugManager::registerMap(Debug* map) {
		_debugMaps->push_back(map);
	}

	void DebugManager::registerPlayer(Debug* player) {
		_debugPlayers->push_back(player);
	}

	void DebugManager::registerEnemy(Debug* enemy) {
		_debugEnemies->push_back(enemy);
	}

	void DebugManager::registerStaticObject(Debug* staticObject) {
		_debugStaticObjects->push_back(staticObject);
	}

	void DebugManager::clearDebugMaps() {
		_debugMaps->clear();
	}

	void DebugManager::clearDebugPlayers() {
		_debugPlayers->clear();
	}

	void DebugManager::clearDebugEnemies() {
		_debugEnemies->clear();
	}

	void DebugManager::clearDebugStaticObjects() {
		_debugStaticObjects->clear();
	}

	void DebugManager::toggleMapDebugMode() {

		_mapDebugModeActive = !_mapDebugModeActive;

		if (_mapDebugModeActive) {
			switchDebugListOn(_debugMaps);
		}
		else {
			switchDebugListOff(_debugMaps);
		}
	}
	void DebugManager::togglePlayerDebugMode() {
		
		_playerDebugModeActive = !_playerDebugModeActive;

		if (_playerDebugModeActive) {
			switchDebugListOn(_debugPlayers);
		}
		else {
			switchDebugListOff(_debugPlayers);
		}
	}
	void DebugManager::toggleEnemyDebugMode() {
		
		_enemyDebugModeActive = !_enemyDebugModeActive;

		if (_enemyDebugModeActive) {
			switchDebugListOn(_debugEnemies);
		}
		else {
			switchDebugListOff(_debugEnemies);
		}
	}
	void DebugManager::toggleStaticObjectDebugMode() {
		
		_staticObjectDebugModeActive = !_staticObjectDebugModeActive;

		if (_staticObjectDebugModeActive) {
			switchDebugListOn(_debugStaticObjects);
		}
		else {
			switchDebugListOff(_debugStaticObjects);
		}
	}

	void DebugManager::dispose() {

		clearDebugMaps();
		clearDebugEnemies();
		clearDebugStaticObjects();
	}

	int DebugManager::getListsSize() {

		int result = 0;

		result += _debugMaps->size();
		result += _debugEnemies->size();
		result += _debugStaticObjects->size();

		return result;
	}

	void DebugManager::enableDebug() {
		_debugModeActive = true;
		static_cast<Camera*>(cg::Registry::instance()->get("Camera"))->freeCamera();
	}

	void DebugManager::disableDebug() {
		_debugModeActive = false;
		static_cast<Camera*>(cg::Registry::instance()->get("Camera"))->mainCamera();
		switchDebugListOff(_debugMaps);
		switchDebugListOff(_debugPlayers);
		switchDebugListOff(_debugEnemies);
		switchDebugListOff(_debugStaticObjects);
	}
}