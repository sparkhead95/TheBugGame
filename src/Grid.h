/*
 * Grid.h
 *
 *  Created on: 12 Mar 2015
 *      Author: chris
 */

#ifndef GRID_H_
#define GRID_H_

#include <vector>
#include "Animal.h"

class Grid {
protected:
	int length, height;
	char *** grid;


	public:
		Grid();

		Grid(int gridlength, int gridHeight);

		void write();

		void create(vector<Aphid> aphidVector, vector<Ladybug> ladyVector);

		int getLength();

		int getHeight();




};



#endif /* GRID_H_ */
