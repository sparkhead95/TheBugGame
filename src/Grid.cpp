/*
 * Grid.cpp
 *
 *  Created on: 10 Mar 2015
 *      Author: chris
 */
#include <vector>
#include "Grid.h"
#include <string>
#include <iostream>

using namespace std;

Grid::Grid() {
	this->height = 10;
	this->length = 10;
}

Grid::Grid(int new_height, int new_length) {
	this->height = new_height;
	this->length = new_length;
}

void Grid::write() {
	vector<string> horizontal(this->height);
	unsigned int j;
	for (j = 0; j < horizontal.size(); j++) {
		vector<string> lengthways(this->length);
		unsigned int i;
		for (i = 0; i < lengthways.size(); i++)
			lengthways.at(i) = "||";

		for (i = 0; i < lengthways.size(); i++)
			cout << " " << lengthways.at(i);

		cout << endl;
	}
}

void Grid::create() {

}

int Grid::getHeight() {
	return this->height;
}

int Grid::getLength() {
	return this->length;
}
