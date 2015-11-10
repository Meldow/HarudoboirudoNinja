#include "WaypointEnemy.h"

namespace proj {

	WaypointEnemy::WaypointEnemy(std::string id, cg::Vector3d position) : cg::Entity(id) {
		_position = position;
	}
	WaypointEnemy::~WaypointEnemy() {}

	void WaypointEnemy::init() {

		// REGISTER TO DEBUG MANAGER
		dynamic_cast<DebugManager*>(cg::Registry::instance()->get("DebugManager"))->registerEnemy(dynamic_cast<Debug*>(this));
	}

	void WaypointEnemy::draw() {

		if (isDebug()) {

			glDisable(GL_LIGHTING);

			glPushMatrix();
				glTranslated(_position[0],_position[1],_position[2]);
				glColor3f(1.0f,0.0f,0.0f);
				glutWireSphere(5.0f,10,10);
			glPopMatrix();

			glEnable(GL_LIGHTING);
		}
	}

	cg::Vector3d WaypointEnemy::getPosition() {
		return _position;
	}	
}