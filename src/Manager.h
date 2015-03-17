/*
 * Manager.h
 *
 *  Created on: 10 Mar 2015
 *      Author: chris
 */

#pragma once

#ifndef MANAGER_H
#define MANAGER_H
#include "Animal.h"
#include <vector>
#include "Configuration.h"

class Manager {

protected:
	int gridLength, gridHeight, aphidNum, ladyNum, tempX, tempY;

public:
	Manager();
	void runPreReqs();
	void runGame(vector<Aphid> aphidVector, vector<Ladybug> ladyVector, Configuration initialConfig, int gridLength, int gridHeight);
	bool finaliseProbability(float unfinalisedProbability);
};



#endif /* MANAGER_H_ */
