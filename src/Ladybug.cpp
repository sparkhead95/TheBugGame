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
	preferredDir = 0;
}

Ladybug::Ladybug(int posX, int posY) {
	xCoord = posX;
	yCoord = posY;
	preferredDir = rand() % (4);
}

void Ladybug::Move(Configuration thisConf, int gridLength, int gridHeight, Ladybug thisLad) {
	Mathematics m;
	pair<int, int> new_pos = m.LadyDirection(this->xCoord, this->yCoord, gridLength, gridHeight, preferredDir);
	cell movingTo(new_pos.first, new_pos.second);
	movingTo.InsertLadybug(thisLad);
	cell currentCell(this->xCoord, this->yCoord);
	currentCell.RemoveLadybug(thisLad);
	this->xCoord = new_pos.first;
	this->yCoord = new_pos.second;
}

void Ladybug::setPreferredDir(int newPref){
	this->preferredDir = newPref;
}

int Ladybug::getPreferredDir(){
	return this->preferredDir;
}
