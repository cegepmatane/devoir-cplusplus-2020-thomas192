/*
 * Assault.cpp
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#include "Assault.h"

Assault::Assault() {
	this->vie=100;
	this->vitesse=1;
}

Assault::Assault(const Assault &other) {}

Assault::~Assault() {}

string Assault::exporter() {
	return "<Assault></Assault>";
}


