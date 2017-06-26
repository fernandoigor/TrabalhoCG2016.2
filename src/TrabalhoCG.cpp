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
#include "Tank.h"

using namespace std;

Tank player;

const float BOX_SIZE = 7.0f; //The length of each side of the cube
float _angle = 0;            //The rotation of the box
int sentido = 0;
int rotacao = 0;
int rotGun = 0;
int shoot = 0;

int keyWPressed = 0;
int keyDPressed = 0;
int keyAPressed = 0;
int keySPressed = 0;

int keyJPressed = 0;
int keyKPressed = 0;


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
	float posX = player.getPosX();
	float posZ = player.getPosZ();

	//glTranslatef(posX, 0.0f, posZ);

	glDisable(GL_TEXTURE_2D);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);

	player.Draw();





	glutSwapBuffers();
}

//Called every 25 milliseconds
void update(int value) {
	if(keyWPressed == 1)
		sentido = -1;
	else if(keySPressed == 1)
		sentido = 1;
	else
		sentido = 0;

	if(keyDPressed == 1)
		rotacao = -1;
	else if(keyAPressed == 1)
		rotacao = 1;
	else
		rotacao = 0;

	if(keyKPressed == 1)
			rotGun = -1;
		else if(keyJPressed == 1)
			rotGun = 1;
		else
			rotGun = 0;


	//_angle +=0.005*sentido;
	player.setMotion(sentido,rotacao,rotGun,shoot);
	glutPostRedisplay();
	//cout << sentido << " " << rotacao << endl;
	glutTimerFunc(25, update, 0);
}

void Teclado(unsigned char key, int x, int y){
	switch(key){
	case 'w':
			keyWPressed =1;
			break;
	case 'd':
			keyDPressed =1;
			break;
	case 's':
			keySPressed =1;
			break;
	case 'a':
			keyAPressed =1;
			break;
	case 'j':
			keyJPressed =1;
			break;
	case 'k':
			keyKPressed =1;
			break;
	case 'h':
			shoot =1;
			break;
	}
}
void TecladoUp(unsigned char key, int x, int y){

	switch(key){
		case 'w':
				keyWPressed =0;
				break;
		case 'd':
				keyDPressed =0;
				break;
		case 's':
				keySPressed =0;
				break;
		case 'a':
				keyAPressed =0;
				break;
		case 'j':
				keyJPressed =0;
				break;
		case 'k':
				keyKPressed =0;
				break;
		case 'h':
				shoot =0;
				break;
		}
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);

	glutCreateWindow("cg");
	initRendering();

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(Teclado);
	glutKeyboardUpFunc(TecladoUp);
	glutReshapeFunc(handleResize);
	glutTimerFunc(25, update, 0);

	glutMainLoop();
	return 0;
}









