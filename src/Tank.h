/*
 * Tank.h
 *
 *  Created on: 24 de jun de 2017
 *      Author: ferna
 */

#ifndef TANK_H_
#define TANK_H_

class Tank {
public:
	Tank();
	void Draw();
	void setMotion(int,int,int,int);
	float getPosX();
	float getPosZ();
private:
	float lonaL = 0.0; 			// MOVIMENTO LONA ESQUERDA
	float lonaR = 0.0; 			// MOVIMENTO LONA DIREITA
	float rodaL = 0.0;
	float rodaR = 0.0;
	float rotInertia = 0.0; 	// MOVIMENTO INERCIAL DO TANK
	float rotTank = 0.0;		// ROTAÇÃO NO EIXO Z DO TANK
	float movTank = 0.0;		// MOVIMENTO DO TANK FRENT/TRAS
	float posXTank = 0.0;		// POSIÇÃO X DO TANK
	float posZTank = 0.0;		// POSIÇÃO Z DO TANK

	float rotGun = 0.0;
	float dirGunX = 0.0;
	float dirGunZ = 0.0;

	int shootBullet = 0;
	float dirBulletX = 0.0;
	float dirBulletZ = 0.0;
	float bulletX = 0.0;
	float bulletZ = 0.0;
};

#endif /* TANK_H_ */
