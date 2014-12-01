#ifndef TILE_H
#define TILE_H

#include "player.h"
#include <vector>
using namespace std;

class Tile{
	private:
	public:
		bool operator==(const Tile &t);
		virtual bool action(Player& player) const = 0;
		virtual Tile* clone() const = 0;
		string type;
};

class DesertTile : public Tile {
	public:
		DesertTile();
		bool action(Player& player) const;
		Tile* clone() const;
};
class RestaurantTile : public Tile {
	public:
		RestaurantTile();
		bool action(Player& player) const;
		Tile* clone() const;
};
class MarchandEpiceTile : public Tile {
	public:
		MarchandEpiceTile();
		bool action(Player& player) const;
		Tile* clone() const;
};
class MarchandTissusTile : public Tile {
	public:
		MarchandTissusTile();
		bool action(Player& player) const;
		Tile* clone() const;
};
class BijoutierTile : public Tile {
	public:
		BijoutierTile();
		bool action(Player& player) const;
		Tile* clone() const;
};
class FabriquantCharretteTile : public Tile {
	public:
		FabriquantCharretteTile();
		bool action(Player& player) const;
		Tile* clone() const;
};
class PetitMarcheTile : public Tile {
	public:
		PetitMarcheTile();
		bool action(Player& player) const;
		Tile* clone() const;
};
class MarcheEpicesTile : public Tile {
	public:
		MarcheEpicesTile();
		bool action(Player& player) const;
		Tile* clone() const;
};
class MarcheBijouxTile : public Tile {
	public:
		MarcheBijouxTile();
		bool action(Player& player) const;
		Tile* clone() const;
};
class MarcheTissusTile : public Tile {
	public:
		MarcheTissusTile();
		bool action(Player& player) const;
		Tile* clone() const;
};
class MarcheNoirTile : public Tile {
	public:
		MarcheNoirTile();
		bool action(Player& player) const;
		Tile* clone() const;
};
class CasinoTile : public Tile {
	public:
		CasinoTile();
		bool action(Player& player) const;
		Tile* clone() const;
};
class MarchandGemmesTile : public Tile {
	public:
		MarchandGemmesTile();
		static unsigned int gemCost;
		Tile* clone() const;
		bool action(Player& player) const;
};
class PalaisTile : public Tile {
	public:
		PalaisTile();
		bool action(Player& player) const;
		Tile* clone() const;
};
ostream& operator<<(ostream &out, const Tile& tile);


class TileFactory {
	private:
		vector<Tile*> tiles;
		TileFactory(int _nTiles);
	public:
		static TileFactory *get(int _nTiles);
		Tile *next();

};

#endif //TILE_H
