/*
 * Tank.h
 *
 *  Created on: 24 de jun de 2017
 *      Author: ferna
 */

#ifndef TANK_H_
#define TANK_H_

#include "Bullet.h"

class Tank {
public:
	Tank();
	void setPlayer();
	void Draw();
	void setMotion(int,int,int,int);
	float getPosX();
	float getPosZ();
	void Collision(int);
	void setPos(float,float);
	void setGun(float,float);
	int getLife();
	float getBulletX();
	float getBulletZ();
	void destroyBullet();
	float getGunX();
	float getGunZ();
	float getRot();
	int getReloadTime();
private:
	int player = 0;
	float lonaL = 0.0; 			// MOVIMENTO LONA ESQUERDA
	float lonaR = 0.0; 			// MOVIMENTO LONA DIREITA
	float rodaL = 0.0;
	float rodaR = 0.0;
	float rotInertia = 0.0; 	// MOVIMENTO INERCIAL DO TANK
	float rotTank = 0.0;		// ROTA플O NO EIXO Z DO TANK
	float movTank = 0.0;		// MOVIMENTO DO TANK FRENT/TRAS
	float posXTank = 0.0;		// POSI플O X DO TANK
	float posZTank = 0.0;		// POSI플O Z DO TANK
	float lastPosXTank = 0.0;		// POSI플O X DO TANK
	float lastPosZTank = 0.0;		// POSI플O Z DO TANK

	float rotGun = 0.0;
	float dirGunX = 0.0;
	float dirGunZ = 0.0;

	int shootBullet = 0;
	Bullet bullet;

	float life = 100;

	int inimigoDetectado = 0;
	/*float dirBulletX = 0.0;
	float dirBulletZ = 0.0;
	float bulletX = 0.0;
	float bulletZ = 0.0;*/
};
float calcAngle(float,float,float,float);
#endif /* TANK_H_ */
