#include <iostream>
#include "Partie.h"
#include <string.h>
#ifdef __linux__
    #define CLOSE "clear"
    #include <stdlib.h>
#elif _WIN32
    #define CLOSE "cls"
#else

#endif

using namespace std;

Partie::Partie() {
	joueur = NULL;
	plat = new Plateau();
  s=new Sauvegarde();
}

Partie::~Partie(){
  delete plat;
  delete s;
}

void Partie::inscriptionJoueurs() {
	char j1[50];
	char j2[50];
		cout << "Entrez le nom du joueur 1 : " << endl;
		cin >> j1;
		cout << "Entrez le nom du joueur 2 : " << endl;
		cin >> j2;
	joueur = new Joueur[2];
	joueur[0].setNom(j1);
	joueur[1].setNom(j2);
  s->initialiserPartie(j1,j2);
}

void Partie::afficher() {
	system(CLOSE);
	cout << "j1 : ";
	joueur[0].afficher();
	cout << endl << "j2 : ";
	joueur[1].afficher();
	plat->afficher();
}

int Partie::demarrerPartie() {
	afficher();
	int sortie;
	while (true) {
		for (int i = 1; i < 3; i++) {
			plat->jouerCoup(i,s);
			afficher();
			sortie = plat->isfini();
			if (sortie != -1) {
				plat->reinitialiser();
				return sortie;
			}
		}
	}
}

void Partie::fin(int score) {
  s->finPartie(score);
	switch (score) {
	case 0:
		cout << "Match nul" << endl;
		break;
	case 1:
		cout << "Victoire du joueur 1!" << endl;
		break;
	case 2:
		cout << "Victoire du joueur 2!" << endl;
		break;
	}
}

void Partie::Menu() {
	char choix[100];
  bool b=true;
	while (b) {
		cout << "1 - Demarrer une nouvelle partie" << endl;
		cout << "2 - Visionner une ancienne partie" << endl;
		cin >> choix;

		switch (choix[0]) {
		case '1':
			inscriptionJoueurs();
			fin(demarrerPartie());
      b=false;
			break;
		case '2':
      menuRedif();
      b=false;
			break;
		default:
			system(CLOSE);
			break;
		}
	}
}

void Partie::menuRedif(){
  int choix;
  for(int i(0);i < s->getNbParties();++i){
    cout<<i<<" - Partie n°"<<i+1<<endl;
  }
  cin>>choix;
  rejouerPartie(choix);
}

void Partie::rejouerPartie(int choix){
  char partie[200];
  s->getPartie(choix, partie);
  cout<<partie<<endl;
  int nbcoups=(strlen(partie)-1)/7;
  cout<<nbcoups<<endl;
  int **tabCoups=new int*[nbcoups];
  for (int i = 0; i < nbcoups; i++) {
    tabCoups[i]=new int[3];
  }
  for(int i(0);i<nbcoups;++i){
    tabCoups[i][0]=partie[1+(7*i)]-'0';
    tabCoups[i][1]=partie[3+(7*i)]-'0';
    tabCoups[i][2]=partie[5+(7*i)]-'0';
  }
  char j1[100], j2[100];
  s->getJoueurs(choix,j1,j2);
  joueur=new Joueur[2];
  joueur[0].setNom(j1);
  joueur[1].setNom(j2);
  afficher();
  cout << "ENTRER pour avoir le coup suivant...";
  if (cin.get() == '\n'){
  }
  for(int i(0);i<nbcoups;++i){
    plat->poseJeton(tabCoups[i][1], tabCoups[i][2], tabCoups[i][0]);
    afficher();
    cout << "ENTRER pour avoir le coup suivant...";
    if (cin.get() == '\n'){
    }
  }
}

void Partie::continuer(bool& b) {
	char reponse[100];
	while (true) {
		cout << "Voulez vous continuer o/n" << endl;
		cin >> reponse;
		switch (reponse[0]) {
		case 'o':
			b = true;
			return;
			break;
		case 'n':
			b = false;
			return;
			break;
		case 'O':
			b = true;
			return;
			break;
		case 'N':
			b = false;
			return;
			break;

		}
	}
}
