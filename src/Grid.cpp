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
	// ============= Aphid initial draw section ============================
	vector<string> vertical(this->height);
	vector<string> horizontal(this->length);
	unsigned int j;
	string aphid = "|A|";
	string ladybug = "|L|";
	string empty = "|-|";
	for (vector<Aphid>::iterator aphIt = aphidVector.begin();
			aphIt != aphidVector.end(); ++aphIt) {

		pair<int, int> temp_pos = (*aphIt).getPosition();
		for (j = 0; j < vertical.size(); j++) {
			if (j == temp_pos.first) {
				unsigned int i;
				for (i = 0; i < horizontal.size(); i++)
					if (i == temp_pos.second) {
						horizontal.at(i) = aphid;
					} else {
						horizontal.at(i) = empty;
					}

				for (i = 0; i < horizontal.size(); i++)
				 cout << " " << horizontal.at(i);
				 cout << endl;
				 }
			}
		}
		// ========================================================

		//  ============= ladybug initial draw section ==============

		for (vector<Ladybug>::iterator ladIt = ladyVector.begin();
				ladIt != ladyVector.end(); ++ladIt) {
			pair<int, int> temp_pos = (*ladIt).getPosition();
			for (j = 0; j < vertical.size(); j++) {
				if (j == temp_pos.first) {
					unsigned int i;
					for (i = 0; i < horizontal.size(); i++)
						if (i == temp_pos.second) {
							horizontal.at(i) = ladybug;
						} else {
							if (horizontal.at(i).compare(aphid) != 0){
								horizontal.at(i) = empty;
							}
						}

					//vector<string> finalhorizontal(this->height);
					//vector<string> lengthways(this->length);

					for (i = 0; i < horizontal.size(); i++)
						cout << " " << horizontal.at(i);
					cout << endl;
				}
			}
		}
	}
// ========================================================

int Grid::getHeight() {
	return this->height;
}

int Grid::getLength() {
	return this->length;
}
