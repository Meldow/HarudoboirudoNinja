#ifndef MAIN_APP_H
#define MAIN_APP_H

#include "cg/cg.h"
#include "MainCamera.h"
#include "Camera.h"
#include "FreeCamera.h"
#include "Controller.h"
#include "Ninja.h"
#include "Enemy.h"
#include "Scene.h"
#include "ImageLoaderHeightMap.h"
#include "ImageLoaderItemMap.h"
#include "MaterialManager.h"
#include "TextureManager.h"
#include "ObjectStaticBox.h"
#include "CollisionManager.h"
#include "DebugManager.h"
#include "Level1.h"
#include "Level2.h"
#include "Skybox.h"
#include "ObjectSexyMagazine.h"
#include "MainMenu.h"
#include "MenuManager.h"


namespace proj {

	class MainApp : public cg::Application {
	private: 
		bool _paused;
	public:
		MainApp();
		~MainApp();
		void createEntities();
		void createViews();
		void pause();
		void unpause();
		void onUpdate();
		
	};
}

#endif