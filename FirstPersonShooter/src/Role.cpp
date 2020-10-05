/*
 * Role.cpp
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#include "Role.h"

Role::Role() {}

Role::Role(string nom) {
	this->nom = nom;
}

Role::Role(const Role &other) {

}

Role::~Role() {
}

string Role::exporter() {
	return"<Role></Role>";
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
