/*
 * Tank.cpp
 *
 *  Created on: 24 de jun de 2017
 *      Author: ferna
 */

#include "Tank.h"
#include <GL/glut.h>
using namespace std;



Tank::Tank() {
	// TODO Auto-generated constructor stub

}

void Tank::Draw() {
		const float BOX_SIZE = 7.0f; //The length of each side of the cube
		glBegin(GL_QUADS);

		glColor3f(1.0f, 1.0f, 1.0f);

		//LONA TOP
		glTexCoord2f(0.0f  + lonaL, 0.0f);
		glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE / 2);

		glTexCoord2f(1.7f + lonaL, 0.0f);
		glVertex3f(BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE / 2);

		glTexCoord2f(1.7f+ lonaL, 1.0f);
		glVertex3f(BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE/1.5);

		glTexCoord2f(0.0f+ lonaL, 1.0f);
		glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE/1.5);

		//LONA BOTTOM
		glTexCoord2f(1.0f  + lonaL, 0.0f);
		glVertex3f(-BOX_SIZE / 4, 0, -BOX_SIZE / 2);

		glTexCoord2f(0.0f + lonaL, 0.0f);
		glVertex3f(BOX_SIZE / 4, 0, -BOX_SIZE / 2);

		glTexCoord2f(0.0f+ lonaL, 1.0f);
		glVertex3f(BOX_SIZE / 4, 0, -BOX_SIZE/1.5);

		glTexCoord2f(1.0f+ lonaL, 1.0f);
		glVertex3f(-BOX_SIZE / 4, 0, -BOX_SIZE/1.5);

		// LONA FRENTE
		glTexCoord2f(1.0f+ lonaL, 0.0f);//+ _angle
		glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE/1.5);

		glTexCoord2f(1.0f+ lonaL, 1.0f);
		glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE / 2);

		glTexCoord2f(0.0f+ lonaL, 1.0f);
		glVertex3f(-BOX_SIZE / 4, 0, -BOX_SIZE / 2);

		glTexCoord2f(0.0f+ lonaL, 0.0f);
		glVertex3f(-BOX_SIZE / 4, 0, -BOX_SIZE/1.5);

		// LONA TRAS
		glTexCoord2f(0.0f+ lonaL, 0.0f);//+ _angle
		glVertex3f(BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE/1.5);

		glTexCoord2f(0.0f+ lonaL, 1.0f);
		glVertex3f(BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE / 2);

		glTexCoord2f(1.0f+ lonaL, 1.0f);
		glVertex3f(BOX_SIZE / 4, 0, -BOX_SIZE / 2);

		glTexCoord2f(1.0f+ lonaL, 0.0f);
		glVertex3f(BOX_SIZE / 4, 0, -BOX_SIZE/1.5);


		glEnd();
}

void Tank::setMotion(int dir) {
	lonaL +=0.1;
}
