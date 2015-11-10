#ifndef SKYBOX_H
#define SKYBOX_H

#include "cg/cg.h"
#include "TextureManager.h"

namespace proj {

	class Skybox : public cg::Entity,
		public cg::IDrawListener
	{
	private:
		float _width, _height, _length;

	public:
		Skybox();
		~Skybox();

		void init();
		void draw();
	};
}

#endif