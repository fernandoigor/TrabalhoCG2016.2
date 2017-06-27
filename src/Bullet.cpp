/*
 * Bullet.cpp
 *
 *  Created on: 26 de jun de 2017
 *      Author: ferna
 */

#include "Bullet.h"
#include <iostream>
#include <GL/glut.h>

using namespace std;

Bullet::Bullet() {
	// TODO Auto-generated constructor stub
}


Bullet::~Bullet() {
	// TODO Auto-generated destructor stub
}
void Bullet::Set(float dirBulletX, float dirBulletZ, float bulletX, float bulletZ){
	this->dirBulletX=dirBulletX;
	this->dirBulletZ=dirBulletZ;
	this->bulletX=bulletX;
	this->bulletZ=bulletZ;
}
void Bullet::Draw(){
	if(dirBulletX != -999 && dirBulletZ != -999){
		bulletX += dirBulletX;
		bulletZ += dirBulletZ;

		glPushMatrix();
		glTranslatef(bulletX,3,bulletZ);
		glutSolidCube(0.2);
		glPopMatrix();
	}
}
float Bullet::getBulletX(){
	return this->bulletX;
}
float Bullet::getBulletZ(){
	return this->bulletZ;
}
