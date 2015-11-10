#include "MaterialManager.h"

namespace proj {

	MaterialManager::MaterialManager() : Entity("MaterialManager") {
		_materials = new std::list<Material*>();
	}
	MaterialManager::~MaterialManager() {}
	
	void MaterialManager::init() {
		
	}

	void MaterialManager::add(Material* m) {
		m->makeMaterial();
		_materials->push_back(m);
	}

	void MaterialManager::clear() {
		_materials->clear();
	}

	Material* MaterialManager::get(std::string name) {
		Material* material = NULL;
		
		std::list<Material*>::iterator it;

		for(it = _materials->begin(); it != _materials->end(); it++) {
			if(!(*it)->getName().compare(name))
				material = *it;
		}
		
		return material;
	}

}