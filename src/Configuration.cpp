/*
 * Configuration.cpp
 *
 *  Created on: 17 Mar 2015
 *      Author: chris
 */
#include <stdlib.h>
#include "Configuration.h"
#include <string>
#include <iostream>

namespace std {

Configuration::Configuration() {
	aphidMoveConf = 0, aphidKillConf = 0, aphIncKillConf = 0, aphidReproConf =
			0, ladyMoveConf = 0, ladyDirConf = 0, ladyKillConf = 0, ladyReproConf =
			0;

}

Configuration::~Configuration() {
	//cout << "Config destroyed." << endl;
}

// ================= Aphid config =======================

float Configuration::getAphidMoveConf() {
	return aphidMoveConf;
}
void Configuration::setAphidMoveConf(float newValue) {
	aphidMoveConf = newValue;
}
float Configuration::getAphidKillConf() {
	return aphidKillConf;
}
void Configuration::setAphidKillConf(float newValue) {
	aphidKillConf = newValue;
}
float Configuration::getAphIncKillConf() {
	return aphIncKillConf;
}
void Configuration::setAphIncKillConf(float newValue) {
	aphIncKillConf = newValue;
}
float Configuration::getAphidReproConf() {
	return aphidReproConf;
}
void Configuration::setAphidReproConf(float newValue) {
	aphidReproConf = newValue;
}

// ================= Ladybug config ======================

float Configuration::getLadyMoveConf() {
	return this->ladyMoveConf;
}
void Configuration::setLadyMoveConf(float newValue) {
	this->ladyMoveConf = newValue;
}
float Configuration::getLadyDirConf() {
	return this->ladyDirConf;
}
void Configuration::setLadyDirConf(float newValue) {
	this->ladyDirConf = newValue;
}
float Configuration::getLadyKillConf() {
	return this->ladyKillConf;
}
void Configuration::setLadyKillConf(float newValue) {
	this->ladyKillConf = newValue;
}
float Configuration::getLadyReproConf() {
	return this->ladyReproConf;
}
void Configuration::setLadyReproConf(float newValue) {
	this->ladyReproConf = newValue;
}

} /* namespace std */
