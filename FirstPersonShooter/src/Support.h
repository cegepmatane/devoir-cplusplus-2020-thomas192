/*
 * Support.h
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#ifndef SUPPORT_H_
#define SUPPORT_H_

#include"Role.h"

class Support :public Role {
public:
	Support(string);
	virtual ~Support();
	Support(const Support &other);
	string exporter();
	ostream& afficher(ostream&) const;
};

#endif /* SUPPORT_H_ */
