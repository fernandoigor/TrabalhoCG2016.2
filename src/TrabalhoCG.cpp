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
#include <stdlib.h>
#include <math.h>

#include "imageloader.h"
#include "Tank.h"

using namespace std;

int JANELAX = 800;
int JANELAY = 600;

Tank player;
Tank inimigo[3];


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


GLuint fogMode[] = { GL_EXP, GL_EXP2, GL_LINEAR };
GLuint fogfilter = 0;
GLfloat fogColor[4]= {0.5f, 0.5f, 0.5f, 1.0f};		// Fog color


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
	image = loadBMP("plano.bmp");
	_textureId[0] = loadTexture(image);
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
void criarPlano(float x,float y,float z){
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId[0]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-x, -0.32, -z);

		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-x, -0.32, z);

		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(x, -0.32, z);

		glTexCoord2f(1.0f, 0.0f);
		glVertex3f( x, -0.32, -z);
	glEnd();

}
void LifeBar(float x,float y,float hp,float max){
	//glColor3f(0.2f, 0.3f, 1.0f);
	hp +=2.5;
	glBegin(GL_QUADS);
		glVertex3f(-6, 1, -100);
		glVertex3f(-6, 1, 100);
		glVertex3f(-6+(12*hp/max), 1, 100);
		glVertex3f(-6+(12*hp/max), 1, -100);
	glEnd();
}
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, JANELAX, JANELAY);
	glClearColor(1.0f, 1.0f, 0.8f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	float posX = player.getPosX();
	float posZ = player.getPosZ();
	float gunX = player.getGunX();
	float gunZ = player.getGunZ();
	/*float rot = player.getRot();
	float camX, camZ;*/
	//camX = cos(rot*3.14/180)*(posX+10)+ + sin(rot*3.14/180)*(posZ+10);
	//camZ = -sin(rot*3.14/180)*(posX+10) + cos(rot*3.14/180)*(posZ+10);
	//cout << acos(gunX)*180.0/ 3.14159265 << endl;
	//gluLookAt(posX, 5.0,posZ,		/* eye */
	//		posX+gunX*10, 1.0,posZ+gunZ*10,		/* look */
	//    	  0.0, 1.0, 0.0);		/* up */

	gluLookAt(posX-gunX*15, 7.0,posZ-gunZ*15,		/* eye */
				posX+gunX*5, 1.0,posZ+gunZ*5,		/* look */
		    	  0.0, 1.0, 0.0);		/* up */



	GLfloat ambientLight[] = {0.7f, 0.7f, 0.7f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

	GLfloat lightColor[] = {0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat lightPos[] = {-2 * BOX_SIZE, BOX_SIZE, 4 * BOX_SIZE, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	//glRotatef(_angle*80, 0.0f, 1.0f, 0.0f);


	criarPlano(50,1,50);

	//glTranslatef(posX, 0.0f, posZ);

	glDisable(GL_TEXTURE_2D);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	player.Draw();
	glPopMatrix();

	for(int i=0; i<3;i++){
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureId[1]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glColor3f(1.0f, 1.0f, 1.0f);
		glPushMatrix();
		inimigo[i].Draw();
		glPopMatrix();
	}
	//glutSwapBuffers();
	//#####################################
	//#####################################
	glViewport(JANELAX-150, JANELAY-150, 150, 150);
	glScissor(JANELAX-150,JANELAY-150,JANELAX,JANELAY);
	glClear(GL_DEPTH_BUFFER_BIT);
	//glClearColor(1.0f, 1.0f, 0.8f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(posX-gunX*15, 80.0,posZ-gunZ*15,		/* eye */
				posX, 1.0,posZ,		/* look */
				  0.0, 1.0, 0.0);		/* up */




	criarPlano(50,1,50);


	glDisable(GL_TEXTURE_2D);


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId[1]);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	player.Draw();
	glPopMatrix();

	for(int i=0; i<3;i++){
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, _textureId[1]);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glColor3f(1.0f, 1.0f, 1.0f);
		glPushMatrix();
		inimigo[i].Draw();
		glPopMatrix();
	}
	// ##############################################
	// ##############################################

	glViewport(JANELAX-150, JANELAY-160, 150, 10);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 10, 0,		/* eye */
			  0.0, 0.0,1.0,		/* look */
			  0.0, 1.0, 0.0);		/* up */
	glColor3f(0.2f, 0.3f, 1.0f);
	LifeBar(0,0,player.getReloadTime(),150.0);

	// ##############################################
	// ##############################################

	glViewport(JANELAX-150, JANELAY-170, 150, 10);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 10, 0,		/* eye */
			  0.0, 0.0,1.0,		/* look */
			  0.0, 1.0, 0.0);		/* up */
	glColor3f(0.2f, 1.0f, 0.2f);
	LifeBar(0,0,player.getLife(),100.0);
	//glViewport(200, 200, 50, 50);

	glutSwapBuffers();
}

int coll(float xA,float yA,float tA,float xB,float yB,float tB){
	int ladoLR = 0; // lado left right
	int ladoTB =0;  // lado top bottom
	// lado {direito =1, esquerdo = 3, atras = 5, frente = 9}

	if(xA+tA < xB) ladoLR = 1;
	else if(xA > xB+tB) ladoLR = 3;
	if(yA > yB+tB) ladoTB = 5;
	else if(yA+tA < yB) ladoTB = 9;
	return ladoLR + ladoTB;
}
int Collision(){

	float xA = player.getPosX();
	float yA = player.getPosZ();
	float tA = 6;
	float xB = 0;
	float yB = 0;
	float tB = 6;
	for(int i=0; i<3; i++){
		xA = player.getPosX();
		yA = player.getPosZ();
		tA = 6;
		// COLISAO ENTRE TANKS
		xB = inimigo[i].getPosX();
		yB = inimigo[i].getPosZ();
		tB = 6;

		if(coll(xA,yA,tA,xB,yB,tB) == 0){
			player.Collision(1);
			inimigo[i].Collision(1);
		}

		// VERIFICAR COLISAO DA BALA DO INIMIGO
		xB = inimigo[i].getBulletX();
		yB = inimigo[i].getBulletZ();
		tB = 2;

		if(coll(xA,yA,tA,xB,yB,tB) == 0){
			player.Collision(10);
			inimigo[i].destroyBullet();
		}

		// VERIFICAR COLISAO DA BALA DO PLAYER
		xA = player.getBulletX();
		yA = player.getBulletZ();
		tA = 2;

		xB = inimigo[i].getPosX();
		yB = inimigo[i].getPosZ();
		tB = 6;

		if(coll(xA,yA,tA,xB,yB,tB) == 0){
			inimigo[i].Collision(10);
			player.destroyBullet();
		}
	}




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


	player.setMotion(sentido,rotacao,rotGun,shoot);
	int posX,posZ;
	posX = player.getPosX();
	posZ = player.getPosZ();
	for(int i=0; i<3;i++){
		int mov, rot;
		mov = rand()%4-1;
		rot = rand()%4-1;
		//lastMov[i][0] = lastMov[i][1] = lastMov[i][mov]
		inimigo[i].setMotion(mov,rot,0,rand()%2);
		inimigo[i].setGun(posX,posZ);
	}


	Collision();
	glutPostRedisplay();
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
	player.setPlayer();
	player.setPos(-30,30);
	inimigo[0].setPos(0,-30);
	inimigo[1].setPos(-30,-30);
	inimigo[2].setPos(30,-30);


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(JANELAX, JANELAY);
	glutInitWindowPosition (500, 100);

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









