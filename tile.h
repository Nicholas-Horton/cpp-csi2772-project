#ifndef TILE_H
#define TILE_H

#include "player.h"
#include <vector>
using namespace std;

class Tile{
	private:
	public:
		Tile();
		bool operator==(const Tile &t);
		virtual bool action(Player& player);
		virtual Tile* clone();
};

class RestaurantTile : public Tile {
	public:
		bool action(Player& player);
};
class MarchandEpiceTile : public Tile {
	public:
		bool action(Player& player);
};
class MarchandTissusTile : public Tile {
	public:
		bool action(Player& player);
};
class BijoutierTile : public Tile {
	public:
		bool action(Player& player);
};
class FabriquantCharretteTile : public Tile {
	public:
		bool action(Player& player);
};
class PetitMarcheTile : public Tile {
	public:
		bool action(Player& player);
};
class MarcheEpicesTile : public Tile {
	public:
		bool action(Player& player);
};
class MarcheBijouxTile : public Tile {
	public:
		bool action(Player& player);
};
class MarcheTissusTile : public Tile {
	public:
		bool action(Player& player);
};
class MarcheNoirTile : public Tile {
	public:
		bool action(Player& player);
};
class CasinoTile : public Tile {
	public:
		bool action(Player& player);
};
class MarchandGemmesTile : public Tile {
	public:
		static int gemCost;
		bool action(Player& player);
};
class PalaisTile : public Tile {
	public:
		bool action(Player& player);
};
ostream& operator<<(ostream &out, const Tile& tile);


class TileFactory {
	private:
		int current;
		vector<Tile> tiles;
		TileFactory(int _nTiles);
	public:
		static TileFactory *get(int _nTiles);
		Tile *next();

};

#endif //TILE_H
