#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

using namespace std;

class Player{
  private:
  public:
  string name;

	int cart; //la capacité du joueur.

	int gold; //le nombre de pièces d’or.
	int ruby; //le nombre de rubis.
	int spice; //le nombre de sacs d’épices.
	int fabric; //le nombre de rouleaux de tissus.
	int jewel; //le nombre de bijoux.

	int food; //le nombre de nourritures.

	Player();
	Player(string _name);
	Player(const Player& other);

	// retourne vrai si food > 0
	bool canAct() const;
	// donne une pièce d’or à un autre joueur
	bool pay( Player& player );
	// reduit le nombre de nourritures de 1 si food > 0
	void eat();
	// nombre de resources de libres
	int getNumFreeResources() const;
};

ostream& operator<<(ostream &out, const Player& player);

#endif //PLAYER_H
