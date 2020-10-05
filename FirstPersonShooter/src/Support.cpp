/*
 * Support.cpp
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#include "Support.h"

Support::Support() {
	this->vie=120;
	this->vitesse=0.8;
}

Support::Support(const Support &other) {}

Support::~Support() {}

string Support::exporter() {
	return "<Support></Support>";
}

