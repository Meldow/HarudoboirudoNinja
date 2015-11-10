#include "MainApp.h"

namespace proj {

	MainApp::MainApp() {

		_windowInfo.caption = "Hardboiled Ninja";
		_windowInfo.width = 1024;
		_windowInfo.height = 768;
		_windowInfo.x = 0;
		_windowInfo.y = 0;
		_paused = true;
	}

	MainApp::~MainApp() {}
	
	void MainApp::createEntities() {
		
		float light0position[] = { 20.0, 20.0, 10.0, 1.0 };
		float light0direction[] = { 0.0, 0.0, -1.0 };

		addEntity(new MaterialManager());
		addEntity(new TextureManager());
		addEntity(new MenuManager());
		addEntity(new DebugManager());
		
		LevelManager* lm = new LevelManager(); 
		addEntity(lm);
	
		addEntity(new Scene());
		addEntity(new Camera());
		addEntity(new MainCamera());
		addEntity(new FreeCamera());
		addEntity(new Skybox());
		addEntity(new Ninja("Ninja", cg::Vector3d(60,60,3)));
		addEntity(new Controller());
		addEntity(new CollisionManager());

		lm->loadLevel(new Level1());
	}


	void MainApp::createViews() {
		
		cg::View* v = createView("view1");
		v->setViewport(0.0f,0.0f,1.0f,1.0f);
		v->linkEntityAtEnd("Scene");
		v->linkEntityAtEnd("Camera");
		v->linkEntityAtEnd("mappedterrain");
		v->linkEntityAtEnd("Skybox");
		v->linkEntityAtEnd("Ninja");
		v->linkEntityAtEnd("CollisionManager");
	}

	void MainApp::pause() {
		_paused = true;

		// Just tell ninja to STOP RUNNING
		dynamic_cast<Ninja*>(cg::Registry::instance()->get("Ninja"))->stop();
	}

	void MainApp::unpause() {
		_paused = false;
	}

	void MainApp::onUpdate() {
		if(!_paused) {
			Application::onUpdate();
		}
		else {
			updateFrameTime();
			static_cast<MenuManager*>(cg::Registry::instance()->get("MenuManager"))->update(_timeInfo.elapsed);
		}
	}
}