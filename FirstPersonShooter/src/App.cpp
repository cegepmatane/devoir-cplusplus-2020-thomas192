//============================================================================
// Name        : FirstPersonShooter.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <ctime>

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
	string nomMonstre = "Kraken";
	int vieMonstre = 1200;
	int degatsMonstre = 30;
	//Assault assault("Rex");
	//cout << assault << endl;
	//cout << "Assault : " << assault.exporter() << endl;

	srand(time(NULL));

	vector<Role*> roles;
	vector<Role*>::iterator iterateur;

	Role* assault;
	assault = new Assault("Rex");
	roles.push_back(assault);
	//(*assault)--;
	//cout << *assault << endl;
	//cout << "Assault : " << assault->exporter() << endl;

	Role* medecin;
	medecin = new Medecin("Bob");
	roles.push_back(medecin);
	//cout << *medecin << endl;
	//cout << "Medecin : " << medecin->exporter() << endl;

	Role* support;
	support = new Support("Max");
	roles.push_back(support);
	//cout << *support << endl;
	//cout << "Support : " << support->exporter() << endl;

	/* BOULCE DE JEU*/
	bool partie = true;
	int tour = 0;
	char touche;
	cout << "Vous affrontez le : " << nomMonstre << endl;
	cout << "A : attaquer le monstre" << endl;
	cout << "H : soigner votre équipe" << endl;
	while(partie) {

		cout << "Tour : " << tour++ << endl;

		cin >> touche;

		switch(touche) {

			// Attaquer
			case 'A':case 'a': {
				for(iterateur = roles.begin(); iterateur != roles.end(); iterateur++) {
					int tirs = rand()%8+1;
					vieMonstre-=(*iterateur)->getArme()->getDegat()*tirs;
					cout << (*iterateur)->getNom() << " inflige : " << (*iterateur)->getArme()->getDegat()*tirs
							<< " points de dégats au " << nomMonstre << " (" << vieMonstre << " PV)" << endl;
				}
				cout << "" << endl;
				if(vieMonstre <= 0) {
					cout << "Votre équipê a vaincu le " << nomMonstre << " !" << endl;
					partie = false;
				}
			}
				break;

			// Soigner
			case 'H':case 'h': {
				for(iterateur = roles.begin(); iterateur != roles.end(); iterateur++) {
					int gainDeVie = rand()%60+1;
					(*iterateur)->setVie((*iterateur)->getVie()+gainDeVie);
					cout << (*iterateur)->getNom() << " (" << (*iterateur)->getVie() << " PV)" << " gagne "
							<< gainDeVie << " point(s) de vie" << endl;
				}
				cout << "" << endl;
			}
				break;

			// Quitter
			case 'Q':case 'q':
				partie = false;
				cout << "Fin de la partie" << endl;
				break;

			default:
				cout << "Vous avez rater votre chance d'agir à ce tour" << endl;
				cout << "" << endl;
				break;
		}

		if(partie != false) {
			// Le monstre attaque
			for(iterateur = roles.begin(); iterateur != roles.end(); iterateur++) {
				if(rand()%5+1 == 1) {
					(*iterateur)->setVie((*iterateur)->getVie()-degatsMonstre*2);
					cout << "Le " << nomMonstre << " inflige un coup critique de " << degatsMonstre*2
							<< " points de dégats à " << (*iterateur)->getNom() << " (" << (*iterateur)->getVie()
							<< " PV)" << endl;
				} else {
				(*iterateur)->setVie((*iterateur)->getVie()-degatsMonstre);
				cout << "Le " << nomMonstre << " attaque " << (*iterateur)->getNom() << " (" << (*iterateur)->getVie()
						<< " PV)" << " et lui retire " << degatsMonstre << " points de vie "  << endl;
				}
			}
			cout << "" << endl;

			// Le monstre déclenche un tremblement de terre
			if(rand()%10+1 == 1) {
				int tremblements = rand()%20+1;
				cout << "Le " << nomMonstre << " frappe le sol et déclenche un tremblement de terre ..." << endl;
				cout << "- " << tremblements << " PV à tous les membres de votre équipe" << endl;
				for(iterateur = roles.begin(); iterateur != roles.end(); iterateur++) {
					(*iterateur)->setVie((*iterateur)->getVie()-tremblements);
					cout << (*iterateur)->getNom() << " (" << (*iterateur)->getVie() << " PV)" << endl;
				}
				cout << "" << endl;
			}

			// On retire les personnages morts de l'équipe
			iterateur = roles.begin();
			while(iterateur != roles.end()) {
				if((*iterateur)->getVie() <= 0) {
					cout << (*iterateur)->getNom() << " est mort pendant ce tour" << endl;
					cout << "" << endl;
					iterateur = roles.erase(iterateur);
				} else {
					iterateur++;
				}
			}
			if(roles.empty()) {
				cout << " Le " << nomMonstre << " (" << vieMonstre << "PV) a terrassé votre équipe" << endl;
				partie = false;
			}
		}
		//cout << *assault << endl;
	}

	return 0;
}
