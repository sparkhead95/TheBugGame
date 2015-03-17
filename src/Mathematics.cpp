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

pair<int, int> Mathematics::LadyDirection(int xCoord, int yCoord,
		int gridLength, int gridHeight) {
	// ...
	srand(time(0));
	int superPath = rand() % (4);
	int subPath = rand() % (2);
	switch (superPath) {
	case (0): //up
		yCoord--;
		switch (subPath) {
		case (0): // up-left
			xCoord--;
			break;
		case (1):
			xCoord++;
			break; // up-right
		}
		break;
	case (1): //right
		xCoord++;
		switch (subPath) {
		case (0): // right-up
			yCoord--;
			break;
		case (1):
			yCoord++;
			break; // right-down
		}
		break;
	case (2): //down
		yCoord++;
		switch (subPath) {
		case (0): // down-left
			xCoord--;
			break;
		case (1):
			xCoord++;
			break; // down-right
		}
		break;
	case (3): //left
		xCoord--;
		switch (subPath) {
		case (0): // left-up
			yCoord--;
			break;
		case (1):
			xCoord++;
			break; // left-right
		}
		break;
	}
	pair<int, int> finalCoords;
	return finalCoords;
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
