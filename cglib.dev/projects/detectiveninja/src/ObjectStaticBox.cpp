#include "ObjectStaticBox.h"

namespace proj {

	ObjectStaticBox::ObjectStaticBox(std::string id, cg::Vector3d position, double size) : WorldObject(id, position) {
		_boxSize = size;
	}
	ObjectStaticBox::~ObjectStaticBox() {}

	void ObjectStaticBox::init() {
		registerToCollisionManager();
		dynamic_cast<DebugManager*>(cg::Registry::instance()->get("DebugManager"))->registerStaticObject(dynamic_cast<Debug*>(this));
	}
	
	void ObjectStaticBox::update(unsigned long elapsed_millis) {}

	void ObjectStaticBox::draw() {

		if (isDebug()) {

			float* color = getBoundingSphere(0)->getColor();
			glPushMatrix();

				glDisable(GL_LIGHTING);

				glColor3f(color[0], color[1], color[2]);
				glTranslated(getBoundingSphere(0)->getPosition()[0], getBoundingSphere(0)->getPosition()[1], getBoundingSphere(0)->getPosition()[2]);
				glutWireSphere(getBoundingSphere(0)->getRadius(), 20, 20);

				glEnable(GL_LIGHTING);

			glPopMatrix();
		}

		TextureManager* tm = dynamic_cast<TextureManager*>( cg::Registry::instance()->get("TextureManager"));
		GLuint txCrate = tm->get("crate")->getTextureDL();

		glPushMatrix();
			glEnable(GL_TEXTURE_2D);
			glTranslated(_position[0], _position[1], _position[2] + _boxSize / 2);
			glScaled(_boxSize, _boxSize, _boxSize);
			unitCube(txCrate);
			glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}

	void ObjectStaticBox::registerToCollisionManager() {

		createBoundingSpheres();

		CollisionManager *collisionManager = (CollisionManager*)cg::Registry::instance()->get("CollisionManager");
		collisionManager->registerStaticObject(dynamic_cast<Collidable*>(cg::Registry::instance()->get(getId())));
	}

	void ObjectStaticBox::createBoundingSpheres() {

		float radius = (float)(sqrt(_boxSize * _boxSize / 2));
		cg::Vector3d position(_position[0], _position[1], _position[2] + _boxSize / 2);

		BoundingSphere *b = new BoundingSphere(radius, position);
		addBoundingSphere(b);
	}

	void ObjectStaticBox::updateBoundingSpheres() {}

	cg::Vector3d ObjectStaticBox::getPosition() {
		return _position;
	}

	cg::Vector3d ObjectStaticBox::getFront() { return cg::Vector3d(1,0,0); }
	void ObjectStaticBox::setHeight(int height) {}
}