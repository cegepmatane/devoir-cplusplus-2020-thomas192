/*
 * Medecin.h
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#ifndef MEDECIN_H_
#define MEDECIN_H_
#include"Role.h"

class Medecin :public Role {
public:
	Medecin(string);
	virtual ~Medecin();
	Medecin(const Medecin &other);
	string exporter();

};

#endif /* MEDECIN_H_ */
