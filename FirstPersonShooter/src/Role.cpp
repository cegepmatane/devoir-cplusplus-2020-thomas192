/*
 * Role.cpp
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#include "Role.h"
#include <sstream>

Role::Role() {}

Role::Role(const Role &other) {}

Role::~Role() {}

string Role::exporter() {
	stringstream xml;
	xml << "<Assault>" << endl;
	xml << "<nom>" << this->nom << "</nom>" << endl;
	xml << "<vie>" << this->vie << "</vie>" << endl;
	xml << "<vitesse>" << this->vitesse << "</vitesse>" << endl;
	xml << this->arme->exporter();
	xml << "</Assault>" << endl;
	return xml.str();
}

ostream& operator<<(ostream& sortie, const Role& role) {
	return role.afficher(sortie);
}

ostream& Role::afficher(ostream& sortie) const {
	return sortie;
}

void Role::operator--(int) {
	this->vie--;
}

const string& Role::getNom() const {
	return nom;
}

void Role::setNom(const string &nom) {
	this->nom = nom;
}

int Role::getVie() const {
	return vie;
}

void Role::setVie(int vie) {
	this->vie = vie;
}

float Role::getVitesse() const {
	return vitesse;
}

void Role::setVitesse(float vitesse) {
	this->vitesse = vitesse;
}

Arme* Role::getArme() {
	return this->arme;
}
