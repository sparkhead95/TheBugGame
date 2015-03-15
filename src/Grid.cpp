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

// might not even use this method
void Grid::write() {

}

void Grid::create(vector<Aphid> aphidVector, vector<Ladybug> ladyVector) {
	vector<string> horizontal(this->height);
	unsigned int j;
	for (vector<Aphid>::iterator aphIt = aphidVector.begin();
			aphIt != aphidVector.end(); ++aphIt) {

		pair<int, int> temp_pos = (*aphIt).getPosition();
		for (j = 0; j < horizontal.size(); j++) {
			if (j == temp_pos.first) {
				vector<string> lengthways(this->length);
				unsigned int i;
				for (i = 0; i < lengthways.size(); i++)
					if (i == temp_pos.second) {
						lengthways.at(i) = "|A|";
					} else {
						lengthways.at(i) = "|-|";
					}

				for (i = 0; i < lengthways.size(); i++)
					cout << " " << lengthways.at(i);
				cout << endl;
			}
		}
	}
}

int Grid::getHeight() {
	return this->height;
}

int Grid::getLength() {
	return this->length;
}
