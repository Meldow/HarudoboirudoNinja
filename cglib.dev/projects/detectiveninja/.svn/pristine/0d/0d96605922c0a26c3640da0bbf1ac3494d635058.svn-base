#ifndef LIGHT_H
#define LIGHT_H

#include "cg/cg.h"
#include "Debug.h"
#include "DebugManager.h"

namespace proj {

	class Light : public cg::Entity,
		public cg::IDrawListener,
		public Debug
	{
	private:
		void makeLight(float position[], float direction[]);

	protected:
		GLenum _lightID;
		int _lightDL;

		cg::Vector3f _position;

	public:
		Light(std::string id, GLenum lightConstant, float position[], float direction[]);
		~Light();
		
		void init();
		void draw();

		void setAmbientLight(float params[]);
		void setDiffuseLight(float params[]);
		void setSpecularLight(float params[]);
		void setSpotCuttoff(float angle);
	};
}

#endif