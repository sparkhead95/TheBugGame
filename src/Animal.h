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

protected:
	int position[2];

public:
	Animal();
	void setHeight(int newHeight);
	void setLength(int newLength);
	~Animal();

};

class Aphid : public Animal {
public:
	Aphid();
	Aphid(int posX, int posY);



};

class Ladybug : public Animal {
public:
	Ladybug();
	Ladybug(int posX, int posY);


};

#endif /* ANIMAL_H_ */
