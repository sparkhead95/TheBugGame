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
	this->preferredDirection = 0;

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
	srand(time(NULL));
	int possibleAngle = getRandomNumber(0, 2), tmpX, tmpY;
	//cout<<endl<<"Possible angle = "<<possibleAngle<<endl;
	//cout<<endl<<"Preferred direction = "<<preferredDir<<endl;
	//srand(1);
	tmpX = currentX;
	tmpY = currentY;
	if (preferredDir == 0) { // going up
		if (possibleAngle == 0) { // definitely up
			tmpY--;
			if (Bounce(gridLength, gridHeight, tmpX, tmpY) == 'd') { // if we cant go up anymore
				preferredDir = 2; // change preferred direction to down
				currentY++; // go down a place (always going down now)
				//cout<<endl<<"We went down!"<<endl;
			} else {
				currentY--;
				//cout<<endl<<"We went up!"<<endl;
			}
		} else if (possibleAngle == 1) { // upright
			tmpX++;
			tmpY--;
			if ((Bounce(gridLength, gridHeight, tmpX, tmpY) == 'd')
					|| (Bounce(gridLength, gridHeight, tmpX, tmpY) == 'l')) { // if we cant go up or right anymore
				preferredDir = 2; // change preferred direction to down
				currentY++; //
				currentX--; // go down left (bounce back)
				//cout<<endl<<"We went down left!"<<endl;
				//cout << endl << "Bounced!" << endl;
			} else {
				currentY--;
				currentX++; // else go upright
				//cout<<endl<<"We went up right!"<<endl;
			}
		} else if (possibleAngle == 2) { //upleft
			tmpX--;
			tmpY--;
			if ((Bounce(gridLength, gridHeight, tmpX, tmpY) == 'd')
					|| (Bounce(gridLength, gridHeight, tmpX, tmpY) == 'r')) { // if we cant go up or left anymore
				preferredDir = 2; // change preferred direction to down
				currentY++; //
				currentX++; // go down right (bounce back)
				//cout<<endl<<"We went down right!"<<endl;
				//cout << endl << "Bounced!" << endl;
			} else {
				currentY--;
				currentX--; // else go upleft
				//cout<<endl<<"We went up left!"<<endl;
			}
		} else {
			cout << endl
					<< "Problem with the angle random number generator inside the ladybug inside going up"
					<< endl;
		}
	} else if (preferredDir == 1) { // going right<
		if (possibleAngle == 0) { // definitely right
			tmpX++;
			if (Bounce(gridLength, gridHeight, tmpX, tmpY) == 'l') { // if we cant go right anymore
				preferredDir = 3; // change preferred direction to left
				currentX--; // go left a place (always going left now)
				//cout<<endl<<"We went left!"<<endl;
				//cout << endl << "Bounced!" << endl;
			} else {
				currentX++;
				//cout<<endl<<"We went down right!"<<endl;
			}
		} else if (possibleAngle == 1) { // upright
			tmpX++;
			tmpY--;
			if ((Bounce(gridLength, gridHeight, tmpX, tmpY) == 'd')
					|| (Bounce(gridLength, gridHeight, tmpX, tmpY) == 'l')) { // if we cant go up or right anymore
				preferredDir = 3; // change preferred direction to left
				currentY++; //
				currentX--; // go down left (bounce back)
				//cout<<endl<<"We went down left!"<<endl;
				//cout << endl << "Bounced!" << endl;
			} else {
				currentY--;
				currentX++; // else go upright
				//cout<<endl<<"We went up right!"<<endl;
			}
		} else if (possibleAngle == 2) { //downright
			tmpX++;
			tmpY++;
			if ((Bounce(gridLength, gridHeight, tmpX, tmpY) == 'u')
					|| (Bounce(gridLength, gridHeight, tmpX, tmpY) == 'l')) { // if we cant go down or right anymore
				preferredDir = 3; // change preferred direction to left
				currentY--; //
				currentX--; // go up left (bounce back)
				//cout<<endl<<"We went up left!"<<endl;
				//cout << endl << "Bounced!" << endl;
			} else {
				currentY++;
				currentX++; // else down right
				//cout<<endl<<"We went down right!"<<endl;
			}
		} else {
			cout << endl
					<< "Problem with the angle random number generator inside the ladybug inside going right"
					<< endl;
		}
	} else if (preferredDir == 2) { // going down
		if (possibleAngle == 0) { // definitely down
			tmpY++;
			if (Bounce(gridLength, gridHeight, tmpX, tmpY) == 'u') { // if we cant go down anymore
				preferredDir = 0; // change preferred direction to up
				currentY--; // go up a place (always going up now)
				//cout<<endl<<"We went up!"<<endl;
				//cout << endl << "Bounced!" << endl;
			} else {
				currentY++; // else go down
				//cout<<endl<<"We went down!"<<endl;
			}
		} else if (possibleAngle == 1) { // downright
			tmpX++;
			tmpY++;
			if ((Bounce(gridLength, gridHeight, tmpX, tmpY) == 'u')
					|| (Bounce(gridLength, gridHeight, tmpX, tmpY) == 'l')) { // if we cant go down or right anymore
				preferredDir = 0; // change preferred direction to up
				currentY = currentY - 2; //
				currentX = currentX - 2; // go up left (bounce back)
				//cout<<endl<<"We went up left!"<<endl;
				//cout << endl << "Bounced!" << endl;
			} else {
				currentY++;
				currentX++; // else down right
				//cout<<endl<<"We went down right!"<<endl;
			}
		} else if (possibleAngle == 2) { //downleft
			tmpX--;
			tmpY++;
			if ((Bounce(gridLength, gridHeight, tmpX, tmpY) == 'u')
					|| (Bounce(gridLength, gridHeight, tmpX, tmpY) == 'r')) { // if we cant go down or left anymore
				preferredDir = 0; // change preferred direction to up
				currentY--; //
				currentX++; // go up right (bounce back)
				//cout<<endl<<"We went up right!"<<endl;
				//cout << endl << "Bounced!" << endl;
			} else {
				currentY++;
				currentX--; // else down left
				//cout<<endl<<"We went down left!"<<endl;
			}

		} else {
			cout << endl
					<< "Problem with the angle random number generator inside the ladybug inside going down"
					<< endl;
		}
	} else if (preferredDir == 3) { // going left
		if (possibleAngle == 0) { // definitely left
			tmpX--;
			if (Bounce(gridLength, gridHeight, tmpX, tmpY) == 'r') { // if we cant go left anymore
				preferredDir = 1; // change preferred direction to right
				currentX++; // go right a place (always going right now)
				//cout<<endl<<"We went right!"<<endl;
				//cout << endl << "Bounced!" << endl;
			} else {
				currentX--;
				//cout<<endl<<"We went left!"<<endl;
			}
		} else if (possibleAngle == 1) { // downleft
			tmpX--;
			tmpY++;
			if ((Bounce(gridLength, gridHeight, tmpX, tmpY) == 'u')
					|| (Bounce(gridLength, gridHeight, tmpX, tmpY) == 'r')) { // if we cant go down or left anymore
				preferredDir = 1; // change preferred direction to right
				currentY--; //
				currentX++; // go up right (bounce back)
				//cout<<endl<<"We went up right!"<<endl;
				//cout << endl << "Bounced!" << endl;
			} else {
				currentY++;
				currentX--; // else down left
				//cout<<endl<<"We went down left!"<<endl;
			}
		} else if (possibleAngle == 2) { //upleft
			tmpX--;
			tmpY--;
			if ((Bounce(gridLength, gridHeight, tmpX, tmpY) == 'd')
					|| (Bounce(gridLength, gridHeight, tmpX, tmpY) == 'r')) { // if we cant go up or left anymore
				preferredDir = 1; // change preferred direction to right
				currentY++; //
				currentX++; // go down right (bounce back)
				//cout<<endl<<"We went down right!"<<endl;
				//cout << endl << "Bounced!" << endl;
			} else {
				currentY--;
				currentX--; // else up left
				//cout<<endl<<"We went up left!"<<endl;
			}
		} else {
			cout << endl
					<< "Problem with the angle random number generator inside the ladybug inside going left"
					<< endl;
		}
	} else {
		cout << endl
				<< "Problem with the preferred direction random value- is not below 4 or is not being compared"
				<< endl;
	}
	this->preferredDirection = preferredDir;
	if ((currentX >= 0) && (currentX < gridLength)) {
		newPosition.first = currentX;

	} else {
		//cout << endl << "X is oob" << endl;
	}
	if ((currentY >= 0) && (currentX < gridHeight)) {
		newPosition.second = currentY;
	} else {
		//cout << endl << "Y is oob" << endl;
	}

	return newPosition;
}

int Mathematics::GetNewPreferredDirection() {
	return this->preferredDirection;
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
	char dir = 'N';
	if (yCoord > gridHeight) {
		dir = 'u';
	}
	if (yCoord < 0) {
		dir = 'd';
	}
	if (xCoord > gridLength) {
		dir = 'l';
	}
	if (xCoord < 0) {
		dir = 'r';
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

int Mathematics::getRandomNumber(int min, int max) {
	int randNum = rand() % (max - min + 1) + min;
	return randNum;
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

		}
	}
	if (exists == false) {
		return make_pair(existingCell, false);
		cout << endl << "false" << endl;
	} else {
		return make_pair(existingCell, true);
		cout << endl << "true" << endl;
	}
}

} /* namespace std */
