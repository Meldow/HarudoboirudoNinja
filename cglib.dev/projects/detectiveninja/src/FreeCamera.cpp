#include "FreeCamera.h"

namespace proj {

	FreeCamera::FreeCamera() : CameraMode("FreeCamera") {}
    FreeCamera::~FreeCamera() {
	}
    void FreeCamera::init() {
		CameraMode::init();
		CAM_SPEED = 25;
		reset();
	}
    void FreeCamera::draw() {
		
	    glMatrixMode(GL_PROJECTION);

        glMatrixMode(GL_PROJECTION);

        glLoadIdentity();
		gluPerspective(	60.0, _winSize[0]/_winSize[1], 1.0, 10000.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

		
		_lookAt = _position + _front;
		gluLookAt(	_position[0],_position[1],_position[2],
					_lookAt[0] , _lookAt[1] , _lookAt[2] ,
					_up[0],_up[1],_up[2]);
		
    }
	
	void FreeCamera::onReshape(int width, int height) {
		CameraMode::onReshape(width, height);
	}
	
	void FreeCamera::onMouseMotion(int x, int y) {
		CameraMode::onMouseMotion(x,y);
	}

	void FreeCamera::onMousePassiveMotion(int x, int y) {
		CameraMode::onMousePassiveMotion(x,y);
	}

	void FreeCamera::onMouse(int button, int state, int x, int y) {
		_isRoll = (button == GLUT_RIGHT_BUTTON);
		_lastMousePosition.set(x,y);
	}
	
	void FreeCamera::update(unsigned long elapsed_millis) {
		double elapsed_seconds = elapsed_millis / (double)1000; //tempo (time = Time.deltaTime), numero de segundos q passou do ultimo frame
		
		if(cg::KeyBuffer::instance()->isSpecialKeyDown(GLUT_KEY_DOWN)) {
			_position -= CAM_SPEED * _front * elapsed_seconds;
		}
		if(cg::KeyBuffer::instance()->isSpecialKeyDown(GLUT_KEY_UP)) {
			_position += CAM_SPEED * _front * elapsed_seconds;
		}
		if(cg::KeyBuffer::instance()->isSpecialKeyDown(GLUT_KEY_RIGHT)) {
			_position += CAM_SPEED * _right * elapsed_seconds;
		}
		if(cg::KeyBuffer::instance()->isSpecialKeyDown(GLUT_KEY_LEFT)) {
			_position -= CAM_SPEED * _right * elapsed_seconds;
		}
		limitPosition();
	}

	void FreeCamera::reset() {
		_position.set(0, 0, 200);
		_front.set(1,1,-1);
		_right.set(1,-1,0);
	}
	
	std::string FreeCamera::getType() {
		return "FreeCamera";
	}

}
