#ifndef MATERIAL_MANAGER_H
#define MATERIAL_MANAGER_H


#include <string.h>
#include <list>
#include "cg/cg.h"
#include "MaterialManager.h"
#include "Material.h"

namespace proj {

	class MaterialManager : public cg::Entity
	{
	private:
		std::list<Material*>* _materials;
	public:
		MaterialManager();
		~MaterialManager();
		void init();
		void add(Material* m);
		void clear();
		Material* get(std::string name);
	};
}

#endif