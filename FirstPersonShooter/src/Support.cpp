/*
 * Support.cpp
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#include "Support.h"
#include "Mitrailleuse.h"
#include <sstream>

Support::Support(string nom) {
	this->nom=nom;
	this->vie=120;
	this->vitesse=0.8;
	this->arme=new Mitrailleuse("M249");
}

Support::Support(const Support &other) {}

Support::~Support() {}

string Support::exporter() {
	stringstream xml;
	xml << "<Support>" << endl;
	xml << "<nom>" << this->nom << "</nom>" << endl;
	xml << "<vie>" << this->vie << "</vie>" << endl;
	xml << "<vitesse>" << this->vitesse << "</vitesse>" << endl;
	xml << this->arme->exporter();
	xml << "</Support>" << endl;
	return xml.str();
}

ostream& Support::afficher(ostream& sortie) const {
	sortie << "<Support>" << endl;
	sortie << "<nom>" << this->nom << "</nom>" << endl;
	sortie << "<vie>" << this->vie << "</vie>" << endl;
	sortie << "<vitesse>" << this->vitesse << "</vitesse>" << endl;
	sortie << *this->arme;
	sortie << "</Support>" << endl;
	return sortie;
}

