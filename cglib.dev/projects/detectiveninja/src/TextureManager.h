#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H


#include <string.h>
#include <list>
#include "cg/cg.h"
#include "Texture.h"
#include "FreeImage.h"

namespace proj {

	class TextureManager : public cg::Entity
	{
	private:
		std::list<Texture*>* _textures;
		std::string _mapTex;
	public:
		TextureManager();
		~TextureManager();
		void init();
		void add(Texture* m);
		void addMap(std::string mapt);
		void clear();

		std::string getMapTexName();
		Texture* get(std::string name);
	};
}

#endif