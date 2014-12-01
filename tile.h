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
		virtual bool action(Player& player) const;
		virtual Tile* clone() const;
};

class RestaurantTile : public Tile {
	public:
		bool action(Player& player);
		Tile* clone() const;
};
class MarchandEpiceTile : public Tile {
	public:
		bool action(Player& player);
		Tile* clone() const;
};
class MarchandTissusTile : public Tile {
	public:
		bool action(Player& player);
		Tile* clone() const;
};
class BijoutierTile : public Tile {
	public:
		bool action(Player& player);
		Tile* clone() const;
};
class FabriquantCharretteTile : public Tile {
	public:
		bool action(Player& player);
		Tile* clone() const;
};
class PetitMarcheTile : public Tile {
	public:
		bool action(Player& player);
		Tile* clone() const;
};
class MarcheEpicesTile : public Tile {
	public:
		bool action(Player& player);
		Tile* clone() const;
};
class MarcheBijouxTile : public Tile {
	public:
		bool action(Player& player);
		Tile* clone() const;
};
class MarcheTissusTile : public Tile {
	public:
		bool action(Player& player);
		Tile* clone() const;
};
class MarcheNoirTile : public Tile {
	public:
		bool action(Player& player);
		Tile* clone() const;
};
class CasinoTile : public Tile {
	public:
		bool action(Player& player);
		Tile* clone() const;
};
class MarchandGemmesTile : public Tile {
	public:
		static int gemCost;
		Tile* clone() const;
		bool action(Player& player);
};
class PalaisTile : public Tile {
	public:
		bool action(Player& player);
		Tile* clone() const;
};
ostream& operator<<(ostream &out, const Tile& tile);


class TileFactory {
	private:
		vector<Tile> tiles;
		TileFactory(int _nTiles);
	public:
		static TileFactory *get(int _nTiles);
		Tile *next();

};

#endif //TILE_H
