#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include "cg/cg.h"
#include "CameraMode.h"
#include "FreeCamera.h"
#include "MainCamera.h"

namespace proj {
    class Camera : public cg::Entity, 
		public cg::IDrawListener,
		public cg::IReshapeEventListener,
		public cg::IMouseEventListener,
		public cg::IUpdateListener

	{
    private:
		CameraMode* _mode;
    public:
        Camera();
        virtual ~Camera();
        void init();
        void draw();
        void onReshape(int width, int height);
        void onMouse(int button, int state, int x, int y);
        void onMouseMotion(int x, int y);
        void onMousePassiveMotion(int x, int y);
		void update(unsigned long elapsed_millis);
		void freeCamera();
		void mainCamera();
		void firstPersonCamera();
		void toggleCamera();

		std::string getType();
	};
}

#endif
