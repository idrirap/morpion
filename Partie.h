#pragma once

class Sauvegarde {
private:
	char* nomFichier;
	int nbParties;
public:
	Sauvegarde();
	~Sauvegarde();
	void initialiserPartie(char*joueur1, char*joueur2);
	void ajouterCoup(int x, int y, int Joueur);
	void finPartie(int Victorieux);
	int getNbParties();
	void getPartie(int partie, char*c);
	void getJoueurs(int partie, char*j1, char*j2);
};

class Joueur {
private:
	char*nom;
	int nbPartiesJouees;
	int nbPartieGagnees;
public:
	Joueur();
	void aJoue();
	void aGagne();
	void setNom(char*);
	void afficher();
};

class Jeton {
private:
	int value;
public:
	Jeton();
	void setJeton(int val);
	void afficher();
	int getJeton();
};

class Plateau {
private:
	Jeton**tab;
public:
	Plateau();
	~Plateau();
	void afficher();
	int isfini();
	void jouerCoup(int joueur, Sauvegarde *s);
	bool isEmpty(int x, int y);
	void reinitialiser();
	void poseJeton(int x, int y, int joueur);
};

class Partie {
private :
	int numTour;
	Joueur *joueur;
	Plateau *plat;
	Sauvegarde *s;
public:
	Partie();
	~Partie();
	void menuRedif();
	void rejouerPartie(int numero);
	void inscriptionJoueurs();
	void afficher();
	int demarrerPartie();
	void fin(int score);
	void Menu();
	void continuer(bool& b);
};
