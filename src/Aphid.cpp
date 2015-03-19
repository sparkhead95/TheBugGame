/*
 * Aphid.cpp
 *
 *  Created on: 10 Mar 2015
 *      Author: chris
 */

#include "Configuration.h"
#include "Animal.h"
#include "Mathematics.h"
#include "Grid.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "cell.h"

using namespace std;

Aphid::Aphid() {
	xCoord = 0;
	yCoord = 0;
}

Aphid::Aphid(int posX, int posY) {
	xCoord = posX;
	yCoord = posY;
}

void Aphid::Move(Configuration thisConf, int gridLength, int gridHeight, Aphid thisAph) {
	Mathematics m;
	/*cell tempCell(this->xCoord, this->yCoord);
	cell existingCell = m.cellExists(tempCell, existingCells).first;
	Aphid baby(this->xCoord, this->yCoord);
	if (existingCell.checkAphidsReproduce()){
		existingCell.InsertAphid(baby);
	}*/
	pair<int, int> new_pos = m.AphidDirection(this->xCoord, this->yCoord, gridLength, gridHeight);
	cell movingTo(new_pos.first, new_pos.second);
	movingTo.InsertAphid(thisAph);

	//existingCell.RemoveAphid(thisAph);
	this->xCoord = new_pos.first;
	this->yCoord = new_pos.second;
}


void Aphid::Kill() {

}

void Aphid::Interact(){

}
