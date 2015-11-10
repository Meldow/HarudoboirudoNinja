#include "Menu.h"

namespace proj {
	
	Menu::Menu(const std::string id) :	Entity(id) {
		_title = id;
		_commands = new std::vector<Command*>();
		_winHeight = cg::Manager::instance()->getApp()->getWindowInfo().height;
		_winWidth = cg::Manager::instance()->getApp()->getWindowInfo().width;
		_active = false;
	}
	Menu::~Menu(){
	}

	void Menu::init() {
		
	}

	std::string Menu::getTitle() {
		return _title;
	}

	void Menu::addCommand(Command* command) {
		_commands->push_back(command);
	}

	void Menu::drawOverlay() {
		
		glDisable(GL_LIGHTING);
		if(_commands->size() == 0 || !_active)
			return;
		
		//printf("DRAWING MENU: %s\n", getTitle().c_str());
		//glDisable(GL_DEPTH_TEST);
		//glClear(GL_COLOR_BUFFER_BIT);
		glPushMatrix();

		int ch = (int)_commands->at(0)->getYsize();
		int cw = (int)_commands->at(0)->getXsize();
		
		glColor3f(1.0,0.5,0.0);
		glRasterPos2d( _winWidth / 2 - cw/ 2, _winHeight * 3 / 4 + ch / 2 );
		for (std::string::iterator i = _title.begin(); i != _title.end() ; i++) {
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *i);
		}
		
		for( int i = 0; i < (int)_commands->size(); i++) {
			//glTranslatef(_winWidth / 2, _winHeight / 2 - i*ch, 0); 
			glColor3f(0.0,0.0,1.0);
			
			glBegin(GL_QUADS);
				glVertex2i(_winWidth / 2 - cw / 2, _winHeight * 3 / 4 + ch / 2 - i * ch);
				glVertex2i(_winWidth / 2 + cw / 2, _winHeight * 3 / 4 + ch / 2 - i * ch);
				glVertex2i(_winWidth / 2 + cw / 2, _winHeight * 3 / 4 - ch / 2 - i * ch);
				glVertex2i(_winWidth / 2 - cw / 2, _winHeight * 3 / 4 - ch / 2 - i * ch);
			glEnd();
				
				glColor3f(1.0,0.5,0.0);
				glRasterPos2d( _winWidth / 2 - cw / 2, _winHeight * 3 / 4 - i*ch );
				std::stringstream ss;
				ss << i << ": " <<  _commands->at(i)->getTitle();
				std::string menuCommand = ss.str();
				for (std::string::iterator i = menuCommand.begin(); i != menuCommand.end() ; i++) {
					glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *i);
				}
			
		}
		
		glPopMatrix();
		glEnable(GL_LIGHTING);
	}

	void Menu::onReshape(int width, int height) {
		_winWidth = width;
		_winHeight = height;
	}

	void Menu::onKeyReleased(char key) {
		if(!_active)
			return;
		if(key > '9' || key < '0')
			return;
		
		int command = atoi(&key);
		if(command >= (int)_commands->size())
			return;
		
		
		_commands->at(command)->execute();
		deactivate();
	}

	void Menu::activate() {
		_active = true;
	}

	void Menu::deactivate() {
		_active = false;
	}

	bool Menu::isActive() {
		return _active;
	}
}