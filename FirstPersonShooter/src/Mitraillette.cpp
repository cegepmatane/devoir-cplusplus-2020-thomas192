/*
 * Mitraillette.cpp
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#include "Mitraillette.h"

Mitraillette::Mitraillette(string nom) {
	this->nom=nom;
	this->degat=12;
	this->portee=50;
	this->cadence=11;
}

Mitraillette::Mitraillette(const Mitraillette &other) {}

Mitraillette::~Mitraillette() {}

string Mitraillette::exporter() {

}

