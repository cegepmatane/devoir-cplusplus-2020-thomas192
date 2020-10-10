/*
 * Mitraillette.cpp
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#include "Mitraillette.h"
#include <sstream>

Mitraillette::Mitraillette(string nom) {
	this->nom=nom;
	this->degat=12;
	this->portee=50;
	this->cadence=11;
}

Mitraillette::Mitraillette(const Mitraillette &other) {}

Mitraillette::~Mitraillette() {}

string Mitraillette::exporter() {
	stringstream xml;
	xml << "<Mitraillette>" << endl;
	xml << "<nom>" << this->nom << "</nom>" << endl;
	xml << "<degat>" << this->degat << "</degat>" << endl;
	xml << "<portee>" << this->portee << "</portee>" << endl;
	xml << "<cadence>" << this->cadence << "</cadence>" << endl;
	xml << "</Mitraillette>" << endl;
	return xml.str();
}

ostream& Mitraillette::afficher(ostream& sortie) const {
	sortie << "<Mitraillette>" << endl;
	sortie << "<nom>" << this->nom << "</nom>" << endl;
	sortie << "<degat>" << this->degat << "</degat>" << endl;
	sortie << "<portee>" << this->portee << "</portee>" << endl;
	sortie << "<cadence>" << this->cadence << "</cadence>" << endl;
	sortie << "</Mitraillette>" << endl;
	return sortie;
}

