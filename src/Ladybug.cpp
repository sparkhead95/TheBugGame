/*
 * Aphid.cpp
 *
 *  Created on: 10 Mar 2015
 *      Author: chris
 */

#include "Animal.h"
#include "Mathematics.h"

Ladybug::Ladybug() {
	xCoord = 0;
	yCoord = 0;
}

Ladybug::Ladybug(int posX, int posY) {
	xCoord = posX;
	yCoord = posY;
}

void Ladybug::Move(Configuration thisConf, int gridLength, int gridHeight, Ladybug thisLad) {
	Mathematics m;
	pair<int, int> new_pos = m.LadyDirection(this->xCoord, this->yCoord, gridLength, gridHeight);
	cell movingTo(new_pos.first, new_pos.second);
	movingTo.InsertAphid(thisAph);
	cell currentCell(this->xCoord, this->yCoord);
	currentCell.RemoveAphid(thisAph);
	this->xCoord = new_pos.first;
	this->yCoord = new_pos.second;
}
