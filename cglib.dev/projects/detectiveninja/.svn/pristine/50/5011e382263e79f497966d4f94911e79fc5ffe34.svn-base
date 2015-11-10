#include "WorldObject.h"

namespace proj {

	WorldObject::WorldObject(std::string id, cg::Vector3d position) : cg::Entity(id) {
		_position = position;
	}
	WorldObject::~WorldObject() {}

	void WorldObject::unitCube(GLuint txAll) {
		unitCube(txAll, txAll, txAll, txAll, txAll, txAll);
	}

	void WorldObject::unitCube(GLuint txFront, GLuint txBack, GLuint txTop, GLuint txBottom, GLuint txRight, GLuint txLeft) {

		glScalef(0.5f,0.5f,0.5f);
		cube(5, -1,-1,1,1, 0,1,0, 0,0,1,1, txFront, txBack, txTop, txBottom, txRight, txLeft);
	}

	void WorldObject::cube(int n, 
		double x0, double y0, double x1, double y1,
		double nx, double ny, double nz,
		double tx0, double ty0, double tx1, double ty1,
		GLuint txFront, GLuint txBack, GLuint txTop, GLuint txBottom, GLuint txRight, GLuint txLeft) {

		// front
		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, txFront);
			glTranslatef(0,1,0);
			dividedPlane(n, x0,y0,x1,y1, nx,ny,nz, tx0,ty0,tx1,ty1);
		glPopMatrix();

		// back
		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, txBack);
			glTranslatef(0,-1,0);
			glRotatef(180, 1,0,0);
			dividedPlane(n, x0,y0,x1,y1, nx,ny,nz, tx0,ty0,tx1,ty1);
		glPopMatrix();

		// top
		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, txTop);
			glTranslatef(0,0,1);
			glRotatef(90,1,0,0);
			dividedPlane(n, x0,y0,x1,y1, nx,ny,nz, tx0,ty0,tx1,ty1);
		glPopMatrix();

		// bottom
		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, txBottom);
			glTranslatef(0,0,-1);
			glRotatef(-90,1,0,0);
			dividedPlane(n, x0,y0,x1,y1, nx,ny,nz, tx0,ty0,tx1,ty1);
		glPopMatrix();

		// right
		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, txRight);
			glTranslatef(1,0,0);
			glRotatef(-90,0,0,1);
			dividedPlane(n, x0,y0,x1,y1, nx,ny,nz, tx0,ty0,tx1,ty1);
		glPopMatrix();

		// left
		glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, txLeft);
			glTranslatef(-1,0,0);
			glRotatef(90,0,0,1);
			dividedPlane(n, x0,y0,x1,y1, nx,ny,nz, tx0,ty0,tx1,ty1);
		glPopMatrix();
	}

	void WorldObject::dividedPlane(int n, 
		double x0, double y0, double x1, double y1,
		double nx, double ny, double nz,
		double tx0, double ty0, double tx1, double ty1) 
	{
		int countx = 0;
		int county = 0;
		double x = x0;
		double y = y0;
		double stepx = (x1 - x0) / (double) n;
		double stepy = (y1 - y0) / (double) n;
		double tx = tx0;
		double ty = ty0;
		double steptx = (tx1 - tx0) / (double) n;
		double stepty = (ty1 - ty0) / (double) n;

		glBegin(GL_QUADS);
		glNormal3d(nx, ny, nz);

		while (countx != n) {

			while (county != n) {

				glTexCoord2d(tx, ty);
				glVertex3d(x, 0, y);
				glTexCoord2d(tx + steptx, ty);
				glVertex3d(x + stepx, 0, y);
				glTexCoord2d(tx + steptx, ty + stepty);
				glVertex3d(x + stepx, 0, y + stepy);
				glTexCoord2d(tx, ty + stepty);
				glVertex3d(x, 0, y + stepy);
				county++;
				y += stepy;
				ty += stepty;
			}

			countx++;
			x += stepx;
			tx += steptx;
			county = 0;
			y = y0;
			ty = ty0;
		}

		glEnd();
	}

	void WorldObject::toggleDebug() {
		switchDebug();
	}
}