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
public:
	Mathematics();
	virtual ~Mathematics();
	pair<int, int> AphidDirection(int xCoord, int yCoord, int gridLength,
			int gridHeight);
	bool Boundary(int gridLength, int gridHeight, int xCoord, int yCoord);
	bool FinaliseProbability(float unfinalisedProbability);
	pair<cell, bool> cellExists(cell checkCell, vector<cell> existingCells) ;
};

} /* namespace std */

#endif /* MATHEMATICS_H_ */
