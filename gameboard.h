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
		list<J> **playersGrid;
	public:
		GameBoard(){
			tileGrid = new T[Y][X];
			playerGrid = new list<J>
		};

		GameBoard(const GameBoard& other){
			tileGrid = new T[Y][X];
			playerGrid = new list<J>[Y][X];

			for (int i(0); i < Y; i++)
				for (int j(0); j < X; j++){
					tileGrid[i][j] = other.tileGrid[i][j];
					playerGrid[i][j] = other.playerGrid[i][j];
				}
		};

		void add(const T& tile, int row, int col){
			tileGrid[row][col] = tile;
		};

		const T& getTile(int row, int col) const{
			return T[row][col];
		};

		void getCoordinate(const T &tile, int *row, int *col) const{
			for (int i(0); i < Y; i++)
				for (int j(0); j < X; j++){
					if (tileGrid == tile){
						*row = i;
						*col = i;
						return;
					}
				}
		};

		void addPlayer(J player, int row, int col){

		}; // ajoute un joueur sur le plateau

		void setPlayer(J player){

		};

		J getPlayer(const std::string& playerName){

		};

		const T& getTile(const std::string& playerName) const{

		};

		std::vector<J> getPlayers(const T& tile) const{

		};

		const T& move(Enum Move move, const std::string& playerName ){

		};
};

#endif //GAMEBOARD_H
