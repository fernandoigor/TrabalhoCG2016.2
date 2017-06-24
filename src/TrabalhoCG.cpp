//============================================================================
// Name        : TrabalhoCG.cpp
// Author      : fer
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

#include "imageloader.h"

using namespace std;

const float BOX_SIZE = 7.0f; //The length of each side of the cube
float _angle = 0;            //The rotation of the box
int sentido = 1;
GLuint _textureId[2];           //The OpenGL id of the texture





//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D,
				 0,
				 GL_RGB,
				 image->width, image->height,
				 0,
				 GL_RGB,
				 GL_UNSIGNED_BYTE,
				 image->pixels);
	return textureId;
}

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	Image* image;
	/*Image* image = loadBMP("vtr.bmp");
	_textureId[0] = loadTexture(image);*/
	image = loadBMP("esteira.bmp");
	_textureId[1] = loadTexture(image);
	delete image;
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 10.0, 20.0,		/* eye */
	   	      0.0, 0.0, 0.0,		/* look */
	    	  0.0, 1.0, 0.0);		/* up */



	GLfloat ambientLight[] = {0.7f, 0.7f, 0.7f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

	GLfloat lightColor[] = {0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat lightPos[] = {-2 * BOX_SIZE, BOX_SIZE, 4 * BOX_SIZE, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	//glRotatef(_angle*80, 0.0f, 1.0f, 0.0f);
	glTranslatef(-_angle*4, 0.0f, 0.0f);

	if(sentido > 0)
		glRotatef(-10, 0.0f, 0.0f, 1.0f);
	else
		glRotatef(10, 0.0f, 0.0f, 1.0f);


	glDisable(GL_TEXTURE_2D);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);

	glColor3f(1.0f, 1.0f, 1.0f);

	//LONA TOP
	glTexCoord2f(0.0f  + _angle, 0.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE / 2);

	glTexCoord2f(1.7f + _angle, 0.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE / 2);

	glTexCoord2f(1.7f+ _angle, 1.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE/1.5);

	glTexCoord2f(0.0f+ _angle, 1.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE/1.5);

	//LONA BOTTOM
	glTexCoord2f(1.0f  + _angle, 0.0f);
	glVertex3f(-BOX_SIZE / 4, 0, -BOX_SIZE / 2);

	glTexCoord2f(0.0f + _angle, 0.0f);
	glVertex3f(BOX_SIZE / 4, 0, -BOX_SIZE / 2);

	glTexCoord2f(0.0f+ _angle, 1.0f);
	glVertex3f(BOX_SIZE / 4, 0, -BOX_SIZE/1.5);

	glTexCoord2f(1.0f+ _angle, 1.0f);
	glVertex3f(-BOX_SIZE / 4, 0, -BOX_SIZE/1.5);

	// LONA FRENTE
	glTexCoord2f(1.0f+ _angle, 0.0f);//+ _angle
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE/1.5);

	glTexCoord2f(1.0f+ _angle, 1.0f);
	glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE / 2);

	glTexCoord2f(0.0f+ _angle, 1.0f);
	glVertex3f(-BOX_SIZE / 4, 0, -BOX_SIZE / 2);

	glTexCoord2f(0.0f+ _angle, 0.0f);
	glVertex3f(-BOX_SIZE / 4, 0, -BOX_SIZE/1.5);

	// LONA TRAS
	glTexCoord2f(0.0f+ _angle, 0.0f);//+ _angle
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE/1.5);

	glTexCoord2f(0.0f+ _angle, 1.0f);
	glVertex3f(BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE / 2);

	glTexCoord2f(1.0f+ _angle, 1.0f);
	glVertex3f(BOX_SIZE / 4, 0, -BOX_SIZE / 2);

	glTexCoord2f(1.0f+ _angle, 0.0f);
	glVertex3f(BOX_SIZE / 4, 0, -BOX_SIZE/1.5);


	glEnd();
	glDisable(GL_TEXTURE_2D);
	glColor3f(0.2,0.2,0.0);
	glPushMatrix();
	glTranslatef(-2.5,1.3,-3.7);
	glRotatef(_angle*1000,0.0,0.0,1.0);
	glutSolidCube(0.5);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.5,1.3,-3.7);
		glRotatef(_angle*1000,0.0,0.0,1.0);
		glutSolidCube(0.5);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-1.2,1.0,-3.9);
		glRotatef(_angle*1000,0.0,0.0,1.0);
		glutSolidCube(1);
		glPopMatrix();

	glPushMatrix();
	glTranslatef(1.2,1.0,-3.9);
	glRotatef(_angle*1000,0.0,0.0,1.0);
	glutSolidCube(1);
	glPopMatrix();



	glutSwapBuffers();
}

//Called every 25 milliseconds
void update(int value) {
	_angle +=0.005*sentido;
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}
void handleKeypress(unsigned char key,int,int){
	if(key == 'w')
		sentido = 1;
	if(key == 's')
		sentido = -1;
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);

	glutCreateWindow("cg");
	initRendering();

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);

	glutMainLoop();
	return 0;
}









