/*
 * Assault.cpp
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#include "Assault.h"
#include <sstream>

Assault::Assault(string nom) {
	this->nom=nom;
	this->vie=100;
	this->vitesse=1;
	this->arme=new Arme("FAMAS", 33, 300, 5);
}

Assault::Assault(const Assault &other) {}

Assault::~Assault() {}

string Assault::exporter() {
	stringstream xml;
	xml << "<assault>" << endl;
	xml << "<nom>" << this->nom << "</nom>" << endl;
	xml << "<vie>" << this->vie << "</vie>" << endl;
	xml << "<vitesse>" << this->vitesse << "</vitesse>" << endl;
	xml << this->arme->exporter();
	xml << "</assault>" << endl;
	return xml.str();
}


