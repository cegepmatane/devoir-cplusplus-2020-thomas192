//============================================================================
// Name        : FirstPersonShooter.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Role.h"
#include "Arme.h"
#include "Assault.h"
#include "Medecin.h"
#include "Support.h"
#include "FusilAssault.h"
#include "Mitraillette.h"
#include "Mitrailleuse.h"

int main() {
	//Assault assault("Rex");
	//cout << assault << endl;
	//cout << "Assault : " << assault.exporter() << endl;

	Role* assault;
	assault = new Assault("Rex");
	(*assault)--;
	cout << *assault << endl;
	//cout << "Assault : " << assault->exporter() << endl;

	//Role* medecin;
	//medecin = new Medecin("Bob");
	//cout << *medecin << endl;
	//cout << "Medecin : " << medecin->exporter() << endl;

	//Role* support;
	//support = new Support("Max");
	//cout << *support << endl;
	//cout << "Support : " << support->exporter() << endl;


	return 0;
}
