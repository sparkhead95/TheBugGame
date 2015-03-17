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

void Grid::create(vector<Aphid> aphidVector, vector<Ladybug> ladyVector) {
	vector<vector<string> > board(this->height,
			vector<string>(this->length, "| -:- |"));
	// checking if two are starting in the same place
	vector<Ladybug>::iterator ladIt = ladyVector.begin();
	for (vector<Aphid>::iterator aphIt = aphidVector.begin();
			aphIt != aphidVector.end() && ladIt != ladyVector.end();
			++aphIt, ++ladIt) {
		pair<int, int> temp_pos = (*aphIt).getPosition();
		pair<int, int> temp_pos_l = (*ladIt).getPosition();
		if ((temp_pos.first == temp_pos_l.first)&&(temp_pos.second == temp_pos_l.second)) {
			cout<<"Same!"<<endl;
			vector<string> & row = board.at(temp_pos.first);
			row.at(temp_pos.second) = "|1A:L1|";
		}


		for (vector<Aphid>::iterator aphIt = aphidVector.begin();
				aphIt != aphidVector.end(); ++aphIt) {

			pair<int, int> temp_pos = (*aphIt).getPosition();
			vector<string> & row = board.at(temp_pos.first);
			row.at(temp_pos.second) = "|1A:- |";
			//cout << "inserted an aphid at " << temp_pos.first << "," << temp_pos.second << endl;
		}

		for (vector<Ladybug>::iterator ladIt = ladyVector.begin();
				ladIt != ladyVector.end(); ++ladIt) {

			pair<int, int> temp_pos = (*ladIt).getPosition();
			vector<string> & row = board.at(temp_pos.first);
			row.at(temp_pos.second) = "| -:L1|";
			//cout << "inserted a ladybug at " << temp_pos.first << "," << temp_pos.second << endl;
		}

		for (unsigned int i = 0; i < board.size(); i++) {
			vector<string> & row = board.at(i);
			for (int j = 0; j < row.size(); j++) {
				cout << " " << row.at(j);

			}
			cout << endl;
		};
		cout << endl;
	}
}

int Grid::getHeight() {
	return this->height;
}

int Grid::getLength() {
	return this->length;
}
