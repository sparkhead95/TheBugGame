/*
 * Interact.h
 *
 *  Created on: 19 Mar 2015
 *      Author: chris
 */

#ifndef INTERACT_H_
#define INTERACT_H_

#include "Configuration.h"
#include "Grid.h"

namespace std {

class Interact {
public:
	Interact();
	void reproduce(Configuration thisConfig, Grid thisGrid);
	virtual ~Interact();
};

} /* namespace std */

#endif /* INTERACT_H_ */
