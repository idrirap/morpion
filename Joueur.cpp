#include <iostream>
#include "Partie.h"

using namespace std;

Joueur::Joueur() {
	nom = NULL;
	nbPartieGagnees = 0;
	nbPartiesJouees = 0;
}

void Joueur::setNom(char*c) {
	nom = new char[50];
	int cpt = 0;
	for (int i = 0; i < 50; i++) {
		if (c[i] >= 'a' && c[i] <= 'z' || c[i] >= 'A' && c[i] <= 'Z' || c[i] >= '0' && c[i] <= '9' || c[i]=='\0') {
			nom[cpt] = c[i];
			cpt++;
		}
	}
}

void Joueur::aGagne() {
	++nbPartieGagnees;
}

void Joueur::aJoue() {
	++nbPartiesJouees;
}

void Joueur::afficher() {
	cout << nom <<" Partie(s) gagnee(s) : "<<nbPartieGagnees<<" sur "<<nbPartiesJouees<<" parties jouees"<< endl;
}