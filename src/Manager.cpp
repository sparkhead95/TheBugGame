/*
 * Manager.cpp
 *
 *  Created on: 10 Mar 2015
 *      Author: chris
 */

#include <fstream>
#include <iostream>
#include <vector>
#include "Manager.h"
#include "Grid.h"
#include "Animal.h"

using namespace std;

int gridLength, gridHeight, aphidNum, tempX, tempY;

// Default constructor
Manager::Manager() {

}

void Manager::runPreReqs() {
	ifstream gridConfig;
	gridConfig.open("gridConfig.txt");
	//char output[100]; -- this line is required if we want to print file contents.
	if (gridConfig.is_open()) {
		/*
		 * Below is the code to print out the contents of the txt file.
		 ===========================
		 while (!gridConfig.eof()) {
		 gridConfig >> output;
		 cout<<output;
		 }
		 ===========================
		 */
		cout << "File opened.\n";
		// assign first line to local variables
		gridConfig >> gridLength;
		gridConfig >> gridHeight;

		//validation for if the file fails to open
	} else if ((gridConfig.is_open()) == false) {
		cout << "Could not locate/open file.\n";
	}

	// Create a new grid with the dimensions passed in
	Grid newGrid(gridLength, gridHeight);
	// fill the grid with characters that are later to be changed
	newGrid.write();
	// Take the amount of aphids from the config and apply it to local variable
	gridConfig >> aphidNum;
	// create a vector of Aphid objects
	vector<Aphid> aphidVector(aphidNum);
	// for every aphid, set its location from the config file
	for (int i = 0; i < aphidNum; i++) {
		gridConfig >> tempX;
		gridConfig >> tempY;
		aphidVector[i].setHeight(tempX);
		aphidVector[i].setLength(tempY);
	}

	// close the grid config
	gridConfig.close();

}
