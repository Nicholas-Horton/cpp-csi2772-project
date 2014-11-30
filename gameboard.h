#ifndef GAMEBOARD_H
#define GAMEBOARD_H

template <class T, class J, int X, int Y> //T for tile, J for player, X for horizontal axis, Y for vertical axis
class GameBoard{
	private:
		
	public:
		void add(const T& tile, int row, int col);
		const T& getTile(int row, int col) const;
		void getCoordinate(const T &tile, int *row, int *col) const;
		void addPlayer(J player, int row, int col); // ajoute un joueur sur le plateau
		void setPlayer(J player); 
		J getPlayer(const std::string& playerName);
		const T& getTile(const std::string& playerName) const;
		std::vector<J> getPlayers(const T& tile) const;
		const T& move(Enum Move move, const std::string& playerName );
};

#endif //GAMEBOARD_H