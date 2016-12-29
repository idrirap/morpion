#include <iostream>
#include <fstream>
#include "Partie.h"
#include <string.h>
#include <string>

using namespace std;

Sauvegarde::Sauvegarde(){
  nomFichier=new char[10];
  strcpy(nomFichier, "save.txt");
  int compteur=0;
  string ligne;
  ifstream fichier;
  fichier.open(nomFichier);
  while(getline(fichier,ligne)){
    if(ligne[0]=='<'){
      ++compteur;
    }
  }
  fichier.close();
  nbParties=compteur;
}

Sauvegarde::~Sauvegarde(){
  delete nomFichier;
}

void Sauvegarde::ajouterCoup(int x, int y, int joueur){
  char coup[8];
  strcpy(coup, "[X:X;X]");
  coup[1]='0'+joueur;
  coup[3]='0'+x;
  coup[5]='0'+y;
  ofstream fichier;
  fichier.open(nomFichier, ios::out | ios::app | ios::binary);
  fichier<<coup;
  fichier.close();
}

void Sauvegarde::initialiserPartie(char* Joueur1, char* Joueur2){
  char balise1[10];
  char balise2[200];
  strcpy(balise1, "<Partie");
  strcpy(balise2, " type=\"save\"|nom1=\"");
  strcat(balise2, Joueur1);
  strcat(balise2,"\"|nom2=\"");
  strcat(balise2, Joueur2);
  strcat(balise2,"\">\n");
  ofstream fichier;
  fichier.open(nomFichier, ios::out | ios::app | ios::binary);
  fichier<<balise1<<nbParties<<balise2;
  fichier.close();
  nbParties++;
}

void Sauvegarde::finPartie(int Victorieux){
  ofstream fichier;
  fichier.open(nomFichier, ios::out | ios::app | ios::binary);
  fichier<<Victorieux<<"\n";
  fichier.close();
}

int Sauvegarde::getNbParties(){
  return nbParties;
}

void Sauvegarde::getPartie(int partie, char*c){
  if(partie>=0 && partie<nbParties){
    int compteur=0;
    string ligne;
    ifstream fichier;
    fichier.open(nomFichier);
    getline(fichier,ligne);
    while(compteur<partie){
      if(ligne[0]=='<'){
        ++compteur;
      }
      getline(fichier,ligne);
    }
    if(partie==0){
      getline(fichier,ligne);
    }
    fichier.close();
    strcpy(c, ligne.c_str());
  }
}

void Sauvegarde::getJoueurs(int partie, char*j1, char*j2){
  if(partie>=0 && partie<nbParties){
    int compteur=0;
    string ligne;
    ifstream fichier;
    fichier.open(nomFichier);
    getline(fichier,ligne);
    while(compteur<partie){
      getline(fichier,ligne);
      if(ligne[0]=='<'){
        ++compteur;
      }
    }
    fichier.close();
    string jr1, jr2;
    for(int i(0);i<ligne.size();++i){
      if(ligne[i-3]=='1' && ligne[i-2]=='=' && ligne[i-1]=='"'){
        while(ligne[i]!='"'){
          jr1+=ligne[i];
          ++i;
        }
      }
      if(ligne[i-3]=='2' && ligne[i-2]=='=' && ligne[i-1]=='"'){
        while(ligne[i]!='"'){
          jr2+=ligne[i];
          ++i;
        }
      }
    }
    strcpy(j1, jr1.c_str());
    strcpy(j2, jr2.c_str());
  }
}
