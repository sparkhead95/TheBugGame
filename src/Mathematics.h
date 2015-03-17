/*
 * Mathematics.h
 *
 *  Created on: 17 Mar 2015
 *      Author: chris
 */

#ifndef MATHEMATICS_H_
#define MATHEMATICS_H_


#include <utility>
namespace std {

class Mathematics {
public:
	Mathematics();
	virtual ~Mathematics();
	pair<int, int> Direction(int xCoord, int yCoord, int gridLength, int gridHeight);
};

} /* namespace std */

#endif /* MATHEMATICS_H_ */
