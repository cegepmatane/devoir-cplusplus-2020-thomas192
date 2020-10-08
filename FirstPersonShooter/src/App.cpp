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
	//Role role;
	//cout << "Role : " << role.exporter() << endl;

	//Role role1("Role1");
	//cout << "Role1 : " << role1.exporter() << endl;

	//Role* role2;
	//role2 = new Role("Role2");
	//cout << "Role2 : " << role2->exporter() << endl;

	//Assault assault;
	//cout << "Assault : " << assault.exporter() << endl;

	//Role* assault;
	//assault = new Assault("Rex");
	//cout << "Assault : " << assault->exporter() << endl;


	//Role* medecin;
	//medecin = new Medecin("Bob");
	//cout << "Medecin : " << medecin->exporter() << endl;

	Role* support;
	support = new Support("Max");
	cout << "Support : " << support->exporter() << endl;


	return 0;
}
