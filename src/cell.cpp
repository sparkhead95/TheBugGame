#include <vector>
#include "cell.h"
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

using namespace std;
//                                Cell.

//             cell holds an aphid vector and a ladybug vector, along with its x and y coordinates.

cell::cell() {
	xCoord = 0;
	yCoord = 0;
}

cell::cell(int posX, int posY) {
	this->xCoord = posX;
	this->yCoord = posY;
}

string cell::AphidPresent() {
	string retValue = "-";
//	This function returns a string depending on whether there's an aphid present
//	if there is, return "A:"
//	else ":"
	if (cellAphids.size() > 0) {
		retValue = "A";
	}
	return retValue;
}

string cell::LadybugPresent() {
//	same as the aphid one
	string retValue = "-";
	if (cellLadys.size() > 0) {
		retValue = "L";
	}
	return retValue;
}

string cell::GetCellContents() {
	string cellContents;
	stringstream sstrm;
	sstrm << "|" << cellAphids.size() << AphidPresent() << ":"
			<< LadybugPresent() << cellLadys.size() << "|";
	cellContents = sstrm.str();
	return cellContents;
}

void cell::InsertAphid(Aphid newAphid) {
	cellAphids.push_back(newAphid);
}

void cell::InsertLadybug(Ladybug newLadybug) {
	cellLadys.push_back(newLadybug);
}

void cell::RemoveAphid(Aphid thisAphid){
	cellAphids.erase(remove(cellAphids.begin(),cellAphids.end(),thisAphid));
}
void cell::RemoveLadybug(Ladybug thisLadybug){

}