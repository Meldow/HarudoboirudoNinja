#include "Level1.h"

namespace proj {
	Level1::Level1() : Level(1, "Level1", "level_0_map.raw", "level_0_item.raw") {
		init();
	}
	Level1::~Level1() {}

	void Level1::init() {
		//adding Obsidian material
		Material* obsidian = new Material();
		obsidian->setName("obsidian");
		obsidian->setMatAmbient(0.05375f, 0.05f, 0.06625f, 1.0f);
		obsidian->setMatDiffuse(0.18275f, 0.17f, 0.22525f, 1.0f);
		obsidian->setMatSpecular(0.332741f, 0.328634f, 0.346435f, 1.0f);
		obsidian->setMatShininess(38.4f);
		obsidian->makeMaterial();
		_levelMats->push_back(obsidian);
		
		//adding Emerald material
		Material* emerald = new Material();
		emerald->setName("emerald");
		emerald->setMatAmbient(0.0215f,  0.1745f,   0.0215f,  1.0f);
		emerald->setMatDiffuse( 0.07568f, 0.61424f,  0.07568f, 1.0f);
		emerald->setMatSpecular( 0.633f,   0.727811f, 0.633f,   1.0f);
		emerald->setMatShininess(76.8f);
		emerald->makeMaterial();
		_levelMats->push_back(emerald);

		//adding textures
		
		/* Dynamic Objects */

		Texture* t = new Texture("tex_dark_ninja_face", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		t = new Texture("tex_dark_ninja_body", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		t = new Texture("tex_enemy_face", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		t = new Texture("tex_enemy_perv_face", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		/*
		t = new Texture("tex_light_ninja_face", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		t = new Texture("tex_light_ninja_body", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		t = new Texture("tex_red_ninja_face", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		t = new Texture("tex_red_ninja_body", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		t = new Texture("tex_blue_ninja_face", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		t = new Texture("tex_blue_ninja_body", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);
		*/

		/* Static Objects */

		t = new Texture("clue", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		t = new Texture("tex_icha_icha_tactics_cover", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		t = new Texture("tex_icha_icha_tactics_spine", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		t = new Texture("tex_icha_icha_tactics", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		t = new Texture("crate", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		/* Map */

		_maptex = "tex_height_map_level_1";
		t = new Texture(_maptex, "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		/* Skybox */

		t = new Texture("tex_skybox_back", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		t = new Texture("tex_skybox_front", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		t = new Texture("tex_skybox_left", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		t = new Texture("tex_skybox_right", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);

		t = new Texture("tex_skybox_top", "tga");
		t->makeTexture();
		_levelTexs->push_back(t);
	}

}