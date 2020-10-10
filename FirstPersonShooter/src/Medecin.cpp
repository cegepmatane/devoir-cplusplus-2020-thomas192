/*
 * Medecin.cpp
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#include "Medecin.h"
#include "Mitraillette.h"
#include <sstream>

Medecin::Medecin(string nom) {
	this->nom=nom;
	this->vie=80;
	this->vitesse=1.2;
	this->arme=new Mitraillette("P90");
}

Medecin::Medecin(const Medecin &other) {}

Medecin::~Medecin() {}

string Medecin::exporter() {
	stringstream xml;
	xml << "<Medecin>" << endl;
	xml << "<nom>" << this->nom << "</nom>" << endl;
	xml << "<vie>" << this->vie << "</vie>" << endl;
	xml << "<vitesse>" << this->vitesse << "</vitesse>" << endl;
	xml << this->arme->exporter();
	xml << "</Medecin>" << endl;
	return xml.str();
}

ostream& Medecin::afficher(ostream& sortie) const {
	sortie << "<Medecin>" << endl;
	sortie << "<nom>" << this->nom << "</nom>" << endl;
	sortie << "<vie>" << this->vie << "</vie>" << endl;
	sortie << "<vitesse>" << this->vitesse << "</vitesse>" << endl;
	sortie << *this->arme;
	sortie << "</Medecin>" << endl;
	return sortie;
}
