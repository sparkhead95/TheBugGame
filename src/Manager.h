/*
 * Manager.h
 *
 *  Created on: 10 Mar 2015
 *      Author: chris
 */

#pragma once

#ifndef MANAGER_H
#define MANAGER_H

class Manager {
protected:
	int gridLength, gridHeight, aphidNum, ladyNum, tempX, tempY;
public:
	Manager();
	void runPreReqs();
	void runGame();
};



#endif /* MANAGER_H_ */
