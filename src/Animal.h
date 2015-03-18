/*
 * Animal.h
 *
 *  Created on: 15 Mar 2015
 *      Author: chris
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <utility>
#include "Configuration.h"

using namespace std;

class Animal {

protected:
	int xCoord, yCoord;

public:
	Animal();
	void setHeight(int newHeight);
	void setLength(int newLength);
	pair<int, int> getPosition();
	~Animal();

};

class Aphid: public Animal {
public:
	Aphid();
	Aphid(int posX, int posY);
	void Move(Configuration thisConf, int gridLength, int gridHeight,
			Aphid thisAph);
	void Kill();
	void Interact();

};

class Ladybug: public Animal {
protected:
	int preferredDir;
public:
	Ladybug();
	Ladybug(int posX, int posY);
	void Move(Configuration thisConf, int gridLength, int gridHeight,
			Ladybug thisLad);
	void Kill();
	void Interact();
	void setPreferredDir(int newPref);
	int getPreferredDir();

};

#endif /* ANIMAL_H_ */
