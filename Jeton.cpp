#include "Partie.h"
#include <iostream>

Jeton::Jeton() {
	value = 0;
}


void Jeton::setJeton(int val) {
	value = val;
}

void Jeton::afficher() {
	switch (value) {
	case 0:
		std::cout << " ";
		break;
	case 1:
		std::cout << "X";
		break;
	case 2:
		std::cout << "O";
		break;
	}
}

int Jeton::getJeton() {
	return value;
}