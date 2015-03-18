/*
 * Mathematics.cpp
 *
 *  Created on: 17 Mar 2015
 *      Author: chris
 */

#include "Mathematics.h"
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>

namespace std {

Mathematics::Mathematics() {
	// TODO Auto-generated constructor stub

}

Mathematics::~Mathematics() {
	// TODO Auto-generated destructor stub
}

pair<int, int> Mathematics::AphidDirection(int xCoord, int yCoord,
		int gridLength, int gridHeight) {
	pair<int, int> finalCoords;
	int direction = 0;
	bool analyse = true;
	int old[2];
	old[0] = xCoord;
	old[1] = yCoord;
	while (analyse) {
		direction = rand() % 7;
		switch (direction) {
		case (0): //Aphid goes up
			yCoord--;
			break;
		case (1): //Aphid goes upright
			yCoord--;
			xCoord++;
			break;
		case (2): //Aphid goes right
			xCoord++;
			break;
		case (3): //Aphid goes downright
			yCoord++;
			xCoord++;
			break;
		case (4): //Aphid goes down
			yCoord++;
			break;
		case (5): //Aphid goes downleft
			yCoord++;
			xCoord--;
			break;
		case (6): //Aphid goes left
			xCoord--;
			break;
		case (7): //Aphid goes upleft
			yCoord--;
			xCoord--;
			break;
		}
		if (Boundary(gridLength, gridHeight, xCoord, yCoord)) {
			xCoord = old[0];
			yCoord = old[1];
		} else {
			analyse = false;
		}
	}
	finalCoords.first = xCoord;
	finalCoords.second = yCoord;
	return finalCoords;
}

pair<int, int> Mathematics::LadyDirection(int currentX, int currentY,
		int gridLength, int gridHeight, int preferredDir) {
	pair<int, int> newPosition;
	int possibleAngle = rand() % (2), tmpX, tmpY;
	tmpX = currentX;
	tmpY = currentY;
	if (preferredDir == 0) { // going up
		if (possibleAngle == 0) { // definitely up
			tmpY--;
			if (Bounce(gridLength, gridHeight, tmpX, tmpY) == "d") { // if we cant go up anymore
				preferredDir = 2; // change preferred direction to down
				currentY++; // go down a place (always going down now)
			} else {
				currentY--;
			}
		} else if (possibleAngle == 1) { // upright
			tmpX++;
			tmpY--;
			if ((Bounce(gridLength, gridHeight, tmpX, tmpY) == "d")
					|| (Bounce(gridLength, gridHeight, tmpX, tmpY) == "l")) { // if we cant go up or right anymore
				preferredDir = 2; // change preferred direction to down
				currentY++; //
				currentX--; // go down left (bounce back)
			} else {
				currentY--;
				currentX++; // else go upright
			}
		} else if (possibleAngle == 2) { //upleft
			tmpX--;
			tmpY--;
			if ((Bounce(gridLength, gridHeight, tmpX, tmpY) == "d")
					|| (Bounce(gridLength, gridHeight, tmpX, tmpY) == "r")) { // if we cant go up or left anymore
				preferredDir = 2; // change preferred direction to down
				currentY++; //
				currentX++; // go down right (bounce back)
			} else {
				currentY--;
				currentX--; // else go upleft
			}
		} else {
			cout << endl
					<< "Problem with the angle random number generator inside the ladybug inside going up"
					<< endl;
		}
	} else if (preferredDir == 1) { // going right
		if (possibleAngle == 0) { // definitely right
			tmpX++;
			if (Bounce(gridLength, gridHeight, tmpX, tmpY) == "l") { // if we cant go right anymore
				preferredDir = 3; // change preferred direction to left
				currentX++; // go left a place (always going left now)
			} else {
				currentY++;
			}
		} else if (possibleAngle == 1) { // upright
			tmpX++;
			tmpY--;
			if ((Bounce(gridLength, gridHeight, tmpX, tmpY) == "d")
					|| (Bounce(gridLength, gridHeight, tmpX, tmpY) == "l")) { // if we cant go up or right anymore
				preferredDir = 2; // change preferred direction to down
				currentY++; //
				currentX--; // go down left (bounce back)
			} else {
				currentY--;
				currentX++; // else go upright
			}
		} else if (possibleAngle == 2) { //upleft
			tmpX--;
			tmpY--;
			if ((Bounce(gridLength, gridHeight, tmpX, tmpY) == "d")
					|| (Bounce(gridLength, gridHeight, tmpX, tmpY) == "r")) { // if we cant go up or left anymore
				preferredDir = 2; // change preferred direction to down
				currentY++; //
				currentX++; // go down right (bounce back)
			} else {
				currentY--;
				currentX--; // else go upleft
			}
		} else {
			cout << endl
					<< "Problem with the angle random number generator inside the ladybug inside going up"
					<< endl;
		}
	} else if (preferredDir == 2) { // going down
		if (possibleAngle == 0) { // definitely up
			if (Bounce(gridLength, gridHeight, currentX, currentY) == "d") { // if we cant go up anymore
				preferredDir = 2; // change preferred direction
				currentY++; // go down a place (always going down now)
			} else {
				currentY--;
			}
		}
	} else if (preferredDir == 3) { // going left
		if (possibleAngle == 0) { // definitely up
			if (Bounce(gridLength, gridHeight, currentX, currentY) == "d") { // if we cant go up anymore
				preferredDir = 2; // change preferred direction
				currentY++; // go down a place (always going down now)
			} else {
				currentY--;
			}
		}
	} else {
		cout << endl
				<< "Problem with the preferred direction random value- is not below 4 or is not being compared"
				<< endl;
	}

	newPosition.first = currentX;
	newPosition.second = currentY;
	return newPosition;
}

bool Mathematics::Boundary(int gridLength, int gridHeight, int xCoord,
		int yCoord) {
	bool boundary = false;
	if (yCoord >= gridHeight || yCoord <= 0 || xCoord >= gridLength
			|| xCoord <= 0) {
		boundary = true;
	} else {
	}
	return boundary;
}

char Mathematics::Bounce(int gridLength, int gridHeight, int xCoord,
		int yCoord) {
	char dir = "";
	if (yCoord >= gridHeight) {
		dir = "u";
	}
	if (yCoord <= 0) {
		dir = "d";
	}
	if (xCoord >= gridLength) {
		dir = "l";
	}
	if (xCoord <= 0) {
		dir = "r";
	}
	return dir;
}

bool Mathematics::FinaliseProbability(float unfinalisedProbability) {
	float feasability = ((double) rand() / (RAND_MAX));
	if (feasability <= unfinalisedProbability) {
		return true;
	} else {
		return false;
	}
}

pair<cell, bool> Mathematics::cellExists(cell checkCell,
		vector<cell> existingCells) {
	bool exists = false;
	cell existingCell;
	for (vector<cell>::iterator cellIt = existingCells.begin();
			cellIt != existingCells.end(); ++cellIt) {
		if ((checkCell.getX() == (*cellIt).getX())
				&& (checkCell.getY() == (*cellIt).getY())) {
			exists = true;
			existingCell = (*cellIt);
			return make_pair(existingCell, true);
		}
	}
	if (exists == false) {
		return make_pair(existingCell, false);
	}
}

} /* namespace std */
