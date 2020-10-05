/*
 * Support.cpp
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#include "Support.h"
#include <sstream>

Support::Support(string nom) {
	this->nom=nom;
	this->vie=120;
	this->vitesse=0.8;
}

Support::Support(const Support &other) {}

Support::~Support() {}

string Support::exporter() {
	stringstream xml;

	xml << "<nom>" << this->nom << "</nom>" << endl;
	xml << "<vie>" << this->vie << "</vie>" << endl;
	xml << "<vitesse>" << this->vitesse << "</vitesse>" << endl;
	xml << this->arme->exporter();
	xml << "<Support>" << xml.str() << "</Support>";

	return xml.str();
}

