#ifndef TILE_H
#define TILE_H

class Tile{
	private:
	public:
		Tile();
		bool operator==(const Tile &t);
		virtual bool action(Player& player);
		virtual Tile* clone();
		ostream& operator<<(ostream &out, const Tile& tile);
};

#endif //TILE_H
