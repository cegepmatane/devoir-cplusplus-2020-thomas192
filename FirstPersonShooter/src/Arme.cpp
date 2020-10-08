/*
 * Arme.cpp
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#include "Arme.h"
#include <sstream>

Arme::Arme() {}

Arme::Arme(const Arme &other) {}

Arme::~Arme() {}

string Arme::exporter() {
	stringstream xml;
	xml << "<Arme>" << endl;
	xml << "<nom>" << this->nom << "</nom>" << endl;
	xml << "<degat>" << this->degat << "</degat>" << endl;
	xml << "<portee>" << this->portee << "</portee>" << endl;
	xml << "<cadence>" << this->cadence << "</cadence>" << endl;
	xml << "</Arme>" << endl;
	return xml.str();
}


int Arme::getDegat() const {
	return degat;
}

void Arme::setDegat(int degat) {
	this->degat = degat;
}

const string& Arme::getNom() const {
	return nom;
}

void Arme::setNom(const string &nom) {
	this->nom = nom;
}

int Arme::getPortee() const {
	return portee;
}

void Arme::setPortee(int portee) {
	this->portee = portee;
}
