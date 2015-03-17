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
	Manager manager;

	manager.runPreReqs();
}

Main::~Main() {
	cout << endl << "Goodbye!" << endl;
}

