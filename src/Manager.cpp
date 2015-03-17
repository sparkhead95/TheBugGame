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
#include "Configuration.h"
#include "Mathematics.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <stdlib.h>

using namespace std;
Mathematics myMath;
float aphidMoveConf = 0, aphidKillConf = 0, aphIncKillConf = 0, aphidReproConf =
		0, ladyMoveConf = 0, ladyDirConf = 0, ladyKillConf = 0, ladyReproConf =
		0;
vector<Ladybug> ladyVector;
vector<Aphid> aphidVector;
// Default constructor
Manager::Manager() {
	gridLength = 0, gridHeight = 0, aphidNum = 0, ladyNum = 0, tempX = 0, tempY =
			0;
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
		//cout << "File opened.\n";
		// assign first line to local variables
		gridConfig >> gridLength;
		gridConfig >> gridHeight;
		//validation for if the file fails to open
	} else if ((gridConfig.is_open()) == false) {
		cout << "Could not locate/open file.\n";
	}

	// Create a new grid with the dimensions passed in
	Grid initialGrid(gridLength, gridHeight);
	// Take the amount of aphids from the config and apply it to local variable
	gridConfig >> aphidNum;
	// resize aphid vector
	aphidVector.resize(aphidNum);
	// for every aphid, set its location from the config file
	for (int i = 0; i < aphidNum; i++) {
		gridConfig >> tempX;
		gridConfig >> tempY;
		aphidVector[i].setHeight(tempX);
		aphidVector[i].setLength(tempY);
	}
	// Take the amount of ladybugs from the config
	gridConfig >> ladyNum;
	// resize ladybug vector
	ladyVector.resize(ladyNum);
	// same for loop but for ladybugs
	for (int j = 0; j < ladyNum; j++) {
		gridConfig >> tempX;
		gridConfig >> tempY;
		ladyVector[j].setHeight(tempY);
		ladyVector[j].setLength(tempX);
	}

	// now that we have all of the locations for the animals, draw the grid.
	initialGrid.create(aphidVector, ladyVector);

	ifstream aphidConfig;
	aphidConfig.open("aphidConfig.txt");
	Configuration initialConfig;
	if (aphidConfig.is_open()) {
		//cout << "aphid File opened.\n";
		// assign first line to local variables
		aphidConfig >> aphidMoveConf;
		initialConfig.setAphidMoveConf(aphidMoveConf);
		aphidConfig >> aphidKillConf;
		initialConfig.setAphidKillConf(aphidKillConf);
		aphidConfig >> aphIncKillConf;
		initialConfig.setAphIncKillConf(aphIncKillConf);
		aphidConfig >> aphidReproConf;
		initialConfig.setAphidReproConf(aphidReproConf);
		// The below line checks that the data has been read into the class properly
		//cout << (initialConfig.getAphidMoveConf()) << " " << (initialConfig.getAphidKillConf()) << " " << (initialConfig.getAphIncKillConf()) << " " << (initialConfig.getAphidReproConf()) << endl;
		//validation for if the file fails to open
	} else if ((aphidConfig.is_open()) == false) {
		cout << "Could not locate/open file.\n";
	}

	ifstream ladyConfig;
	ladyConfig.open("ladyConfig.txt");
	if (aphidConfig.is_open()) {
		//cout << "ladybug File opened.\n";
		// assign first line to local variables
		ladyConfig >> ladyMoveConf;
		initialConfig.setLadyMoveConf(ladyMoveConf);
		ladyConfig >> ladyDirConf;
		initialConfig.setLadyDirConf(ladyDirConf);
		ladyConfig >> ladyKillConf;
		initialConfig.setLadyKillConf(ladyKillConf);
		ladyConfig >> ladyReproConf;
		initialConfig.setLadyReproConf(ladyReproConf);
		//validation for if the file fails to open
	} else if ((ladyConfig.is_open()) == false) {
		cout << "Could not locate/open file.\n";
	}
	Manager::runGame(aphidVector, ladyVector, initialConfig, gridLength, gridHeight);
	// close the grid config
	gridConfig.close();
	aphidConfig.close();
	ladyConfig.close();
}

void Manager::runGame(vector<Aphid> aphidVector, vector<Ladybug> ladyVector,
		Configuration initialConfig, int gridLength, int gridHeight) {

	while (true) {
		for (vector<Aphid>::iterator aphIt = aphidVector.begin();
				aphIt != aphidVector.end(); ++aphIt) {
			if (myMath.FinaliseProbability(initialConfig.getAphidMoveConf())) {
				(*aphIt).Move(initialConfig, gridLength, gridHeight, (*aphIt));
			} else {
			}
		}
		Grid newGrid;
		newGrid.create(aphidVector, ladyVector);
		this_thread::sleep_for(chrono::milliseconds(2000));
		//cin >> end;
	}
}


