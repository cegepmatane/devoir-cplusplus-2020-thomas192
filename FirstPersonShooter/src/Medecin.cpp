/*
 * Medecin.cpp
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#include "Medecin.h"

Medecin::Medecin() {
	this->vie=90;
	this->vitesse=1.1;
}

Medecin::Medecin(const Medecin &other) {}

Medecin::~Medecin() {}

string Medecin::exporter() {
	return "<Medecin></Medecin>";
}

