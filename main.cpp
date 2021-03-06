//Julien Mageau, 6881314
//Nicholas Horton, 6814726

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include <exception>
#include <stdexcept>
#include "gameboard.h"
#include "tile.h"
#include "player.h"


bool isPaused;
bool playerHasWon;
string winnerName;
GameBoard<Tile,Player,6,6> gb;
vector<string> playerNames;

void initializePlayers(){
	int numPlayers;
	cout << "How many players are there? " << endl;
	cin >> numPlayers;
	for (int i(0); i < numPlayers; i++){
		cout << "What is the name of player " << i+1 << "? " << endl;
		string temp;
		cin >> temp;
		playerNames.push_back(temp);
	}
}

GameBoard<Tile,Player,6,6> setup(){
	initializePlayers();

	GameBoard<Tile,Player,6,6> _gb;
	TileFactory *tf= TileFactory::get(6*6);
	for (int i=0;i<6; i++)
		for (int j=0; j<6; j++)
			_gb.add(*tf->next(),i,j);

	for (int i=0;i<6; i++)
		for (int j=0; j<6; j++){

			const Tile *t = &(_gb.getTile(i, j));

			if((*t).type == "RestaurantTile"){
				for (unsigned int x = 0; x < playerNames.size(); ++x){
					_gb.addPlayer(*(new Player(playerNames[x])), i, j);
				}
				return _gb;
			}
		}
	return _gb;
}

bool takeTurn( GameBoard<Tile,Player,6,6> &gb, const std::string &pName) {
	try {
		Move m;
		cin.exceptions(std::istream::failbit);

		int *x = new int;
		int *y = new int;
		gb.getPlayerCoordinate(pName, y, x);
		cout << "You are at coordinate X: " << *x << " Y: " << *y << endl;
		cout << "What is your move?" << endl;
		cin>> m;
		const Tile *t = &(gb.move( m, pName ));
		Player p = gb.getPlayer( pName );

		// si le joueur peut effectuer l’action

		cout << "You arrive at a " << (*t).type << "." << endl << endl;
		if ((p.canAct() && (*t).type != "DesertTile" ) || (*t).type == "RestaurantTile") {

			bool makeAction;
			cout << "Would you like to take an action? (true or false?)" << endl;
			cin>>makeAction;
			if ( makeAction ) {
				std::vector<Player> opL = gb.getPlayers( *t );

				if (p.gold >= opL.size()) {
					// consommer une nourriture
					p.eat();
					// payer les joueurs presents
					// sur la meme tuile
					for ( auto op : opL ) {
						p.pay( op );
						gb.setPlayer( op );
					}
					// effectuer l’action
					t->action( p );
					gb.setPlayer( p );
				}
			}
		}
		return true;
	} catch ( istream::failure e ) {
		cout << "Incorrect key pressed" << endl;
		cin.clear();
	} catch ( out_of_range e ) {
		cout<< e.what();
	}
	return false;
}

void runGame(){
	if (isPaused){
		isPaused = false;
	}else{
		gb = setup();
	}

	while (!playerHasWon){
		if (!isPaused){
			for ( auto pName : playerNames ) {
				do {
					cout << gb;
					cout << gb.getPlayer(pName);
				} while (!takeTurn(gb,pName));
				if ( gb.win(pName) ){
					playerHasWon = true;
					winnerName = pName;
					break;
				}
			}
		}
	}
	cout << winnerName << " has collected enough rubies!" << endl;
	cout << winnerName << " has won the game!" << endl;
}

int main(){
	srand(time(NULL));

	isPaused = false;
	playerHasWon = false;

	runGame();
}

