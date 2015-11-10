#include "Scene.h"



namespace proj {

	Scene::Scene() : cg::Entity("Scene") {}
	Scene::~Scene() {}

	void Scene::init() {

		glCullFace(GL_FRONT);
		glEnable(GL_CULL_FACE);

		initLighting();
		initFog();

		_winHeight = cg::Manager::instance()->getApp()->getWindowInfo().height;
		_winWidth = cg::Manager::instance()->getApp()->getWindowInfo().width;

		_debugOptions = new std::list<std::string>();
		_debugOptions->push_back("1: Toggle camera");
		_debugOptions->push_back("2: Toggle map debug");
		_debugOptions->push_back("3: Toggle player debug");
		_debugOptions->push_back("4: Toggle enemy debug");
		_debugOptions->push_back("5: Toggle static objects debug");
		_debugOptions->push_back("F2: Exit debug mode");
		
		reset();
	}

	void Scene::initLighting() {

		GLfloat modelAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, modelAmbient);
		glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
		glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	}

	void Scene::initFog() {

		GLfloat fogColor[] = { 0.5f, 0.5f, 0.5f, 1.0f };
		glFogi(GL_FOG_MODE, GL_EXP);  // BEST: GL_LINEAR
		glFogfv(GL_FOG_COLOR, fogColor);
		glFogf(GL_FOG_DENSITY, 0.003f);
		glFogf(GL_FOG_START, 1.0f);
		glFogf(GL_FOG_END, 5.0f);
	}

	bool Scene::getWon() {
		return _won;
	}

	bool Scene::getLost() {
		return _lost;
	}

	void Scene::draw() {
		glEnable(GL_LIGHTING);
		glEnable(GL_FOG);
	}

	void Scene::printString(std::string s) {
		std::string::iterator iend = s.end();
		for (std::string::iterator i = s.begin(); i != iend; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *i);
		} 
	}
	void Scene::drawOverlay() {

		glDisable(GL_LIGHTING);
		glDisable(GL_FOG);

		glColor3d(0.9,0.1,0.1);

		LevelManager* _lvlm = dynamic_cast<LevelManager*>(cg::Registry::instance()->get("LevelManager"));
		std::ostringstream clueMessage;
		//clueMessage.clear();
		clueMessage << "Clues collected: " << _lvlm->getCurrentClues() << " out of " << _lvlm->getTotalClues();

		
		cg::Util::instance()->drawBitmapString(clueMessage.str(),10,10);

		if(_won) {

			glRasterPos2d( _winWidth/2,  _winHeight/2 );
			printString("YOU WON!");
		}

		if(_lost) {

			glRasterPos2d( _winWidth/2,  _winHeight/2  );
			printString("YOU LOST!");
		}

		if(_notEnoughMags) {

			glRasterPos2d( _winWidth/2,  _winHeight/2 );
			printString("NOT ENOUGH ANCIENT SECRET NINJA ART!");
		}
		
		if(_debugMessageTimer > 0) {
			glRasterPos2d( _winWidth * 3 / 4,  _winHeight * 3 / 4 );
			std::string s;
			if(_debugMode)
				s = "ENTERING DEBUG MODE";
			else
				s = "EXITING DEBUG MODE";
			printString(s);
		}

		if(_debugMode) {
			std::list<std::string>::iterator doptionsit;
			int i = 0;
			for(doptionsit = _debugOptions->begin(); doptionsit != _debugOptions->end(); doptionsit++) { 
				glRasterPos2d( _winWidth* 3 / 4,  _winHeight/2 - i);
				printString(*doptionsit);
				i += 20;
			}
		}
		
		glEnable(GL_LIGHTING);
		glEnable(GL_FOG);
	}

	void Scene::update(unsigned long elapsed_millis) {
		if(_debugMessageTimer > 0)
			_debugMessageTimer -= elapsed_millis;
		else
			_debugMessageTimer = 0;
	}

	void Scene::onReshape(int width, int height) {
		_winWidth = width;
		_winHeight = height;
	}

	void Scene::onLose() {
		if(!_won)
			_lost = true;
	}

	void Scene::onWin() {
		if(!_lost)
			_won = true;
	}

	void Scene::setNotEnoughMags(bool value) {
		_notEnoughMags = value;
	}

	void Scene::reset() {
		_won = _lost = _notEnoughMags = _debugMode = false;
		_debugMessageTimer = 0;
	}

	void Scene::switchDebug() {
		_debugMessageTimer = 1000;
		Debug::switchDebug();
	}
}