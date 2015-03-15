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

Manager::Manager() {

}

void Manager::runPreReqs() {
	ifstream gridConfig;
	gridConfig.open("gridConfig.txt");
	//char output[100]; -- this line is required if we want to print file contents.
	if (gridConfig.is_open()) {
		/*
		 * Below is the code to print out the contents of the txt file.
		 while (!gridConfig.eof()) {
		 gridConfig >> output;
		 cout<<output;
		 }*/
		cout << "File opened.\n";
		gridConfig >> gridLength;
		gridConfig >> gridHeight;

	} else if ((gridConfig.is_open()) == false) {
		cout << "Could not locate/open file.\n";
	}

	Grid newGrid(gridLength, gridHeight);
	newGrid.write();
	gridConfig >> aphidNum;

	gridConfig >> aphidNum;
	vector<Aphid> aphidVector(aphidNum);
	 for (int i = 0; i < aphidNum; i++) {
	 gridConfig >> tempX;
	 gridConfig >> tempY;
	 aphidVector[i].setHeight(tempX);
	 aphidVector[i].setLength(tempY);
	 }

	gridConfig.close();

}
