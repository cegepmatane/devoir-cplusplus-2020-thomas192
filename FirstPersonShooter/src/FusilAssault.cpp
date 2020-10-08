/*
 * FusilAssault.cpp
 *
 *  Created on: 5 Oct 2020
 *      Author: Thomas
 */

#include "FusilAssault.h"
#include <sstream>

FusilAssault::FusilAssault(string nom) {
	this->nom=nom;
	this->degat=27;
	this->portee=200;
	this->cadence=6;
}

FusilAssault::FusilAssault(const FusilAssault &other) {}

FusilAssault::~FusilAssault() {}

string FusilAssault::exporter() {
	stringstream xml;
	xml << "<FusilAssault>" << endl;
	xml << "<nom>" << this->nom << "</nom>" << endl;
	xml << "<degat>" << this->degat << "</degat>" << endl;
	xml << "<portee>" << this->portee << "</portee>" << endl;
	xml << "<cadence>" << this->cadence << "</cadence>" << endl;
	xml << "</FusilAssault>" << endl;
	return xml.str();
}

