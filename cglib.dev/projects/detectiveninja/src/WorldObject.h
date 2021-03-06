#ifndef WORLD_OBJECT_H
#define WORLD_OBJECT_H

#include <string>
#include "cg/cg.h"
#include "Collidable.h"
#include "Debug.h"

namespace proj {

	class WorldObject : public cg::Entity,
		public cg::IDrawListener,
		public cg::IUpdateListener,
		public Collidable,
		public Debug
	{
	private:
		void cube(int n,
			double x0, double y0, double x1, double y1,
			double nx, double ny, double nz,
			double tx0, double ty0, double tx1, double ty1,
			GLuint txFront, GLuint txBack, GLuint txTop, GLuint txBottom, GLuint txRight, GLuint txLeft);
		void dividedPlane(int n,
			double x0, double y0, double x1, double y1,
			double nx, double ny, double nz,
			double tx0, double ty0, double tx1, double ty1);

	protected:
		cg::Vector3d _position;
		void unitCube(GLuint txAll);
		void unitCube(GLuint txFront, GLuint txBack, GLuint txTop, GLuint txBottom, GLuint txRight, GLuint txLeft);

		virtual void registerToCollisionManager() = 0;
		virtual void createBoundingSpheres() = 0;
		virtual void updateBoundingSpheres() = 0;

	public:
		WorldObject(std::string id, cg::Vector3d position);
		~WorldObject();
		
		virtual void init() = 0;
		virtual void update(unsigned long elapsed_millis) = 0;
		virtual void draw() = 0;

		virtual cg::Vector3d getPosition() = 0;
		virtual cg::Vector3d getFront() = 0;
		virtual void setHeight(int height) = 0;

		void toggleDebug();
	};
}

#endif