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
	return "";
}

ostream& operator<<(ostream& sortie, const Role& role) {
	return role.afficher(sortie);
}

ostream& Role::afficher(ostream& sortie) const {
	return sortie;
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
