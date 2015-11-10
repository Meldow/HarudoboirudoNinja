#ifndef SCENE_H
#define SCENE_H

#include <string>
#include "cg/cg.h"
#include "Debug.h"
#include "LevelManager.h"

namespace proj {

	class Scene : public cg::Entity,
		public cg::IDrawListener,
		public cg::IReshapeEventListener, 
		public cg::IUpdateListener, 
		public Debug
	{
	private:
		//LevelManager* _lvlm;
		int _winHeight;
		int _winWidth;
		bool _won;
		bool _lost;
		bool _notEnoughMags;
		long _debugMessageTimer;
		std::list<std::string>* _debugOptions;

		void initLighting();
		void initFog();
		void printString(std::string s);
	public:
		Scene();
		~Scene();
		void init();
		void draw();
		void drawOverlay();
		bool getWon();
		bool getLost();
		
		void update(unsigned long elapsed_millis);
		void onReshape(int width, int height);
		void onLose();
		void onWin();
		void reset();
		void setNotEnoughMags(bool value);
		void switchDebug();
	};
}

#endif