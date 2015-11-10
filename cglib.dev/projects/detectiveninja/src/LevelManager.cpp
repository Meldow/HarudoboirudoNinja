#include "LevelManager.h"

namespace proj {

	LevelManager::LevelManager() : Entity("LevelManager") {
		_currentClues = 0;
		_currentEntities = new std::list<std::string>();
	}
	LevelManager::~LevelManager() {}
	
	void LevelManager::init() {
		
		
	}

	void LevelManager::onClueGet() {
		_currentClues++;
		
		//checks if level is over
		if(_currentClues == _currentLevel->getTotalClues()) {
			static_cast<Scene*>( cg::Registry::instance()->get("Scene"))->onWin();
			static_cast<MenuManager*>(cg::Registry::instance()->get("MenuManager"))->goToMenuByName("WonLevelMenu");
			static_cast<MainApp*>(cg::Manager::instance()->getApp())->pause();
		}
	}
	
	void LevelManager::loadLevel(Level* lvl) {
		printf("STARTING TO LOAD LEVEL \n" );
		
		std::cout << "Entities::start " << cg::Registry::instance()->size() << "\n";
		
		_currentLevel = lvl;
		_currentClues = 0;
		static_cast<Scene*>(cg::Registry::instance()->get("Scene"))->reset();
		
		MaterialManager* materialManager = dynamic_cast<MaterialManager*>(cg::Registry::instance()->get("MaterialManager"));
		TextureManager* textureManager = dynamic_cast<TextureManager*>(cg::Registry::instance()->get("TextureManager"));

		materialManager->clear();
		std::list<Material*>::iterator matit;
		for(matit = lvl->getMaterials()->begin(); matit != lvl->getMaterials()->end(); matit++) {
			materialManager->add(*matit);
		}

		textureManager->clear();
		std::list<Texture*>::iterator texit;
		textureManager->addMap(lvl->getMapTex());
		for(texit = lvl->getTextures()->begin(); texit != lvl->getTextures()->end(); texit++) {
			textureManager->add(*texit);
		}


		printf("LEVEL MANAGER: REMOVING PREVIOUS ENTITIES\n");
		//clearing old ones (if there are any)
		cg::View* v1 = static_cast<cg::View*>(cg::Registry::instance()->get("view1"));
		std::list<std::string>::iterator entitiesit;
		for(entitiesit = _currentEntities->begin(); entitiesit != _currentEntities->end(); entitiesit++) {
			v1->unlinkEntity(*entitiesit);
			cg::Registry::instance()->remove(*entitiesit);
		}
		
		std::cout << "Entities::after_unlink " << cg::Registry::instance()->size() << "\n";
		DebugManager* dm = static_cast<DebugManager*>(cg::Registry::instance()->get("DebugManager"));
		std::cout << "Debugmanager::Before " << dm->getListsSize() << "\n";


		printf("LEVEL MANAGER: REMOVING DEBUG LISTENERS\n");
		//removing everything registered for Debug (Ninja is always there)
		//DebugManager* dm = static_cast<DebugManager*>(cg::Registry::instance()->get("DebugManager"));
		dm->dispose();
		dm->disableDebug();

		std::cout << "Debugmanager::After " << dm->getListsSize() << "\n";
		
		CollisionManager* cm = static_cast<CollisionManager*>(cg::Registry::instance()->get("CollisionManager"));
		std::cout << "Collision::Before " << cm->getListsSize() << "\n";
		

		printf("LEVEL MANAGER: REMOVING COLLISION LISTENERS\n");
		//removing everything except Ninja from Collisions
		//CollisionManager* cm = static_cast<CollisionManager*>(cg::Registry::instance()->get("CollisionManager"));
		cm->dispose();
		
		
		std::cout << "Collision::After " << cm->getListsSize() << "\n";
		std::cout << "Entities::after_managers " << cg::Registry::instance()->size() << "\n";

		_currentEntities->clear();

		std::cout << "Entities::after_clean_entities " << cg::Registry::instance()->size() << "\n";

		printf("LEVEL MANAGER: STARTING TO LOAD HEIGHT MAP\n");
		ImageLoaderHeightMap* ilhm = static_cast<ImageLoaderHeightMap*>(cg::Registry::instance()->get("mappedterrain"));
		if(ilhm != NULL)
			ilhm->setHeightMap(LEVEL_PATH + _currentLevel->getHeightMap());
		else {
			ilhm = new ImageLoaderHeightMap("mappedterrain", LEVEL_PATH + _currentLevel->getHeightMap());
			cg::Registry::instance()->add(ilhm);
		}

		std::cout << "Entities::after_heightmap " << cg::Registry::instance()->size() << "\n";

		printf("LEVEL MANAGER: STARTING TO LOAD ITEM MAP\n");
		ImageLoaderItemMap* ilim = static_cast<ImageLoaderItemMap*>(cg::Registry::instance()->get("mappeditems"));
		if(ilim != NULL)
			ilim->setItemMap(LEVEL_PATH + _currentLevel->getHeightMap(), LEVEL_PATH + _currentLevel->getItemMap());
		else {
			ilim = new ImageLoaderItemMap("mappeditems", LEVEL_PATH + _currentLevel->getHeightMap(), LEVEL_PATH + _currentLevel->getItemMap());
			cg::Registry::instance()->add(ilim);
		}
		
		
		for(entitiesit = _currentEntities->begin(); entitiesit != _currentEntities->end(); entitiesit++) {
			cg::Registry::instance()->get(*entitiesit)->init();
		}

		//reset ninja position
		printf("LEVEL MANAGER: RESETING NINJA POSITION\n");
		Ninja* ninja = dynamic_cast<Ninja*>(cg::Registry::instance()->get("Ninja"));
		ninja->reset();

		static_cast<Camera*>(cg::Registry::instance()->get("Camera"))->mainCamera();

		std::cout << "Entities::after_itemmap " << cg::Registry::instance()->size() << "\n";
		std::cout << "Debugmanager::After " << dm->getListsSize() << "\n";
		std::cout << "Collision::After " << cm->getListsSize() << "\n";
		printf("LEVEL LOADED\n");
	}

	void LevelManager::restartLevel() {
		_currentLevel->resetLevel();
		loadLevel(_currentLevel);
	}

	int LevelManager::getTotalClues() {
		return _currentLevel->getTotalClues();
	}

	int LevelManager::getCurrentClues() {
		return _currentClues;
	}

	void LevelManager::addClue() {
		_currentLevel->addClue();
	}

	Level* LevelManager::getCurrentLevel() {
		return _currentLevel;
	}

	void LevelManager::addEntity(std::string id) {
		_currentEntities->push_back(id);
	}

	std::list<std::string>* LevelManager::getCurrentEntities() {
		return _currentEntities;
	}
}