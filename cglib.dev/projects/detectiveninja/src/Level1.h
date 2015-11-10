#ifndef LEVEL1_H
#define LEVEL1_H

#include <list>
#include "Material.h"
#include "Texture.h"
#include "Level.h"

namespace proj {

	class Level1 : 
		public Level
	{
	public:
		Level1();
		~Level1();
		void init();
	};
}


#endif