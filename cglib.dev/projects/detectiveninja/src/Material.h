#ifndef MATERIAL_H
#define MATERIAL_H

#include <string.h>
#include "cg/cg.h"

namespace proj {

	class Material 
	{
	public:
		std::string id;
		GLfloat mat_ambient[4];
		GLfloat mat_emission[4];
		GLfloat mat_diffuse[4];
		GLfloat mat_specular[4];
		GLfloat mat_shininess[1];
		int _materialDL;

		

	public:
		Material();
		~Material();
		
		void init();
        void apply();
		void makeMaterial();

		std::string getName();
	
		void setName(std::string name);
		void setMatAmbient(GLfloat maR, GLfloat maG, GLfloat maB, GLfloat maA);
		void setMatEmission(GLfloat meR, GLfloat meG, GLfloat meB, GLfloat meA);
		void setMatDiffuse(GLfloat mdR, GLfloat mdG, GLfloat mdB, GLfloat mdA);
		void setMatSpecular(GLfloat msR, GLfloat msG, GLfloat msB, GLfloat msA);
		void setMatShininess(GLfloat msh);
		
	};
}

#endif