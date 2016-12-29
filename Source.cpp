#include <iostream>
#include "Jeton.h"
#include "Partie.h"

using namespace std;

int main() {
	Partie* p=NULL;
	bool continuer = true;
	while (continuer) {
		p = new Partie();
		p->Menu();
		p->continuer(continuer);
	}
	return 0;
}
