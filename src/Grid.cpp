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
#include "Mathematics.h"
#include "cell.h"
#include <stdexcept>

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
	vector<vector<string> > column(this->height,
			vector<string>(this->length, "| -:- |"));
	Mathematics m;
	for (vector<Aphid>::iterator aphIt = aphidVector.begin();
			aphIt != aphidVector.end(); ++aphIt) {

		pair<int, int> temp_pos = (*aphIt).getPosition();
		// we create a temporary cell because if there is already a cell at its location we don't want to create two-
		// so we can rid ourselves of this one if necessary.
		cell tempCell(temp_pos.first, temp_pos.second);
		if (m.cellExists(tempCell, existingCells).second == true) {
			cell existingCell = m.cellExists(tempCell, existingCells).first;
			existingCell.InsertAphid(*aphIt);
			//existingCells.push_back(existingCell);
			vector<string> & row = column.at(temp_pos.second);
			row.at(temp_pos.first) = existingCell.GetCellContents();
			//cout << "inserted an aphid at " << temp_pos.first << "," << temp_pos.second << endl;
		} else {
			cell movingTo(temp_pos.first, temp_pos.second);
			movingTo.InsertAphid(*aphIt);
			existingCells.push_back(movingTo);
			vector<string> & row = column.at(temp_pos.second);
			row.at(temp_pos.first) = movingTo.GetCellContents();
		}

	}
	//cout << endl << "Aphids written." << endl;

	for (vector<Ladybug>::iterator ladIt = ladyVector.begin();
			ladIt != ladyVector.end(); ++ladIt) {

		pair<int, int> temp_pos = (*ladIt).getPosition();
		cell tempCell(temp_pos.first, temp_pos.second);
		if (m.cellExists(tempCell, existingCells).second == true) {
			//cout << endl << "Fell to first" << endl;
			cell existingCell = m.cellExists(tempCell, existingCells).first;
			//cout << endl << "created existing cell." << endl;
			existingCell.InsertLadybug(*ladIt);
			//cout << endl << "inserted ladybug" << endl;
			if (temp_pos.second < this->height) {
				vector<string> & row = column.at(temp_pos.second);
				//cout << endl << "row located. assigning cell contents.."<< endl;
				try {
					row.at(temp_pos.first) = existingCell.GetCellContents();
					;
				} catch (const std::out_of_range& oor) {
					//std::cerr << "Out of Range error: " << oor.what() << '\n';
				}
			} else {
				//cout << endl << "exceeded height" << endl;
			}
			//cout << "inserted a ladybug at " << temp_pos.first << "," << temp_pos.second << endl;
		} else if (m.cellExists(tempCell, existingCells).second == false) {
			//cout << endl << "Fell to second" << endl;
			cell movingTo(temp_pos.first, temp_pos.second);

			movingTo.InsertLadybug(*ladIt);
			existingCells.push_back(movingTo);
			//cout << endl << "locating row from columns..." << endl;
			//cout<<endl<<temp_pos.second<<endl;
			if (temp_pos.second < this->height) {
				vector<string> & row = column.at(temp_pos.second);
				//cout << endl << "row located. assigning cell contents.."	<< endl;
				if (temp_pos.first < this->length) {
					//cout << endl << temp_pos.first<< endl;
					try {
						row.at(temp_pos.first) = movingTo.GetCellContents();
					} catch (const std::out_of_range& oor) {
						//std::cerr << "Out of Range error: " << oor.what() << '\n';
					}
				} else {
					//cout << endl << "exceeded length."<< endl;
				}
			} else {
				//cout << endl << "exceeded height" << endl;
			}

		} else {
			cout << endl
					<< "Cannot establish equality of cells due to a comparison clause"
					<< endl;
		}
	}

	//cout << endl << "Ladybugs written." << endl;
	cout << aphidVector.size() << " Aphids and " << ladyVector.size()
			<< " ladybugs in total." << endl;
	for (unsigned int i = 0; i < column.size(); i++) {
//find the row
		vector<string> & row = column.at(i);
		for (int j = 0; j < row.size(); j++) {
			cout << " " << row.at(j);

		}
		cout << endl;
	};
	/*for (vector<cell>::iterator cellIt = existingCells.begin();
	 cellIt != existingCells.end(); ++cellIt) {
	 cout<<endl<<(*cellIt).GetCellContents()<<" at "<<(*cellIt).getX()<<" "<<(*cellIt).getY();
	 cout<<endl<<(*cellIt).getAphidsSize()<<" aphids and "<<(*cellIt).getLadysSize()<< "ladybugs at "<<(*cellIt).getX()<<" "<<(*cellIt).getY();
	 }*/
	cout << endl;

}

int Grid::getHeight() {
	return this->height;
}

int Grid::getLength() {
	return this->length;
}

vector<cell> Grid::getExistingCells() {
	return this->existingCells;
}

