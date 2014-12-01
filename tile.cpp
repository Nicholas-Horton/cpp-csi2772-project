#include "tile.h"
#include <algorithm>
#include <stdlib.h>

//Tile
Tile::Tile(){
}

bool Tile::operator==(const Tile &t){
	return false; //TODO: complete
}

bool Tile::action(Player& player) const{
	return true;
}

Tile* Tile::clone() const{
	return new Tile(*this); //TODO: check if valid
}


bool RestaurantTile::action(Player& player){
	player.food = 10;
	return true;
}
bool MarchandEpiceTile::action(Player& player){
	if(player.gold >= 2) {
		player.gold -= 2;
		player.spice += min(player.getNumFreeResources(), 3);
		return true;
	}
	return false;
}
bool MarchandTissusTile::action(Player& player){
	if(player.gold >= 2) {
		player.gold -= 2;
		player.fabric += min(player.getNumFreeResources(), 3);
		return true;
	}
	return false;
}
bool BijoutierTile::action(Player& player){
	if(player.gold >= 2) {
		player.gold -= 2;
		player.jewel += min(player.getNumFreeResources(), 3);
		return true;
	}
	return false;
}
bool FabriquantCharretteTile::action(Player& player){
	if(player.gold >= 7) {
		player.gold -= 7;
		player.cart += 3;
		return true;
	}
	return false;
}
bool PetitMarcheTile::action(Player& player){
	if(player.fabric >= 1 && player.spice >= 1 && player.jewel >= 1) {
		player.fabric -= 1;
		player.spice -= 1;
		player.jewel -= 1;
		player.gold += 8;
		return true;
	}
	return false;
}
bool MarcheEpicesTile::action(Player& player){
	if(player.spice >= 3) {
		player.spice -= 3;
		player.gold += 6;
		return true;
	}
	return false;
}
bool MarcheBijouxTile::action(Player& player){
	if(player.jewel >= 3) {
		player.jewel -= 3;
		player.gold += 6;
		return true;
	}
	return false;
}
bool MarcheTissusTile::action(Player& player){
	if(player.fabric >= 3) {
		player.fabric -= 3;
		player.gold += 6;
		return true;
	}
	return false;
}
bool MarcheNoirTile::action(Player& player){
	if(player.gold >= 1) {
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
	if(player.gold >= 1) {
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
	if(player.gold >= MarchandGemmesTile::gemCost) {
		player.gold -= MarchandGemmesTile::gemCost;
		MarchandGemmesTile::gemCost++;
		player.ruby++;
		return true;
	}
	return false;
}
bool PalaisTile::action(Player& player){
	if(player.fabric >= 5 && player.spice >= 5 && player.jewel >= 5) {
		player.fabric -= 5;
		player.spice -= 5;
		player.jewel -= 5;
		player.ruby++;
		return true;
	}
	return false;
}

Tile* RestaurantTile::clone() const {
	return new RestaurantTile(*this);
}
Tile* MarchandEpiceTile::clone() const {
	return new MarchandEpiceTile(*this);
}
Tile* MarchandTissusTile::clone() const {
	return new MarchandTissusTile(*this);
}
Tile* BijoutierTile::clone() const {
	return new BijoutierTile(*this);
}
Tile* FabriquantCharretteTile::clone() const {
	return new FabriquantCharretteTile(*this);
}
Tile* PetitMarcheTile::clone() const {
	return new PetitMarcheTile(*this);
}
Tile* MarcheEpicesTile::clone() const {
	return new MarcheEpicesTile(*this);
}
Tile* MarcheBijouxTile::clone() const {
	return new MarcheBijouxTile(*this);
}
Tile* MarcheTissusTile::clone() const {
	return new MarcheTissusTile(*this);
}
Tile* MarcheNoirTile::clone() const {
	return new MarcheNoirTile(*this);
}
Tile* CasinoTile::clone() const {
	return new CasinoTile(*this);
}
Tile* MarchandGemmesTile::clone() const {
	return new MarchandGemmesTile(*this);
}
Tile* PalaisTile::clone() const {
	return new PalaisTile(*this);
}


ostream& operator<<(ostream &out, const Tile& tile){
	// TODO: put something here
}

//TileFactory
TileFactory::TileFactory(int _nTiles) {
	for(int i = 0; i < _nTiles; ++i){
		Tile *t;
		int n = rand() % 14;
		switch(n) {
			case 0:
				break;
			case 1:
				t = new RestaurantTile();
				break;
			case 2:
				t = new MarchandEpiceTile();
				break;
			case 3:
				t = new MarchandTissusTile();
				break;
			case 4:
				t = new BijoutierTile();
				break;
			case 5:
				t = new FabriquantCharretteTile();
				break;
			case 6:
				t = new PetitMarcheTile();
				break;
			case 7:
				t = new MarcheEpicesTile();
				break;
			case 8:
				t = new MarcheBijouxTile();
				break;
			case 9:
				t = new MarcheTissusTile();
				break;
			case 10:
				t = new MarcheNoirTile();
				break;
			case 11:
				t = new CasinoTile();
				break;
			case 12:
				t = new MarchandGemmesTile();
				break;
			case 13:
				t = new PalaisTile();
				break;
		}
		tiles.push_back(*t);
	}
}
TileFactory* TileFactory::get(int _nTiles) {
	if(_nTiles < 14)
		return NULL;
	static TileFactory tf(_nTiles);
	return &tf;
}
Tile* TileFactory::next() {
		Tile *t = &(tiles.back());
		tiles.pop_back();
		return t;
}
