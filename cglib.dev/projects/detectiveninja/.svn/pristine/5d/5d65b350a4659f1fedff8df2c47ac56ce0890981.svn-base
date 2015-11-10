#ifndef TEXTURE_H
#define TEXTURE_H


#include <string.h>
#include "cg/cg.h"
#include "FreeImage.h"

#define TEXTURE_LOCATION "../../data/"

namespace proj {

	class Texture 
	{
	private:
		GLuint _textureDL;
		std::string _filename;
		std::string _fileextension;
		GLuint loadTexture(std::string fn);
	public:
		Texture(std::string fname, std::string fext);
		~Texture();
		void init();
		void makeTexture();

		std::string getName();
		std::string getExtension();
		GLuint getTextureDL();
	};
}

#endif