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
	void setMotion(int);
private:
	float lonaL = 0.0;
};

#endif /* TANK_H_ */
