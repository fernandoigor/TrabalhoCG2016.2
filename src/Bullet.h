/*
 * Bullet.h
 *
 *  Created on: 26 de jun de 2017
 *      Author: ferna
 */

#ifndef BULLET_H_
#define BULLET_H_

class Bullet {
public:
	Bullet();
	virtual ~Bullet();
	void Draw();
	void Set(float,float,float,float);
	float getBulletX();
	float getBulletZ();
private:
	float dirBulletX = -999;
	float dirBulletZ = -999;
	float bulletX = -999;
	float bulletZ = -999;
};

#endif /* BULLET_H_ */
