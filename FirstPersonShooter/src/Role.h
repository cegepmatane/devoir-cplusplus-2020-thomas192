/*
 * Role.h
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#ifndef ROLE_H_
#define ROLE_H_
#include <iostream>
using namespace std;
#include "Arme.h"

class Role {
	
protected:
	string nom;
	int vie;
	float vitesse;
	Arme* arme;

public:
	Role();
	virtual ~Role();
	Role (const Role &other);
	const string& getNom() const;
	void setNom(const string &nom);
	int getVie() const;
	void setVie(int vie);
	float getVitesse() const;
	void setVitesse(float vitesse);
	virtual string exporter();
	friend ostream& operator<<(ostream&, const Role&);
	virtual ostream& afficher(ostream&) const;
};

#endif /* ROLE_H_ */
