#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

enum Move {UP, DOWN, LEFT, RIGHT};
std::istream& operator>>( std::istream& is, Move& i ){
	string tmp;

	if ( is >> tmp ){
		if(tmp == "UP" || tmp == "w"){
			i = UP;
		}else if (tmp == "DOWN" || tmp == "s"){
			i = DOWN;
		}else if (tmp == "LEFT" || tmp == "a"){
			i = LEFT;
		}else if (tmp == "RIGHT" || tmp == "d"){
			i = RIGHT;
		}
	}

		return is;
}

template <typename T, typename J, int X, int Y> //T for tile, J for player, X for horizontal axis, Y for vertical axis
class GameBoard{
	private:
		T (*tileGrid)[X];
		list<J> (*playerGrid)[X];
	public:
		GameBoard(){
			tileGrid = new T[Y][X];
			playerGrid = new list<J>[Y][X];
		}

		GameBoard(const GameBoard& other){
			tileGrid = new T[Y][X];
			playerGrid = new list<J>[Y][X];

			for (int i(0); i < Y; i++)
				for (int j(0); j < X; j++){
					tileGrid[i][j] = other.tileGrid[i][j];
					playerGrid[i][j] = other.playerGrid[i][j];
				}
		}

		void add(const T& tile, int row, int col){
			tileGrid[row][col] = tile;
		}

		const T& getTile(int row, int col) const{
			return tileGrid[row][col];
		}

		void getCoordinate(const T &tile, int *row, int *col) const{
			for (int i(0); i < Y; i++)
				for (int j(0); j < X; j++){
					if (tileGrid[i][j] == tile){
						*row = i;
						*col = i;
						return;
					}
				}
		}

		void addPlayer(J player, int row, int col){
			playerGrid[row][col].push_front(player);
		} // ajoute un joueur sur le plateau

		void setPlayer(J player){
			for (int i(0); i < Y; i++)
				for (int j(0); j < X; j++){
					for (typename list<J>::iterator iterator = playerGrid[i][j].begin(),
						end = playerGrid[i][j].end();
						iterator != end; ++iterator) {
						if (player.name == (*iterator).name){
							*iterator = player;
							return;
						}
					}
				}
		}

		J getPlayer(const string& playerName){
			for (int i(0); i < Y; i++)
				for (int j(0); j < X; j++){
					for (typename list<J>::const_iterator iterator = playerGrid[i][j].begin(),
						end = playerGrid[i][j].end();
						iterator != end; ++iterator) {
						if (playerName == (*iterator).name){
							return *iterator;
						}
					}
				}

			throw "PLAYER NOT FOUND";
		}

		const T& getTile(const string& playerName) const{
			for (int i(0); i < Y; i++)
				for (int j(0); j < X; j++){
					for (typename list<J>::const_iterator iterator = playerGrid[i][j].begin(),
						end = playerGrid[i][j].end();
						iterator != end; ++iterator) {
						if (playerName == (*iterator).name){
							return tileGrid[i][j];
						}
					}
				}
			throw "TILE NOT FOUND";
		}

		vector<J> getPlayers(const T& tile) const{
			for (int i(0); i < Y; i++)
				for (int j(0); j < X; j++){
					if(tileGrid[i][j] == tile){
						vector<J> result{ playerGrid[i][j].begin(), playerGrid[i][j].end() };
						return result;
					}
				}
		}

		const T& move(enum Move move, const string& playerName ){
			T playerTile = getTile(playerName);
			int *x;
			int *y;
			getCoordinate(playerTile, y, x);
			//J player = getPlayer(playerName);
			J player;

			for (typename list<J>::iterator iterator = playerGrid[*y][*x].begin(),
					end = playerGrid[*y][*x].end();
					iterator != end; ++iterator) {
					if (player.name == (*iterator).name){
						player = *iterator;

						switch(move){
							case UP    :
								addPlayer(player, --(*y), *x);
								break;
							case DOWN  :
								addPlayer(player, ++(*y), *x);
								break;
							case LEFT  :
								addPlayer(player, *y, --(*x));
								break;
							case RIGHT :
								addPlayer(player, *y, ++(*x));

						}
						(playerGrid[*y][*x]).erase(iterator);
						break;
					}
			}
			return tileGrid[*y][*x];
		}

		bool win(const string& playerName){
			J player = getPlayer(playerName);
			return player.ruby >= 5;
		}
};

#endif //GAMEBOARD_H
