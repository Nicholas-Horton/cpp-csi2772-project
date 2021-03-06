#include "tile.h"
#include <algorithm>
#include <stdlib.h>

//Tile
bool Tile::operator==(const Tile &t){
	return type == t.type;
}

DesertTile::DesertTile(){
	type = "DesertTile";
}
RestaurantTile::RestaurantTile(){
	type = "RestaurantTile";
}
MarchandEpiceTile::MarchandEpiceTile(){
	type = "MarchandEpiceTile";
}
MarchandTissusTile::MarchandTissusTile(){
	type = "MarchandTissusTile";
}
BijoutierTile::BijoutierTile(){
	type = "BijoutierTile";
}
FabriquantCharretteTile::FabriquantCharretteTile(){
	type = "FabriquantCharretteTile";
}
PetitMarcheTile::PetitMarcheTile(){
	type = "PetitMarcheTile";
}
MarcheEpicesTile::MarcheEpicesTile(){
	type = "MarcheEpicesTile";
}
MarcheBijouxTile::MarcheBijouxTile(){
	type = "MarcheBijouxTile";
}
MarcheTissusTile::MarcheTissusTile(){
	type = "MarcheTissusTile";
}
MarcheNoirTile::MarcheNoirTile(){
	type = "MarcheNoirTile";
}
CasinoTile::CasinoTile(){
	type = "CasinoTile";
}
MarchandGemmesTile::MarchandGemmesTile(){
	type = "MarchandGemmesTile";
}
PalaisTile::PalaisTile(){
	type = "PalaisTile";
}


bool DesertTile::action(Player& player) const {
	return true;
}
bool RestaurantTile::action(Player& player) const {
	player.food = 10;
	return true;
}
bool MarchandEpiceTile::action(Player& player) const {
	if(player.gold >= 2) {
		player.gold -= 2;
		player.spice += min(player.getNumFreeResources(), 3);
		return true;
	}
	return false;
}
bool MarchandTissusTile::action(Player& player) const {
	if(player.gold >= 2) {
		player.gold -= 2;
		player.fabric += min(player.getNumFreeResources(), 3);
		return true;
	}
	return false;
}
bool BijoutierTile::action(Player& player) const {
	if(player.gold >= 2) {
		player.gold -= 2;
		player.jewel += min(player.getNumFreeResources(), 3);
		return true;
	}
	return false;
}
bool FabriquantCharretteTile::action(Player& player) const {
	if(player.gold >= 7) {
		player.gold -= 7;
		player.cart += 3;
		return true;
	}
	return false;
}
bool PetitMarcheTile::action(Player& player) const {
	if(player.fabric >= 1 && player.spice >= 1 && player.jewel >= 1) {
		player.fabric -= 1;
		player.spice -= 1;
		player.jewel -= 1;
		player.gold += 8;
		return true;
	}
	return false;
}
bool MarcheEpicesTile::action(Player& player) const {
	if(player.spice >= 3) {
		player.spice -= 3;
		player.gold += 6;
		return true;
	}
	return false;
}
bool MarcheBijouxTile::action(Player& player) const {
	if(player.jewel >= 3) {
		player.jewel -= 3;
		player.gold += 6;
		return true;
	}
	return false;
}
bool MarcheTissusTile::action(Player& player) const {
	if(player.fabric >= 3) {
		player.fabric -= 3;
		player.gold += 6;
		return true;
	}
	return false;
}
bool MarcheNoirTile::action(Player& player) const {
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
bool CasinoTile::action(Player& player) const {
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
unsigned int MarchandGemmesTile::gemCost = 12;
bool MarchandGemmesTile::action(Player& player) const {
	if(player.gold >= MarchandGemmesTile::gemCost) {
		player.gold -= MarchandGemmesTile::gemCost;
		MarchandGemmesTile::gemCost++;
		player.ruby++;
		return true;
	}
	return false;
}
bool PalaisTile::action(Player& player) const {
	if(player.fabric >= 5 && player.spice >= 5 && player.jewel >= 5) {
		player.fabric -= 5;
		player.spice -= 5;
		player.jewel -= 5;
		player.ruby++;
		return true;
	}
	return false;
}

Tile* DesertTile::clone() const {
	return new DesertTile(*this);
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
	if (tile.type == "DesertTile")                     out << "--";
	else if (tile.type == "RestaurantTile")            out << "++";
	else if (tile.type == "MarchandEpiceTile")         out << "E^";
	else if (tile.type == "MarchandTissusTile")        out << "T^";
	else if (tile.type == "BijoutierTile")             out << "B^";
	else if (tile.type == "FabriquantCharretteTile")   out << "C^";
	else if (tile.type == "PetitMarcheTile")           out << "M$";
	else if (tile.type == "MarcheEpicesTile")          out << "E$";
	else if (tile.type == "MarcheBijouxTile")          out << "B$";
	else if (tile.type == "MarcheTissusTile")          out << "T$";
	else if (tile.type == "MarcheNoirTile")            out << "N^";
	else if (tile.type == "CasinoTile")                out << "$$";
	else if (tile.type == "MarchandGemmesTile")        out << "R^";
	else if (tile.type == "PalaisTile")                out << "P$";
	return out;
}

//TileFactory
TileFactory::TileFactory(int _nTiles) {
	int overlap = _nTiles % 14;
	for(int i = 0; i < _nTiles - overlap; ++i){
		Tile *t;
		switch(i%14) {
			case 0:	 t = new DesertTile();              break;
			case 1:  t = new RestaurantTile();          break;
			case 2:	 t = new MarchandEpiceTile();	      break;
			case 3:	 t = new MarchandTissusTile();      break;
			case 4:	 t = new BijoutierTile();	          break;
			case 5:	 t = new FabriquantCharretteTile();	break;
			case 6:	 t = new PetitMarcheTile();	        break;
			case 7:	 t = new MarcheEpicesTile();        break;
			case 8:	 t = new MarcheBijouxTile();        break;
			case 9:	 t = new MarcheTissusTile();        break;
			case 10: t = new MarcheNoirTile();          break;
			case 11: t = new CasinoTile();              break;
			case 12: t = new MarchandGemmesTile();      break;
			case 13: t = new PalaisTile();              break;
			default:                                    break;
		}
		tiles.push_back(t);
	}
	for(int i = 0; i < overlap; ++i)
		tiles.push_back(new DesertTile());
	random_shuffle(tiles.begin(), tiles.end());
}

TileFactory* TileFactory::get(int _nTiles) {
	if(_nTiles < 14)
		return NULL;
	static TileFactory tf(_nTiles);
	return &tf;
}

Tile* TileFactory::next() {
		Tile *t = tiles.back();
		tiles.pop_back();
		return t;
}
