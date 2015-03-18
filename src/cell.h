/*
 * cell.h
 *
 *  Created on: 17 Mar 2015
 *      Author: chris
 */

#ifndef CELL_H_
#define CELL_H_

#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include "Animal.h"

using namespace std;
class cell {
protected:
	vector<Aphid> cellAphids;
	vector<Ladybug> cellLadys;

	int xCoord, yCoord;
public:
	cell();
	cell(int posX, int posY);
	string AphidPresent();
	string LadybugPresent();
	string GetCellContents();
	void InsertAphid(Aphid newAphid);
	void InsertLadybug(Ladybug newLadybug);
	void RemoveAphid(Aphid thisAphid);
	void RemoveLadybug(Ladybug thisLadybug);
	int getX();
	int getY();
	int getAphidsSize();
	int getLadysSize();
};

#endif /* CELL_H_ */
