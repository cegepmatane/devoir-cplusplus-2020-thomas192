/*
 * Mitrailleuse.cpp
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#include "Mitrailleuse.h"
#include <sstream>

Mitrailleuse::Mitrailleuse(string nom) {
	this->nom=nom;
	this->degat=30;
	this->portee=300;
	this->cadence=9;
}

Mitrailleuse::Mitrailleuse(const Mitrailleuse &other){}

Mitrailleuse::~Mitrailleuse() {}

string Mitrailleuse::exporter() {
	stringstream xml;
	xml << "<Mitrailleuse>" << endl;
	xml << "<nom>" << this->nom << "</nom>" << endl;
	xml << "<degat>" << this->degat << "</degat>" << endl;
	xml << "<portee>" << this->portee << "</portee>" << endl;
	xml << "<cadence>" << this->cadence << "</cadence>" << endl;
	xml << "</Mitrailleuse>" << endl;
	return xml.str();
}

