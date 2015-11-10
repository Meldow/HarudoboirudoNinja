#include "Skybox.h"

namespace proj {

	Skybox::Skybox() : cg::Entity("Skybox") {}
	Skybox::~Skybox() {}

	void Skybox::init() {
	
		_width	= 600.0f;
		_height	= 350.0f;
		_length	= 600.0f;
	}

	void Skybox::draw() {

		TextureManager* textureManager = dynamic_cast<TextureManager*>(cg::Registry::instance()->get("TextureManager"));
		
		glPushMatrix();

		glDisable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);	
		
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		/**
		 * BACK
		 */
		GLuint tex = textureManager->get("tex_skybox_back")->getTextureDL();
		glBindTexture(GL_TEXTURE_2D, tex);

		glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f,   0.0f, _height);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f,   0.0f, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(_width, 0.0f, 0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(_width, 0.0f, _height);
		glEnd();

		/**
		 * LEFT
		 */
		tex = textureManager->get("tex_skybox_left")->getTextureDL();
		glBindTexture(GL_TEXTURE_2D, tex);

		glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, _length, _height);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, _length, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f,	0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f,    _height);
		glEnd();

		/**
		 * FRONT
		 */
		tex = textureManager->get("tex_skybox_front")->getTextureDL();
		glBindTexture(GL_TEXTURE_2D, tex);

		glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(_width, _length, _height);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(_width, _length, 0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f,	 _length, 0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f,   _length, _height);
		glEnd();

		/**
		 * RIGHT
		 */
		tex = textureManager->get("tex_skybox_right")->getTextureDL();
		glBindTexture(GL_TEXTURE_2D, tex);

		glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(_width, 0.0f, _height);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(_width, 0.0f,    0.0f);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(_width, _length, 0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(_width, _length, _height);
		glEnd();

		/**
		 * TOP
		 */
		tex = textureManager->get("tex_skybox_top")->getTextureDL();
		glBindTexture(GL_TEXTURE_2D, tex);

		glBegin(GL_QUADS);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(_width, 0.0f,    _height);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(_width, _length, _height);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f,   _length, _height);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f,   0.0f,    _height);
		glEnd();

		glDisable(GL_TEXTURE_2D);
		glEnable(GL_LIGHTING);
		glPopMatrix();
	}
}