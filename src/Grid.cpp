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
#include "cell.h"

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

	for (vector<Aphid>::iterator aphIt = aphidVector.begin();
			aphIt != aphidVector.end(); ++aphIt) {

		pair<int, int> temp_pos = (*aphIt).getPosition();
		cell movingTo(temp_pos.first, temp_pos.second);
		movingTo.InsertAphid(*aphIt);
		vector<string> & row = board.at(temp_pos.first);
		row.at(temp_pos.second) = movingTo.GetCellContents();
		//cout << "inserted an aphid at " << temp_pos.first << "," << temp_pos.second << endl;
	}

	for (vector<Ladybug>::iterator ladIt = ladyVector.begin();
			ladIt != ladyVector.end(); ++ladIt) {

		pair<int, int> temp_pos = (*ladIt).getPosition();
		cell movingTo(temp_pos.first, temp_pos.second);
		movingTo.InsertLadybug(*ladIt);
		vector<string> & row = board.at(temp_pos.first);
		row.at(temp_pos.second) = movingTo.GetCellContents();
		//cout << "inserted a ladybug at " << temp_pos.first << "," << temp_pos.second << endl;
	}

	for (unsigned int i = 0; i < board.size(); i++) {
		//find the row
		vector<string> & row = board.at(i);
		for (int j = 0; j < row.size(); j++) {
			cout << " " << row.at(j);

		}
		cout << endl;
	};
	cout << endl;
}

int Grid::getHeight() {
	return this->height;
}

int Grid::getLength() {
	return this->length;
}
