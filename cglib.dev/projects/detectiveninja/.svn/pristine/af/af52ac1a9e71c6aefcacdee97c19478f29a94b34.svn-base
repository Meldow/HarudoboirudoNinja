#include "TextureManager.h"

namespace proj {

	TextureManager::TextureManager() : Entity("TextureManager") {
		_textures = new std::list<Texture*>();
	}
	TextureManager::~TextureManager() {}
	
	void TextureManager::init() {
		

		/*
		add(new Texture("crate", "tga"));
		add(new Texture("ninja_face", "tga"));
		*/
	}

	void TextureManager::add(Texture* t) {
		t->makeTexture();
		_textures->push_back(t);
	}

	void TextureManager::addMap(std::string mapt) {
		_mapTex = mapt;
	}
	

	void TextureManager::clear() {
		_textures->clear();
	}

	
	Texture* TextureManager::get(std::string name) {
		
		Texture* texture = NULL;
		
		std::list<Texture*>::iterator it;

		for(it = _textures->begin(); it != _textures->end(); it++) {
			if(!(*it)->getName().compare(name))
				texture = *it;
		}
		
		return texture;

	}

	std::string TextureManager::getMapTexName() {
		return _mapTex;
	}

}