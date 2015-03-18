/*
 * Mathematics.h
 *
 *  Created on: 17 Mar 2015
 *      Author: chris
 */

#ifndef MATHEMATICS_H_
#define MATHEMATICS_H_

#include <utility>
#include "cell.h"

namespace std {

class Mathematics {
protected:
	int preferredDirection;
public:
	Mathematics();
	virtual ~Mathematics();
	pair<int, int> AphidDirection(int xCoord, int yCoord, int gridLength,
			int gridHeight);
	bool Boundary(int gridLength, int gridHeight, int xCoord, int yCoord);
	bool FinaliseProbability(float unfinalisedProbability);
	pair<cell, bool> cellExists(cell checkCell, vector<cell> existingCells);
	pair<int, int> LadyDirection(int currentX, int currentY, int gridLength,
			int gridHeight, int preferredDir);
	char Bounce(int gridLength, int gridHeight, int xCoord,
			int yCoord);
	int GetNewPreferredDirection();
};

} /* namespace std */

#endif /* MATHEMATICS_H_ */
