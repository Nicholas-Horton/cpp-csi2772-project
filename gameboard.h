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
			return is;
		}else if (tmp == "DOWN" || tmp == "s"){
			i = DOWN;
			return is;
		}else if (tmp == "LEFT" || tmp == "a"){
			i = LEFT;
			return is;
		}else if (tmp == "RIGHT" || tmp == "d"){
			i = RIGHT;
			return is;
		}
	}

		throw istream::failure("INVALID INPUT");
}

template <typename T, typename J, int X, int Y> //T for tile, J for player, X for horizontal axis, Y for vertical axis
class GameBoard{
	private:
		T*** tileGrid;										//CHECKME
		list<J> (*playerGrid)[X];

		void checkBounds(int rowVal, int colVal) const {
			bool outOfVerticalBounds = rowVal >= Y || rowVal < 0;
			bool outOfHorizontalBounds = colVal >= X || colVal < 0;
			if(outOfVerticalBounds || outOfHorizontalBounds){
				throw out_of_range("Coordinate out of bounds! \n");
			}
		}

	public:
		GameBoard(){
			tileGrid = new T**[Y];											//CHECKME
			for (int i(0); i < Y; ++i){
				tileGrid[i] = new T*[X];
			}

			for (int i = 0; i < Y; ++i) {
			  for (int j = 0; j < X; ++j) {
			    tileGrid[i][j] = NULL;
			  }
			}
			playerGrid = new list<J>[Y][X];
		}

		GameBoard(const GameBoard& other){
			tileGrid = new T**[Y];											//CHECKME
			for (int i(0); i < Y; ++i){
				tileGrid[i] = new T*[X];
			}

			for (int i = 0; i < Y; ++i) {
			  for (int j = 0; j < X; ++j) {
			    tileGrid[i][j] = other.tileGrid[i][j];
			  }
			}

			playerGrid = new list<J>[Y][X];

			for (int i(0); i < Y; i++)
				for (int j(0); j < X; j++){
					tileGrid[i][j] = other.tileGrid[i][j];
					playerGrid[i][j] = other.playerGrid[i][j];
				}
		}

		void add(const T& tile, int row, int col){
			checkBounds(row, col);
			tileGrid[row][col] = tile.clone();										//CHECKME
		}

		const T& getTile(int row, int col) const{
			checkBounds(row, col);
			return *(tileGrid[row][col]);										//CHECKME
		}

		const T& getTile(const string& playerName) const{
			for (int i(0); i < Y; i++)
				for (int j(0); j < X; j++){
					for (typename list<J>::const_iterator iterator = playerGrid[i][j].begin(),
						end = playerGrid[i][j].end();
						iterator != end; ++iterator) {
						if (playerName == (*iterator).name){
							return *(tileGrid[i][j]);										//CHECKME
						}
					}
				}
			throw "TILE NOT FOUND";
		}

		void getCoordinate(const T &tile, int *row, int *col) const{
			for (int i(0); i < Y; i++)
				for (int j(0); j < X; j++){
					if (*(tileGrid[i][j]) == tile){										//CHECKME
						*row = i;
						*col = j;
						return;
					}
				}
			throw "TILE NOT FOUND";
		}

		void getPlayerCoordinate(const string& playerName, int *row, int *col) const{
			for (int i(0); i < Y; i++)
				for (int j(0); j < X; j++){
					for (typename list<J>::const_iterator iterator = playerGrid[i][j].begin(),
						end = playerGrid[i][j].end();
						iterator != end; ++iterator) {
						if (playerName == (*iterator).name){
							*row = i;
							*col = j;
							return;
							}								//CHECKME
					}
				}
			throw "PLAYER NOT FOUND";
		}

		void addPlayer(J player, int row, int col){
			checkBounds(row, col);
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


		vector<J> getPlayers(const T& tile) const{
			for (int i(0); i < Y; i++)
				for (int j(0); j < X; j++){
					if(*(tileGrid[i][j]) == tile){										//CHECKME
						vector<J> result{ playerGrid[i][j].begin(), playerGrid[i][j].end() };
						return result;
					}
				}
			throw "TILE DOES NOT EXIST";
		}

		const T& move(enum Move move, const string& playerName ){
			int *x = new int;
			int *y = new int;
			getPlayerCoordinate(playerName, y, x);

			//J player = getPlayer(playerName);
			J * player = new J();

			for (typename list<J>::iterator iterator = playerGrid[*y][*x].begin(),
					end = playerGrid[*y][*x].end();
					iterator != end; ++iterator) {
					if (playerName == (*iterator).name){
						*player =  *iterator;
						switch(move){
							case UP    :
								addPlayer(*(new J(*player)), *y -= 1, *x);
								break;
							case DOWN  :
								addPlayer(*(new J(*player)), *y += 1, *x);
								break;
							case LEFT  :
								addPlayer(*(new J(*player)), *y, *x -= 1);
								break;
							case RIGHT :
								addPlayer(*(new J(*player)), *y, *x += 1);
								break;
						}
						(playerGrid[*y][*x]).erase(iterator);
						break;
					}
			}
			return *(tileGrid[*y][*x]);
		}

		bool win(const string& playerName){
			J player = getPlayer(playerName);
			return player.ruby >= 5;
		}
};

#endif //GAMEBOARD_H
