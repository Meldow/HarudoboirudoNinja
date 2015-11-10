#include "BoundingSphere.h"

namespace proj {

	BoundingSphere::BoundingSphere(float radius, cg::Vector3d position) {

		_isColliding = false;

		_radius = radius;
		_position = position;

		_defaultColor[0] = 0.0f;
		_defaultColor[1] = 0.0f;
		_defaultColor[2] = 1.0f;

		_collidingColor[0] = 1.0f;
		_collidingColor[1] = 0.0f;
		_collidingColor[2] = 0.0f;
	}

	BoundingSphere::~BoundingSphere() {}

	float BoundingSphere::getRadius() {
		return _radius;
	}

	cg::Vector3d BoundingSphere::getPosition() {
		return _position;
	}

	float* BoundingSphere::getColor() {
		if (_isColliding) {
			return _collidingColor;
		}
		else {
			return _defaultColor;
		}
	}

	void BoundingSphere::updatePosition(cg::Vector3d newPosition) {
		_position = newPosition;
	}
	
	void BoundingSphere::isColliding(bool isColliding) {
		_isColliding = isColliding;
	}
}