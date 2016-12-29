#include <iostream>
#include "Partie.h"

using namespace std;

Plateau::Plateau() {
	reinitialiser();
}

Plateau::~Plateau() {
	for (int i = 0; i < 3; i++) {
		delete[]tab[i];
	}
	delete[]tab;
}

void Plateau::afficher() {
	cout << "  0 1 2 " << endl;
	for (int i = 0; i < 3; i++)	{
		cout << " +-+-+-+" << endl;
		cout << i;
		for (int j = 0; j < 3; j++)	{
			cout << "|";
			tab[i][j].afficher();
		}
		cout << "|" << endl;
	}
	cout << " +-+-+-+" << endl;
}

int Plateau::isfini() {
	//-1 pas fini, 0 egalit�, 1 victoire 1, 2 victoire 2

	for (int k = 1; k < 3; k++)	{
		for (int i = 0; i < 3; i++) {
			if (tab[i][0].getJeton() == k && tab[i][1].getJeton() == k && tab[i][2].getJeton() == k || tab[0][i].getJeton() == k && tab[1][i].getJeton() == k && tab[2][i].getJeton() == k) {
				return k;
			}
		}
	}
	for (int i = 1; i < 3; i++) {
		if (tab[0][0].getJeton() == i && tab[1][1].getJeton() == i && tab[2][2].getJeton() == i || tab[0][2].getJeton() == i && tab[1][1].getJeton() == i && tab[2][0].getJeton() == i) {
			return i;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tab[i][j].getJeton() == 0) {
				return -1;
			}
		}
	}
	return 0;
}

bool Plateau::isEmpty(int x, int y) {
	if (x >= 0 && x <= 2 && y >= 0 && y <= 2)
		return tab[y][x].getJeton() == 0;
	else
		return false;
}

int chartoint(char*c) {
	if (c[0] >= '0' && c[0] <= '9') {
		return c[0] - '0';
	}
	else
		return -1;
}

void Plateau::jouerCoup(int joueur, Sauvegarde *s) {
	cout << "Tour du joueur " << joueur <<endl;
	int x;
	int y;//ajoute la secu
	do {
		cout << "Entrez x : ";
		cin >> x;
		cout << "Entrez y : ";
		cin >> y;
		if (!isEmpty(x, y))
			cout << "Case deja pleine ou hors du tableau" << endl;
	} while (!isEmpty(x,y));
	tab[y][x].setJeton(joueur);
	s->ajouterCoup(x,y,joueur);
}

void Plateau::reinitialiser() {
	tab = new Jeton*[3];
	for (int i = 0; i < 3; i++) {
		tab[i] = new Jeton[3];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			tab[i][j].setJeton(0);
		}
	}
}

void Plateau::poseJeton(int x, int y, int joueur){
	if (!isEmpty(x, y)){
		cout << "Case deja pleine ou hors du tableau" << endl;
	}else{
		tab[y][x].setJeton(joueur);
	}
}
