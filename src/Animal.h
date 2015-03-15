/*
 * Animal.h
 *
 *  Created on: 15 Mar 2015
 *      Author: chris
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_

using namespace std;

class Animal
{

	void setHeight(int newHeight);
	void setLength(int newLength);


};

class Aphid : public Animal {

	Aphid();
	Aphid(int posX, int posY);



};

class Ladybug : public Animal {

	Ladybug();
	Ladybug(int posX, int posY);


};

#endif /* ANIMAL_H_ */
