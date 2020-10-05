/*
 * Mitraillette.h
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#ifndef MITRAILLETTE_H_
#define MITRAILLETTE_H_
#include "Arme.h"

class Mitraillette :public Arme {
public:
	Mitraillette(string);
	virtual ~Mitraillette();
	Mitraillette(const Mitraillette &other);
	string exporter();
};

#endif /* MITRAILLETTE_H_ */
