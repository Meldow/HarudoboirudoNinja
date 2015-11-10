#ifndef FREE_CAMERA_H
#define FREE_CAMERA_H

#include <string>
#include "cg/cg.h"
#include "CameraMode.h"

namespace proj {

    class FreeCamera : public CameraMode
	{
    private:
		
		cg::Vector3d _lookAt;
		bool _isRoll;
		double CAM_SPEED;


    public:
        FreeCamera();
        virtual ~FreeCamera();
        void init();
        void draw();
        void onReshape(int width, int height);
        void onMouse(int button, int state, int x, int y);
        void onMouseMotion(int x, int y);
        void onMousePassiveMotion(int x, int y);
		void update(unsigned long elapsed_millis);
		std::string getType();
		void reset();
	};
}

#endif
