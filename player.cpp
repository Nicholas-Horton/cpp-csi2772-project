#include "player.h"

Player::Player(){
	cart = 9;

	gold = 5;
	ruby = 0;
	spice = 1;
	fabric = 1;
	jewel = 1;

	food = 10;
}

// retourne vrai si food > 0
bool Player::canAct() const{
	return food > 0;
}

// donne une pièce d’or à un autre joueur
bool Player::pay( Player& player ){
	if (gold > 0){
		gold--;
		player.gold++;
		return true;
	}
	else{
		return false;
	}
}

// reduit le nombre de nourritures de 1 si food > 0
void Player::eat(){
	if (food > 0){
		food--;
	}
}
