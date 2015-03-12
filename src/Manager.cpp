/*
 * Manager.cpp
 *
 *  Created on: 10 Mar 2015
 *      Author: chris
 */

#include <fstream>
#include <iostream>
#include "Manager.h"
using namespace std;

int gridLength, gridHeight;

	Manager::Manager(){

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
			cout<<"File opened.\n";
			gridConfig>>gridLength;
			gridConfig>>gridHeight;

		}
		else if ((gridConfig.is_open()) == false) {
			cout << "Could not locate/open file.\n";
		}
		gridConfig.close();

	}
