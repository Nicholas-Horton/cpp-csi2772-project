#include "player.h"

Player::Player(){
	name = "NO_NAME";

	cart = 9;

	gold = 5;
	ruby = 0;
	spice = 1;
	fabric = 1;
	jewel = 1;

	food = 10;
}

Player::Player(string _name){
	name = _name;

	cart = 9;

	gold = 5;
	ruby = 0;
	spice = 1;
	fabric = 1;
	jewel = 1;

	food = 10;
}

Player::Player(const Player& other){
	name = other.name;

	cart = other.cart;

	gold = other.gold;
	ruby = other.ruby;
	spice = other.spice;
	fabric = other.fabric;
	jewel = other.jewel;

	food = other.food;
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

int Player::getNumFreeResources() const {
	return cart - (ruby + spice + fabric + jewel);
}

ostream& operator<<(ostream &out, const Player& player){
	out << "=== Player " << player.name << " ===" << endl;
	out << "gold   = " << player.gold << endl;
	out << "ruby   = " << player.ruby << endl;
	out << "spice  = " << player.spice << endl;
	out << "fabric = " << player.fabric << endl;
	out << "jewel  = " << player.jewel << endl;
	out << "food   = " << player.food << endl;
	out << "You have " << player.getNumFreeResources() << " free inventory slots remaining." << endl;

	return out;
}

