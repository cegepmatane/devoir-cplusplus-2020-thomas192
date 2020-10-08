/*
 * Medecin.cpp
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#include "Medecin.h"
#include <sstream>

Medecin::Medecin(string nom) {
	this->nom=nom;
	this->vie=80;
	this->vitesse=1.2;
}

Medecin::Medecin(const Medecin &other) {}

Medecin::~Medecin() {}

string Medecin::exporter() {
	stringstream xml;
	xml << "<medecin>" << endl;
	xml << "<nom>" << this->nom << "</nom>" << endl;
	xml << "<vie>" << this->vie << "</vie>" << endl;
	xml << "<vitesse>" << this->vitesse << "</vitesse>" << endl;
	xml << this->arme->exporter();
	xml << "</medecin>" << endl;

	return xml.str();
}

