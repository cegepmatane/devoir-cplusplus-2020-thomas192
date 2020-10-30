//============================================================================
// Name        : FirstPersonShooter.cpp
// Author      : Thomas Saudemont
// Version     :
// Copyright   : Your copyright notice
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <regex>

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
	int degatMonstre = 30;
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

			// Attaquer le monstre
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

			// Soigner l'équipe
			case 'H':case 'h': {
				for(iterateur = roles.begin(); iterateur != roles.end(); iterateur++) {
					int gainDeVie = rand()%80+1;
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
					(*iterateur)->setVie((*iterateur)->getVie()-degatMonstre*2);
					cout << "Le " << nomMonstre << " inflige un coup critique de " << degatMonstre*2
							<< " points de dégats à " << (*iterateur)->getNom() << " (" << (*iterateur)->getVie()
							<< " PV)" << endl;
				}else{
				(*iterateur)->setVie((*iterateur)->getVie()-degatMonstre);
				cout << "Le " << nomMonstre << " attaque " << (*iterateur)->getNom() << " (" << (*iterateur)->getVie()
						<< " PV)" << " et lui retire " << degatMonstre << " points de vie "  << endl;
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
				}else{
					iterateur++;
				}
			}
			if(roles.empty()) {
				cout << " Le " << nomMonstre << " (" << vieMonstre << "PV) a terrassé votre équipe" << endl;
				partie = false;
			}
		}
	}


	/* SAUVEGARDE DE LA PARTIE */
	string const fichierSauvegarde("jeu.txt");

	// Si le fichier existe déjà on supprime la dernière ligne
	ifstream fluxLecture(fichierSauvegarde.c_str());
	bool existe = true;
	if(!fluxLecture) {
		existe = false;
	}else{
		string ligne;
		string ligneASupprimer = "</jeu>";
		ofstream temp("temp.txt");
		while(getline(fluxLecture, ligne)) {
			ligne = regex_replace(ligne, regex(ligneASupprimer), "");
			temp << ligne << endl;
		}
		temp.close();
		fluxLecture.close();
		remove(fichierSauvegarde.c_str());
		rename("temp.txt", fichierSauvegarde.c_str());
	}

	//cout << existe << endl;

	// Ecriture des données
	ofstream flux(fichierSauvegarde.c_str(), ofstream::app | ofstream::out);
	time_t now = time(0);
	char* date = ctime(&now);
	if(flux) {
		if(!existe)
			flux << "<jeu>" << endl;

		// Sauvegarde des personnages si encore en vie
		flux << "<partie>" << endl;
		flux << "<date>" << date << "</date>" << endl;
		flux << "<tours>" << tour << "</tours>" << endl;
		if(!roles.empty()) {
			flux << "<equipe>" << endl;
			for(iterateur = roles.begin(); iterateur != roles.end(); iterateur++) {
				flux << (*iterateur)->exporter(); // Surcharge de "<<" ne fonctionne pas avec l'itérateur :(
			}
			flux << "</equipe>" << endl;
		}
		// Sauvegarde du monstre si encore en vie
		if(vieMonstre > 0) {
			flux << "<Monstre>" << endl;
			flux << "<nom>" << nomMonstre << "</nom>" << endl;
			flux << "<vie>" << vieMonstre << "</vie>" << endl;
			flux << "<degat>" << degatMonstre << "</degat>" << endl;
			flux << "</Monstre>" << endl;
		}
		flux << "</partie>" << endl;
		flux << "</jeu>";
	}else{
		cout << "ERREUR: Impossible d'ouvrir le fichier \"jeu.txt\"" << endl;
	}
	flux.close();
	// On libère la mémoire
	delete(assault);
	delete(medecin);
	delete(support);

	return 0;
}
