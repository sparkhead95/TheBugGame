/*
 * Aphid.cpp
 *
 *  Created on: 10 Mar 2015
 *      Author: chris
 */

#include "Configuration.h"
#include "Animal.h"
#include "Mathematics.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

Aphid::Aphid() {
	xCoord = 0;
	yCoord = 0;
}

Aphid::Aphid(int posX, int posY) {
	xCoord = posX;
	yCoord = posY;
}

void Aphid::Move(Configuration thisConf, int gridLength, int gridHeight) {
	Mathematics m;
	pair<int, int> new_pos = m.Direction(this->xCoord, this->yCoord, gridLength, gridHeight);
	this->xCoord = new_pos.first;
	this->yCoord = new_pos.second;
}


void Aphid::Kill() {

}
