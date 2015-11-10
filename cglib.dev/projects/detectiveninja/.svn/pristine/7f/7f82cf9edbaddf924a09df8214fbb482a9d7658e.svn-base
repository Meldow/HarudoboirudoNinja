#ifndef BOUNDING_SPHERE_H
#define BOUNDING_SPHERE_H

#include "cg/cg.h"

namespace proj {

	class BoundingSphere 
	{
	private:
		float _radius;
		cg::Vector3d _position;
		bool _isColliding;
		float _defaultColor[3], _collidingColor[3];

	public:
		BoundingSphere(float radius, cg::Vector3d position);
		~BoundingSphere();

		float getRadius();
		cg::Vector3d getPosition();
		float* getColor();

		void updatePosition(cg::Vector3d newPosition);
		void isColliding(bool isColliding);
	};
}

#endif