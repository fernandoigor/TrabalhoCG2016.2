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
#include <stdlib.h>
#include "Bullet.h"
using namespace std;

Tank::Tank() {
	// TODO Auto-generated constructor stub

}

void Tank::Draw() {
		const float BOX_SIZE = 7.0f; //The length of each side of the cube


		glPushMatrix();
			if(life == 0.0)
				glTranslatef(0.0,-1.0,0.0);
			glColor3f(0.7,0.7,0.7);
			glTranslatef(posXTank,3.0,posZTank);
			glRotatef(rotGun+90,0.0,1.0,0.0);
			glutSolidOctahedron();
			glPushMatrix();
			glScalef(1.0,0.5,1.0);
			glTranslatef(0.0,-1.1,0.0);
			glutSolidCube(2);
			glPopMatrix();
			glutSolidCone(0.5,6,4,4);
		glPopMatrix();

		glPushMatrix();
		glBegin(GL_LINES);
		glVertex3f(0+posXTank, 1, 0+posZTank);
		glVertex3f(posXTank+dirGunX, 1, posZTank+dirGunZ);
		glEnd();
		glPopMatrix();
		if(shootBullet > 0){
			bullet.Draw();
		}

		glTranslatef(posXTank, 0.0f, posZTank);
		glRotatef(rotTank, 0.0f, 1.0f, 0.0f);


		glRotatef(rotInertia, 0.0f, 0.0f, 1.0f);

		glPushMatrix();
			if(player == 1)
				glColor3f(1.0*(life/100.0),1.0*(life/100.0),0.0*(life/100.0));
			else
				glColor3f(0.0*(life/100.0),1.0*(life/100.0),0.0*(life/100.0));
			if(life == 0.0)
				glTranslatef(0.0,-1.0,0.0);
			glTranslatef(0.0,1.0,0.0);
			glScalef(1.2,0.4,0.75);
			glutSolidCube(4);
		glPopMatrix();

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
				glTranslatef(-2.5,1.3,1.7);
				glRotatef(rodaL,0.0,0.0,1.0);
				glutSolidCube(0.5);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(2.5,1.3,1.7);
				glRotatef(rodaL,0.0,0.0,1.0);
				glutSolidCube(0.5);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-1.2,1.0,1.9);
				glRotatef(rodaL,0.0,0.0,1.0);
				glutSolidCube(1);
				glPopMatrix();

			glPushMatrix();
			glTranslatef(1.2,1.0,1.9);
			glRotatef(rodaL,0.0,0.0,1.0);
			glutSolidCube(1);
			glPopMatrix();

			// RODAS ESQUERDA

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
	if(life == 0){
		sentido = rotacao = gun = shoot = 0;
	}
		rotGun += gun;
		if(rotGun >= 360 || rotGun <= -360)
			rotGun = 0;
		if(player == 1){
		dirGunX = cos(rotGun*3.14/180)*1 + sin(rotGun*3.14/180)*0 + 0;
		dirGunZ = -sin(rotGun*3.14/180)*1 + cos(rotGun*3.14/180)*0 + 0;
		}

		if(shoot == 1 && shootBullet == 0 && (inimigoDetectado == 1 || player == 1)){
			shootBullet = 1;
			float dirBulletX = dirGunX*0.7;//cos(rotGun*3.14/180)*0.7;//+ sin(rotGun*3.14/180)*0 + 0;
			float dirBulletZ = dirGunZ*0.7;//-sin(rotGun*3.14/180)*0.7;//+ cos(rotGun*3.14/180)*0 + 0;

			float bulletX = posXTank;
			float bulletZ = posZTank;
			bullet.Set(dirBulletX,dirBulletZ,bulletX,bulletZ);

		}else if(shootBullet != 0)
			shootBullet++;

		if(shootBullet > 150){
			bullet.Set(-999,-999,-999,-999);
			shootBullet = 0;
		}

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

		lastPosXTank = posXTank;
		lastPosZTank = posZTank;
		posXTank -=cos(rotTank*3.14/180)*sentido/10.0;
		posZTank +=sin(rotTank*3.14/180)*sentido/10.0;
}

float Tank::getPosX() {
	return posXTank;
}
float Tank::getPosZ() {
	return posZTank;
}

void Tank::Collision(int n){
	life -=n;
	if(life < 0)
		life = 0;
	if(n == 1){
		posXTank = lastPosXTank;
		posZTank = lastPosZTank;
	}
}

void Tank::setPos(float x,float z){
	posXTank = lastPosXTank = x;
	posZTank = lastPosZTank = z;
}

int Tank::getLife(){
	return life;
}

float Tank::getBulletX(){
	return bullet.getBulletX();
}
float Tank::getBulletZ(){
	return bullet.getBulletZ();
}
void Tank::destroyBullet(){
	bullet.Set(-999,-999,-999,-999);
}

void Tank::setGun(float x, float z){
	if(life != 0){
		float distancia = sqrt((x-posXTank)*(x-posXTank) + (z-posZTank)*(z-posZTank));
		if(distancia < 40){
			inimigoDetectado = 1;
			dirGunX = ((x - posXTank)/ sqrt((x - posXTank)*(x - posXTank)   +   (z - posZTank)*(z - posZTank)));
			dirGunZ = ((z - posZTank)/ sqrt((x - posXTank)*(x - posXTank)   +   (z - posZTank)*(z - posZTank)));
			//cout << dirGunX << " " << dirGunZ << endl;
			rotGun = calcAngle(dirGunX, dirGunZ, 1.0,0.0);
			cout << x - posXTank << " "<< z - posZTank << endl;
			//calcAngle(1, 1, 1.0,0.0);
		}else
			inimigoDetectado = 0;
	}
}
float Tank::getGunX(){
	return dirGunX;
}
float Tank::getGunZ(){
	return dirGunZ;
}
float Tank::getRot(){
	return rotGun;
}

void Tank::setPlayer(){
	player = 1;
}

int Tank::getReloadTime(){
	return shootBullet;
}


float calcAngle(float xA, float zA, float xB, float zB){
	return -acos((xA*xB + zA*zB) /(sqrt(xA*xA + zA*zA) * sqrt(xB*xB + zB*zB)))*180.0/ 3.14159265;
}

