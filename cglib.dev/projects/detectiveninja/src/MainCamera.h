#ifndef MAIN_CAMERA_H
#define MAIN_CAMERA_H

#include <string>
#include "cg/cg.h"
#include "CameraMode.h"
#include "WorldObject.h"

#define MAX_CAM_HEIGHT 1

namespace proj {

    class MainCamera : public CameraMode
	{
    private:
		
		WorldObject* _target;
		float _scale;

    public:
		MainCamera();
        virtual ~MainCamera();
        void init();							//init values of the camera
        void draw();							//draw the camera
        void onReshape(int width, int height);	//reshapes if needed
		void onMouse(int button, int state, int x, int y);
        void onMouseMotion(int x, int y);
        void onMousePassiveMotion(int x, int y);
		std::string getType();
		void reset();

	};
}

#endif
