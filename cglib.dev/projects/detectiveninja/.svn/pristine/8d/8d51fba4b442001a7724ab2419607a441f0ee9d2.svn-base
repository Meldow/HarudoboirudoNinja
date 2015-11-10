#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include <sstream>
#include <ctype.h>
#include "cg/cg.h"
#include "Command.h"

namespace proj {

    class Menu : public cg::Entity, 
		public cg::IDrawListener,
		public cg::IReshapeEventListener
	{
    protected:
		std::vector<Command*>* _commands;
		std::string _title;
		unsigned int _winHeight;
		unsigned int _winWidth;
		unsigned int _selectedCommand;
		bool _active;
    public:
        Menu(const std::string id);
        ~Menu();
        virtual void init();
        void drawOverlay();
        void onReshape(int width, int height);
		void onKeyReleased(char key);
		void addCommand(Command* command);
		void activate();
		void deactivate();
		bool isActive();
		std::string getTitle();
	};
}

#endif
