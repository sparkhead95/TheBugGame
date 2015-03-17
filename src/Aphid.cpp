/*
 * Aphid.cpp
 *
 *  Created on: 10 Mar 2015
 *      Author: chris
 */

#include "Configuration.h"
#include "Animal.h"

	Aphid::Aphid(){
		xCoord = 0;
		yCoord = 0;
	}

	Aphid::Aphid(int posX, int posY){
		xCoord = posX;
		yCoord = posY;
	}

	void Aphid::Move(Configuration thisConf) {
		float moveProb = thisConf.getAphidMoveConf();

	}

	void Aphid::Kill(){

	}

