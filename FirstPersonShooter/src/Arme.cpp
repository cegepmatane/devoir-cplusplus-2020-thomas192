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
	return "";
}

ostream& operator<<(ostream& sortie, const Arme& arme) {
	return arme.afficher(sortie);
}

ostream& Arme::afficher(ostream& sortie) const {
	return sortie;
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
