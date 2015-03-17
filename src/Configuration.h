/*
 * Configuration.h
 *
 *  Created on: 17 Mar 2015
 *      Author: chris
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

namespace std {

class Configuration {
protected:
	float aphidMoveConf, aphidKillConf, aphIncKillConf,
			aphidReproConf, ladyMoveConf, ladyDirConf,
			ladyKillConf, ladyReproConf;
public:
	Configuration();
	virtual ~Configuration();
	float getAphidMoveConf();
	void setAphidMoveConf(float newValue);
	float getAphidKillConf();
	void setAphidKillConf(float newValue);
	float getAphIncKillConf();
	void setAphIncKillConf(float newValue);
	float getAphidReproConf();
	void setAphidReproConf(float newValue);

	float getLadyMoveConf();
	void setLadyMoveConf(float newValue);
	float getLadyDirConf();
	void setLadyDirConf(float newValue);
	float getLadyKillConf();
	void setLadyKillConf(float newValue);
	float getLadyReproConf();
	void setLadyReproConf(float newValue);
};

} /* namespace std */

#endif /* CONFIGURATION_H_ */
