/*
 * FusilAssault.h
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#ifndef FUSILASSAULT_H_
#define FUSILASSAULT_H_
#include "Arme.h"

class FusilAssault :public Arme {
public:
	FusilAssault(string);
	virtual ~FusilAssault();
	FusilAssault(const FusilAssault &other);
	string exporter();
	ostream& afficher(ostream&) const;
};

#endif /* FUSILASSAULT_H_ */
