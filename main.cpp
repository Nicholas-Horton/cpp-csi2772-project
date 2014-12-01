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
			const RestaurantTile *r = dynamic_cast<const RestaurantTile*>(t);
			cout << (*t).type << endl;
			if(r != 0){
				for (int x = 0; x < playerNames.size(); ++x){
					_gb.addPlayer(*(new Player(playerNames[x])), i, j);
				}
				break;
			}
		}

	return _gb;
}

bool takeTurn( GameBoard<Tile,Player,6,6> &gb, const std::string &pName) {
	try {
			Move m;
		cin.exceptions(std::istream::failbit);

		// quel est le deplacement du joueur ?
		cout << "What is your move?" << endl;
		cin>> m;
		const Tile t = gb.move( m, pName );
		Player p = gb.getPlayer( pName );

		// si le joueur peut effectuer l’action
		if (p.canAct()) { //TODO: logic doesn't permit restaurant action if no food
			bool makeAction;
			cout << "Would you like to take an action? (true or false?)" << endl;
			cin>>makeAction;
			if ( makeAction ) {
				std::vector<Player> opL = gb.getPlayers( t );

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
					t.action( p );
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
		if (!isPaused){          //THIS IS FROM THE INSTRUCTIONS... I THINK IT IS WRONG
			for ( auto pName : playerNames ) {
				do {
					cout << gb.getPlayer(pName); //IT CRASHES HERE
				} while (!takeTurn(gb,pName));
				if ( gb.win(pName) ) break;
			}
		}
	}
}

int main(){
	srand(time(NULL));

	isPaused = false;
	playerHasWon = false;

	runGame();
}

