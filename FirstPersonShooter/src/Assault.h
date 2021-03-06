/*
 * Assault.h
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#ifndef ASSAULT_H_
#define ASSAULT_H_
#include "Role.h"

class Assault :public Role {
public:
	Assault(string);
	virtual ~Assault();
	Assault(const Assault &other);
	string exporter();
	ostream& afficher(ostream&) const;
};

#endif /* ASSAULT_H_ */
