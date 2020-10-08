/*
 * Assault.cpp
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#include "Assault.h"
#include "FusilAssault.h"
#include <sstream>

Assault::Assault(string nom) {
	this->nom=nom;
	this->vie=100;
	this->vitesse=1;
	this->arme=new FusilAssault("FAMAS");
}

Assault::Assault(const Assault &other) {}

Assault::~Assault() {}

string Assault::exporter() {
	stringstream xml;
	xml << "<Assault>" << endl;
	xml << "<nom>" << this->nom << "</nom>" << endl;
	xml << "<vie>" << this->vie << "</vie>" << endl;
	xml << "<vitesse>" << this->vitesse << "</vitesse>" << endl;
	xml << this->arme->exporter();
	xml << "</Assault>" << endl;
	return xml.str();
}

ostream& operator<<(ostream& sortie, const Assault& assault) {
	sortie << "<Assault>" << endl;
	sortie << "<nom>" << assault.nom << "</nom>" << endl;
	sortie << "<vie>" << assault.vie << "</vie>" << endl;
	sortie << "<vitesse>" << assault.vitesse << "</vitesse>" << endl;
	sortie << assault.arme->exporter();
	sortie << "</Assault>" << endl;
	return sortie;
}
