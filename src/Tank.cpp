/*
 * Tank.cpp
 *
 *  Created on: 24 de jun de 2017
 *      Author: ferna
 */

#include "Tank.h"
#include <iostream>
#include <GL/glut.h>
#include <cmath>
using namespace std;



Tank::Tank() {
	// TODO Auto-generated constructor stub

}

void Tank::Draw() {
		const float BOX_SIZE = 7.0f; //The length of each side of the cube


		glPushMatrix();
				glColor3f(1.0,1.0,0.0);
				glTranslatef(posXTank,3.0,posZTank);
				glRotatef(rotGun+90,0.0,1.0,0.0);
				glutSolidCone(0.5,6,4,4);
		glPopMatrix();





		glPushMatrix();
		glBegin(GL_LINES);
		glVertex3f(0+posXTank, 1, 0+posZTank);
		glVertex3f(posXTank+dirGunX, 1, posZTank+dirGunZ);
		glEnd();
		glPopMatrix();
		cout << shootBullet << endl;
		if(shootBullet > 0){
			glPushMatrix();
			glTranslatef(bulletX,3,bulletZ);
			glutSolidCube(0.2);

			glPopMatrix();
		}

		glTranslatef(posXTank, 0.0f, posZTank);
		glRotatef(rotTank, 0.0f, 1.0f, 0.0f);
		glutSolidCube(1);

		glRotatef(rotInertia, 0.0f, 0.0f, 1.0f);

		/*glPushMatrix();
			glTranslatef(0.0,1.0,-8.0);
			glScalef(1.0,0.5,1.0);
			glutSolidCube(4);
		glPopMatrix();
		*/
		glPushMatrix();
		glTranslatef(0.0,0.0,2.0);
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
			glTexCoord2f(1.0f+ lonaL, 0.0f);
			glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE/1.5);

			glTexCoord2f(1.0f+ lonaL, 1.0f);
			glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE / 2);

			glTexCoord2f(0.0f+ lonaL, 1.0f);
			glVertex3f(-BOX_SIZE / 4, 0, -BOX_SIZE / 2);

			glTexCoord2f(0.0f+ lonaL, 0.0f);
			glVertex3f(-BOX_SIZE / 4, 0, -BOX_SIZE/1.5);

			// LONA TRAS
			glTexCoord2f(0.0f+ lonaL, 0.0f);
			glVertex3f(BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE/1.5);

			glTexCoord2f(0.0f+ lonaL, 1.0f);
			glVertex3f(BOX_SIZE / 2, BOX_SIZE / 4, -BOX_SIZE / 2);

			glTexCoord2f(1.0f+ lonaL, 1.0f);
			glVertex3f(BOX_SIZE / 4, 0, -BOX_SIZE / 2);

			glTexCoord2f(1.0f+ lonaL, 0.0f);
			glVertex3f(BOX_SIZE / 4, 0, -BOX_SIZE/1.5);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.0,0.0,-2.0);
		glBegin(GL_QUADS);
					glColor3f(1.0f, 1.0f, 1.0f);
					//LONA TOP
					glTexCoord2f(0.0f  + lonaR, 0.0f);
					glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 4, BOX_SIZE / 2);

					glTexCoord2f(1.7f + lonaR, 0.0f);
					glVertex3f(BOX_SIZE / 2, BOX_SIZE / 4, BOX_SIZE / 2);

					glTexCoord2f(1.7f+ lonaR, 1.0f);
					glVertex3f(BOX_SIZE / 2, BOX_SIZE / 4, BOX_SIZE/1.5);

					glTexCoord2f(0.0f+ lonaR, 1.0f);
					glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 4, BOX_SIZE/1.5);

					//LONA BOTTOM
					glTexCoord2f(1.0f  + lonaR, 0.0f);
					glVertex3f(-BOX_SIZE / 4, 0, BOX_SIZE / 2);

					glTexCoord2f(0.0f + lonaR, 0.0f);
					glVertex3f(BOX_SIZE / 4, 0, BOX_SIZE / 2);

					glTexCoord2f(0.0f+ lonaR, 1.0f);
					glVertex3f(BOX_SIZE / 4, 0, BOX_SIZE/1.5);

					glTexCoord2f(1.0f+ lonaR, 1.0f);
					glVertex3f(-BOX_SIZE / 4, 0, BOX_SIZE/1.5);

					// LONA FRENTE
					glTexCoord2f(1.0f+ lonaR, 0.0f);
					glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 4, BOX_SIZE/1.5);

					glTexCoord2f(1.0f+ lonaR, 1.0f);
					glVertex3f(-BOX_SIZE / 2, BOX_SIZE / 4, BOX_SIZE / 2);

					glTexCoord2f(0.0f+ lonaR, 1.0f);
					glVertex3f(-BOX_SIZE / 4, 0, BOX_SIZE / 2);

					glTexCoord2f(0.0f+ lonaR, 0.0f);
					glVertex3f(-BOX_SIZE / 4, 0, BOX_SIZE/1.5);

					// LONA TRAS
					glTexCoord2f(0.0f+ lonaR, 0.0f);
					glVertex3f(BOX_SIZE / 2, BOX_SIZE / 4, BOX_SIZE/1.5);

					glTexCoord2f(0.0f+ lonaR, 1.0f);
					glVertex3f(BOX_SIZE / 2, BOX_SIZE / 4, BOX_SIZE / 2);

					glTexCoord2f(1.0f+ lonaR, 1.0f);
					glVertex3f(BOX_SIZE / 4, 0, BOX_SIZE / 2);

					glTexCoord2f(1.0f+ lonaR, 0.0f);
					glVertex3f(BOX_SIZE / 4, 0, BOX_SIZE/1.5);
		glEnd();
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
			glColor3f(0.2,0.2,0.0);
			glPushMatrix();
				glTranslatef(-2.5,1.3,-1.7);
				glRotatef(rodaL,0.0,0.0,1.0);
				glutSolidCube(0.5);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(2.5,1.3,-1.7);
				glRotatef(rodaL,0.0,0.0,1.0);
				glutSolidCube(0.5);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-1.2,1.0,-1.9);
				glRotatef(rodaL,0.0,0.0,1.0);
				glutSolidCube(1);
				glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2,1.0,-1.9);
			glRotatef(rodaL,0.0,0.0,1.0);
			glutSolidCube(1);
			glPopMatrix();


			// RODAS DIREITA

			glDisable(GL_TEXTURE_2D);
						glColor3f(0.2,0.2,0.0);
						glPushMatrix();
							glTranslatef(-2.5,1.3,-1.7);
							glRotatef(rodaL,0.0,0.0,1.0);
							glutSolidCube(0.5);
						glPopMatrix();

						glPushMatrix();
							glTranslatef(2.5,1.3,-1.7);
							glRotatef(rodaL,0.0,0.0,1.0);
							glutSolidCube(0.5);
						glPopMatrix();

						glPushMatrix();
							glTranslatef(-1.2,1.0,-1.9);
							glRotatef(rodaL,0.0,0.0,1.0);
							glutSolidCube(1);
							glPopMatrix();

						glPushMatrix();
						glTranslatef(1.2,1.0,-1.9);
						glRotatef(rodaL,0.0,0.0,1.0);
						glutSolidCube(1);
						glPopMatrix();






}

void Tank::setMotion(int sentido,int rotacao,int gun,int  shoot) {
	rotGun += gun;
	if(rotGun >= 360 || rotGun <= -360)
		rotGun = 0;
	dirGunX = cos(rotGun*3.14/180)*3 + sin(rotGun*3.14/180)*0 + 0;
	dirGunZ = -sin(rotGun*3.14/180)*3 + cos(rotGun*3.14/180)*0 + 0;

	if(shoot == 1 && shootBullet == 0){
		shootBullet = 1;
		dirBulletX = cos(rotGun*3.14/180)*0.4+ sin(rotGun*3.14/180)*0 + 0;
		dirBulletZ = -sin(rotGun*3.14/180)*0.4+ cos(rotGun*3.14/180)*0 + 0;
		bulletX = posXTank;
		bulletZ = posZTank;
	}else if(shootBullet != 0)
		shootBullet++;

	if(shootBullet > 150){
		shootBullet = 0;
		bulletX = 0;
		bulletZ = 0;
	}
	bulletX += dirBulletX;
	bulletZ += dirBulletZ;

	rotTank += rotacao;
	if(rotacao >= 360 || rotacao <= -360)
		rotacao = 0;


	lonaL +=0.02*sentido+(rotacao*0.01);
	lonaR +=0.02*sentido-(rotacao*0.01);
	rodaL +=8*sentido+(rotacao*4);
	rodaR +=8*sentido-(rotacao*4);
	if(lonaL > 1.0 || lonaL < -1.0)
		lonaL = 0.0;
	if(lonaR > 1.0 || lonaR < -1.0)
			lonaR = 0.0;

	movTank = sentido;
	if(movTank == -1 && rotInertia < 10)
		rotInertia +=1;
	else if(movTank == 1 && rotInertia > -10)
		rotInertia -=1;
	else if(movTank == 0 && (rotInertia > 0.1 || rotInertia < -0.1))
			rotInertia +=-0.1*rotInertia;


	posXTank -=cos(rotTank*3.14/180)*sentido/10.0;
	posZTank +=sin(rotTank*3.14/180)*sentido/10.0;
}

float Tank::getPosX() {
	return posXTank;
}
float Tank::getPosZ() {
	return posZTank;
}
