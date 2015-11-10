#include "Light.h"

namespace proj {

	Light::Light(std::string id, GLenum lightID, float position[], float direction[]) : cg::Entity(id) {
	
		_lightID = lightID;
		_position = cg::Vector3f(position[0], position[1], position[2]);

		makeLight(position, direction);
	}

	Light::~Light() {}

	inline
	void Light::makeLight(float position[], float direction[]) {

		_lightDL = glGenLists(1);
		assert(_lightDL != 0);

		glNewList(_lightDL,GL_COMPILE);
			glLightfv(_lightID, GL_POSITION, position);
			glLightfv(_lightID, GL_SPOT_DIRECTION, direction);
		glEndList();
	}

	void Light::init() {

		GLfloat ambient[] =	{ 0.1f, 0.1f, 0.1f, 1.0f };
		GLfloat diffuse[] =	{ 0.9f, 0.9f, 0.9f, 1.0f };
		GLfloat specular[] = { 0.9f, 0.9f, 0.9f, 1.0f };

		glLightfv(_lightID, GL_AMBIENT, ambient);
		glLightfv(_lightID, GL_DIFFUSE, diffuse);
		glLightfv(_lightID, GL_SPECULAR, specular);
		glLightf(_lightID, GL_SPOT_CUTOFF, 90.0f);

		glEnable(_lightID);

		// REGISTER TO DEBUG MANAGER
		dynamic_cast<DebugManager*>(cg::Registry::instance()->get("DebugManager"))->registerStaticObject(dynamic_cast<Debug*>(this));
	}

	void Light::draw() {
	
		glPushMatrix();
			glCallList(_lightDL);
		glPopMatrix();

		if (isDebug()) {

			glDisable(GL_LIGHTING);

			glPushMatrix();
				glTranslated(_position[0],_position[1],_position[2]);
				glColor3f(0.9f,0.9f,0.9f);
				glutWireCone(2.0f,2.0f,10,10);
			glPopMatrix();

			glEnable(GL_LIGHTING);
		}
	}

	void Light::setAmbientLight(float params[]) {
		glLightfv(_lightID, GL_AMBIENT, params);
	}
	void Light::setDiffuseLight(float params[]) {
		glLightfv(_lightID, GL_DIFFUSE, params);
	}
	void Light::setSpecularLight(float params[]) {
		glLightfv(_lightID, GL_SPECULAR, params);
	}
	void Light::setSpotCuttoff(float angle) {
		glLightf(_lightID, GL_SPOT_CUTOFF, angle);
	}
}