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
	//Mathematics m;
	xCoord = posX;
	yCoord = posY;
	//srand(time(NULL));
	//srand(1);
}

void Ladybug::Move(Configuration thisConf, int gridLength, int gridHeight,
		Ladybug thisLad) {
	Mathematics m;
	pair<int, int> new_pos = m.LadyDirection(this->xCoord, this->yCoord,
			gridLength, gridHeight, thisLad.preferredDir);
	cell movingTo(new_pos.first, new_pos.second);
	movingTo.InsertLadybug(thisLad);
	thisLad.setPreferredDir(m.GetNewPreferredDirection());
	cell currentCell(this->xCoord, this->yCoord);
	currentCell.RemoveLadybug(thisLad);
	this->xCoord = new_pos.first;
	this->yCoord = new_pos.second;
}

void Ladybug::setPreferredDir(int newPref) {
	this->preferredDir = newPref;
}

int Ladybug::getPreferredDir() {
	return this->preferredDir;
}
