#ifndef COLLIDABLE_H
#define COLLIDABLE_H

#include "cg/cg.h"
#include "BoundingSphere.h"

namespace proj {

	class Collidable 
	{
	private:
		std::vector<BoundingSphere*>* _boundingSpheres;

	protected:
		bool _isColliding;

		virtual void createBoundingSpheres() = 0;
		virtual void updateBoundingSpheres() = 0;

		void addBoundingSphere(BoundingSphere* boundingSphere);

	public:
		Collidable();
		~Collidable();

		void isColliding();

		BoundingSphere* getBoundingSphere(int index);
		std::vector<BoundingSphere*>* getBoundingSpheres();

		virtual cg::Vector3d getPosition() = 0;
		virtual cg::Vector3d getFront() = 0;
		virtual void setHeight(int height) = 0;
	};
}

#endif