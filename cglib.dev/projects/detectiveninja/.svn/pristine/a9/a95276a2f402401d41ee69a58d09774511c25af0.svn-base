#ifndef COMMAND_H
#define COMMAND_H

#include "cg/cg.h"

namespace proj {

    class Command :  
		public cg::IReshapeEventListener
	{
	protected:
		std::string _title;
		GLfloat _Xsize;
		GLfloat _Ysize;
    public:
        Command(const std::string id);
        ~Command();
        void drawOverlay();
        
		void onReshape(int width, int height);
		virtual void execute();

		std::string getTitle();
		GLfloat getXsize();
		GLfloat getYsize();
	};
}

#endif
