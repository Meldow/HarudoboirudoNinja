#include "Collidable.h"

namespace proj {

	Collidable::Collidable() {
		_isColliding = false;
		_boundingSpheres = new std::vector<BoundingSphere*>();
	}
	Collidable::~Collidable() {}

	void Collidable::addBoundingSphere(BoundingSphere* boundingSphere) {
		_boundingSpheres->push_back(boundingSphere);
	}

	BoundingSphere* Collidable::getBoundingSphere(int index) {
		return _boundingSpheres->at(index);
	}

	std::vector<BoundingSphere*>* Collidable::getBoundingSpheres() {
		return _boundingSpheres;
	}

	void Collidable::isColliding() {
		_isColliding = true;
	}
}