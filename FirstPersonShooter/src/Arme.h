/*
 * Arme.h
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#ifndef ARME_H_
#define ARME_H_
#include <iostream>
using namespace std;

class Arme {

protected :
	string nom;
	int degat;
	int portee;
	float cadence;

public:
	Arme();
	virtual ~Arme();
	Arme (const Arme &other);
	int getDegat() const;
	void setDegat(int degat);
	const string& getNom() const;
	void setNom(const string &nom);
	int getPortee() const;
	void setPortee(int portee);
	virtual string exporter();
	friend ostream& operator<<(ostream&, const Arme&);
	virtual ostream& afficher(ostream&) const;
};

#endif /* ARME_H_ */
