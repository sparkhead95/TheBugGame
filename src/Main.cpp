/*
sd * Main.cpp
 *
 *  Created on: 10 Mar 2015
 *      Author: chris
 */

#include "Manager.h"
#include "Main.h"

#include <iostream>
using namespace std;

int main(){
	Main();
	return 0;
}


Main::Main() {
	cout << "Welcome to the Aphids and Ladybugs program!" << endl;
	cin.get();
	Manager manager;


	manager.runPreReqs();
	// Manager.rungame (draws the grid, places the aphids/ladybugs)


}

Main::~Main() {
	cout << "Destructor called. Goodbye!" << endl;
}

