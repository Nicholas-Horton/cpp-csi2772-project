#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>
#include <list>
#include <vector>

using namespace std;

enum Move {UP, DOWN, LEFT, RIGHT};

template <typename T, typename J, int X, int Y> //T for tile, J for player, X for horizontal axis, Y for vertical axis
class GameBoard{
	private:
		T **tileGrid;
		list<J> **playerGrid;
	public:
		GameBoard(){
			tileGrid = new T[Y][X];
			playerGrid = new list<J>
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
			return T[row][col];
		}

		void getCoordinate(const T &tile, int *row, int *col) const{
			for (int i(0); i < Y; i++)
				for (int j(0); j < X; j++){
					if (tileGrid == tile){
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
					for (std::list<J>::const_iterator iterator = playerGrid[i][j].begin(),
						end = playerGrid[i][j].end();
						iterator != end; ++iterator) {
						if (player.name == *iterator.name){
							*iterator = player;
							return;
						}
					}
				}
		}

		J getPlayer(const std::string& playerName){
			for (int i(0); i < Y; i++)
				for (int j(0); j < X; j++){
					for (std::list<J>::const_iterator iterator = playerGrid[i][j].begin(),
						end = playerGrid[i][j].end();
						iterator != end; ++iterator) {
						if (player.name == *iterator.name){
							return *iterator;
						}
					}
				}
		}

		const T& getTile(const std::string& playerName) const{
			for (int i(0); i < Y; i++)
				for (int j(0); j < X; j++){
					for (std::list<J>::const_iterator iterator = playerGrid[i][j].begin(),
						end = playerGrid[i][j].end();
						iterator != end; ++iterator) {
						if (player.name == *iterator.name){
							return tileGrid[i][j];
						}
					}
				}
		}

		std::vector<J> getPlayers(const T& tile) const{
			for (int i(0); i < Y; i++)
				for (int j(0); j < X; j++){
					if(tileGrid[i][j] == tile){
						return std::vector<J> result{std::begin(playerGrid[i][j]), std::end(playerGrid[i][j])};
					}
				}
		}

		const T& move(enum Move move, const std::string& playerName ){

		}
};

#endif //GAMEBOARD_H
