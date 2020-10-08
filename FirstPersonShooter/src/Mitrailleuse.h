/*
 * Mitrailleuse.h
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#ifndef MITRAILLEUSE_H_
#define MITRAILLEUSE_H_
#include "Arme.h"

class Mitrailleuse :public Arme {
public:
	Mitrailleuse(string);
	virtual ~Mitrailleuse();
	Mitrailleuse(const Mitrailleuse &other);
	string exporter();
};

#endif /* MITRAILLEUSE_H_ */
