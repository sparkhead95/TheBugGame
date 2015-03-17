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
		// we create a temporary cell because if there is already a cell at its location we don't want to create two-
		// so we can rid ourselves of this one if necessary.
		cell tempCell(temp_pos.first, temp_pos.second);
		if (cellExists(tempCell).second == true) {
			cell existingCell = cellExists(tempCell).first;
			existingCell.InsertAphid(*aphIt);
			existingCells.push_back(existingCell);
			vector<string> & row = board.at(temp_pos.first);
			row.at(temp_pos.second) = existingCell.GetCellContents();
			//cout << "inserted an aphid at " << temp_pos.first << "," << temp_pos.second << endl;
		} else {
			cell movingTo(temp_pos.first, temp_pos.second);
			movingTo.InsertAphid(*aphIt);
			existingCells.push_back(movingTo);
			vector<string> & row = board.at(temp_pos.first);
			row.at(temp_pos.second) = movingTo.GetCellContents();
		}


	}

	for (vector<Ladybug>::iterator ladIt = ladyVector.begin();
			ladIt != ladyVector.end(); ++ladIt) {

		pair<int, int> temp_pos = (*ladIt).getPosition();
		cell tempCell(temp_pos.first, temp_pos.second);
		if (cellExists(tempCell).second == true) {
			cell existingCell = cellExists(tempCell).first;
			existingCell.InsertLadybug(*ladIt);
			existingCells.push_back(existingCell);
			vector<string> & row = board.at(temp_pos.first);
			row.at(temp_pos.second) = existingCell.GetCellContents();
			//cout << "inserted a ladybug at " << temp_pos.first << "," << temp_pos.second << endl;
		} else {
			cell movingTo(temp_pos.first, temp_pos.second);
			movingTo.InsertLadybug(*ladIt);
			existingCells.push_back(movingTo);
			vector<string> & row = board.at(temp_pos.first);
			row.at(temp_pos.second) = movingTo.GetCellContents();
		}

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

pair<cell, bool> Grid::cellExists(cell checkCell) {
	bool exists = false;
	cell existingCell;
	for (vector<cell>::iterator cellIt = existingCells.begin();
			cellIt != existingCells.end(); ++cellIt) {
		if ((checkCell.getX() == (*cellIt).getX())
				&& (checkCell.getY() == (*cellIt).getY())) {
			exists = true;
			existingCell = (*cellIt);
			return make_pair(existingCell, true);
		}
	}
	if (exists == false) {
		return make_pair(existingCell, false);
	}
}
