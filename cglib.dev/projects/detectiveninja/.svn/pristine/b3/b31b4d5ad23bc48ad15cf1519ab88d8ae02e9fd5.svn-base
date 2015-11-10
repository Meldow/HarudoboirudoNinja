#ifndef OBJECT_CLUE_H
#define OBJECT_CLUE_H

#include <string>
#include <math.h>
#include "cg/cg.h"
#include "WorldObject.h"
#include "CollisionManager.h"
#include "TextureManager.h"
#include "LevelManager.h"

#define CLUE_SIZE	5.0f

namespace proj {

	class ObjectClue : public WorldObject
	{
	private:
		bool _caught;

	protected:
		void registerToCollisionManager();
		void createBoundingSpheres();
		void updateBoundingSpheres();

	public:
		ObjectClue(std::string id, cg::Vector3d position);
		~ObjectClue();

		void init();
		void update(unsigned long elapsed_millis);
		void draw();
		void setup();

		cg::Vector3d getPosition();
		cg::Vector3d getFront();
		void setHeight(int height);
	};
}

#endif