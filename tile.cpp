#include "tile.h"
#include <algorithm>
#include <stdlib.h>

Tile::Tile(){
}

bool Tile::operator==(const Tile &t){
	return false; //TODO: complete
}

bool Tile::action(Player& player){
	return true; //TODO: implement subclasses, revise implementation for tile
}

Tile* Tile::clone(){
	return new Tile(*this); //TODO: check if valid
}


bool RestaurantTile::action(Player& player){
	player.food = 10;
}
bool MarchandEpiceTile::action(Player& player){
	if(player.canAct() && player.gold >= 2) {
		player.eat();
		player.gold -= 2;
		player.spice += min(player.getNumFreeResources(), 3);
		return true;
	}
	return false;
}
bool MarchandTissusTile::action(Player& player){
	if(player.canAct() && player.gold >= 2) {
		player.eat();
		player.gold -= 2;
		player.fabric += min(player.getNumFreeResources(), 3);
		return true;
	}
	return false;
}
bool BijoutierTile::action(Player& player){
	if(player.canAct() && player.gold >= 2) {
		player.eat();
		player.gold -= 2;
		player.jewel += min(player.getNumFreeResources(), 3);
		return true;
	}
	return false;
}
bool FabriquantCharretteTile::action(Player& player){
	if(player.canAct() && player.gold >= 7) {
		player.eat();
		player.gold -= 7;
		player.cart += 3;
		return true;
	}
	return false;
}
bool PetitMarcheTile::action(Player& player){
	if(player.canAct() && player.fabric >= 1 && player.spice >= 1 && player.jewel >= 1) {
		player.eat();
		player.fabric -= 1;
		player.spice -= 1;
		player.jewel -= 1;
		player.gold += 8;
		return true;
	}
	return false;
}
bool MarcheEpicesTile::action(Player& player){
	if(player.canAct() && player.spice >= 3) {
		player.eat();
		player.spice -= 3;
		player.gold += 6;
		return true;
	}
	return false;
}
bool MarcheBijouxTile::action(Player& player){
	if(player.canAct() && player.jewel >= 3) {
		player.eat();
		player.jewel -= 3;
		player.gold += 6;
		return true;
	}
	return false;
}
bool MarcheTissusTile::action(Player& player){
	if(player.canAct() && player.fabric >= 3) {
		player.eat();
		player.fabric -= 3;
		player.gold += 6;
		return true;
	}
	return false;
}
bool MarcheNoirTile::action(Player& player){
	if(player.canAct() && player.gold >= 1) {
		player.eat();
		player.gold -= 1;
		int numResources = rand() % 5;
		for (int i = 0; i < numResources; ++i){
			int type = rand() % 3;
			if(type == 0)
				player.fabric++;
			else if(type == 1)
				player.spice++;
			else
				player.jewel++;
		}
		return true;
	}
	return false;
}
bool CasinoTile::action(Player& player){
	if(player.canAct() && player.gold >= 1) {
		player.eat();
		player.gold -= 1;
		int n = rand() % 10;
		if(n >= 4 && n <= 6 )
			player.gold += 2;
		else if(n >= 7 && n <= 8)
			player.gold += 3;
		else if(n == 9)
			player.gold += 10;
		return true;
	}
	return false;
}
int MarchandGemmesTile::gemCost = 12;
bool MarchandGemmesTile::action(Player& player){
	if(player.canAct() && player.gold >= MarchandGemmesTile::gemCost) {
		player.eat();
		player.gold -= MarchandGemmesTile::gemCost;
		MarchandGemmesTile::gemCost++;
		player.ruby++;
		return true;
	}
	return false;
}
bool PalaisTile::action(Player& player){
	if(player.canAct() && player.fabric >= 5 && player.spice >= 5 && player.jewel >= 5) {
		player.eat();
		player.fabric -= 5;
		player.spice -= 5;
		player.jewel -= 5;
		player.ruby++;
		return true;
	}
	return false;
}


ostream& operator<<(ostream &out, const Tile& tile){
	// TODO: put something here
}
