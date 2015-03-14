/*
 * Grid.cpp
 *
 *  Created on: 10 Mar 2015
 *      Author: chris
 */

#include "Grid.h"
using namespace std;


	Grid::Grid()
	{
		this->height = 10;
		this->length = 10;
	}

	Grid::Grid(int new_height, int new_width)
	{
	this->height = new_height;
	this->length = new_width;
	}
