#ifndef OBJECT_STATIC_BOX_H
#define OBJECT_STATIC_BOX_H

#include <string>
#include <math.h>
#include "cg/cg.h"
#include "WorldObject.h"
#include "CollisionManager.h"
#include "TextureManager.h"
#include "DebugManager.h"

namespace proj {

	class ObjectStaticBox : public WorldObject
	{
	private:
		double _boxSize;

	protected:
		void registerToCollisionManager();
		void createBoundingSpheres();
		void updateBoundingSpheres();

	public:
		ObjectStaticBox(std::string id, cg::Vector3d position, double size);
		~ObjectStaticBox();

		void init();
		void update(unsigned long elapsed_millis);
		void draw();

		cg::Vector3d getPosition();
		cg::Vector3d getFront();
		void setHeight(int height);
	};
}

#endif