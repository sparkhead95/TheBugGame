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
	/*vector<string> row(this->length, "|-|");
	 vector<vector<string> > board(this->height, row);
	 for (vector<Aphid>::iterator aphIt = aphidVector.begin();
	 aphIt != aphidVector.end(); ++aphIt) {

	 pair<int, int> temp_pos = (*aphIt).getPosition();
	 board[temp_pos.first()][temp_pos.second()] = "|A|";
	 }

	 for (vector<Ladybug>::iterator ladIt = ladyVector.begin();
	 ladIt != ladyVector.end(); ++ladIt) {

	 pair<int, int> temp_pos = (*ladIt).getPosition();
	 board[temp_pos.first()][temp_pos.second()] = "|L|";
	 }

	 for (unsigned int i = 0; i < board.size(); i++)
	 cout << " " << board.at(i);
	 cout << endl;
	 */

}

void Grid::create(vector<Aphid> aphidVector, vector<Ladybug> ladyVector) {
	string aphid = "|A|";
	string ladybug = "|L|";
	string empty = "|-|";
	vector<string> vertical(this->height, empty);
	vector<string> horizontal(this->length, empty);
	unsigned int j;
	vector<Ladybug>::iterator ladIt = ladyVector.begin();
	for (vector<Aphid>::iterator aphIt = aphidVector.begin();
			aphIt != aphidVector.end() && ladIt != ladyVector.end();
			++aphIt, ++ladIt) {

		pair<int, int> temp_pos = (*aphIt).getPosition();
		pair<int, int> temp_pos_l = (*ladIt).getPosition();
		for (j = 0; j < vertical.size(); j++) {
			if (j == temp_pos.first) {
				unsigned int i;
				for (i = 0; i < horizontal.size(); i++)
					if (i == temp_pos.second) {
						horizontal.at(i) = aphid;
					} else {
						horizontal.at(i) = empty;
					}

				for (i = 0; i < horizontal.size(); i++) {
					if (temp_pos.second == i)
						cout << "|A|";
					else
						cout << "| |";

					if (temp_pos_l.second == i && temp_pos_l.first == j)
						cout << "|L|";
					else
						cout << "| |";
				}
				cout << endl;
			}
		}
	}
	cout << endl;
	// ========================================================
}

int Grid::getHeight() {
	return this->height;
}

int Grid::getLength() {
	return this->length;
}
