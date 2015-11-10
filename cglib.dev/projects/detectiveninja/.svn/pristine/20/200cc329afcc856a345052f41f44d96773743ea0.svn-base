#include "Level.h"

namespace proj {

	Level::Level(int nr, std::string name, std::string heightmap, std::string itemmap) {
		_levelNumber = nr;
		_lvlName = name;
		_heightmap = heightmap;
		_itemmap = itemmap;
		_levelMats = new std::list<Material*>();
		_levelTexs = new std::list<Texture*>();
		resetLevel();
	}
	Level::~Level() {}

	void Level::init() {
	}

	void Level::addClue() {
		_totalClues++;
	}

	std::list<Material*>* Level::getMaterials() {
		return _levelMats;
	}

	std::list<Texture*>* Level::getTextures() {
		return _levelTexs;
	}

	int Level::getTotalClues() {
		return _totalClues;
	}

	std::string Level::getHeightMap() {
		return _heightmap;
	}

	std::string Level::getItemMap() {
		return _itemmap;
	}
	
	void Level::resetLevel() {
		_totalClues = 0;
	}

	std::string Level::getMapTex() {
		return _maptex;
	}
}