#include <iostream>
#include <ctime>
#include <cstdlib>
#include "gameboard.h"
#include "tile.h"
#include "player.h"
#include <time.h>

bool isPaused;
bool playerHasWon;
GameBoard<Tile,Player,6,6> gb;


GameBoard<Tile,Player,6,6> setup(){
	GameBoard<Tile,Player,6,6> _gb;
	TileFactory *tf= TileFactory.get(6*6);
	for (int i=0;i<6; i++)
		for (int j=0; j<6; j++)
			_gb.add(*tf->next(),i,j);
	return _gb;
}

bool takeTurn( GameBoard<Tile,Player,6,6> &gb, const std::string &pName) {
	try {
			Move m;
		cin.exceptions(std::istream::failbit);

		// quel est le deplacement du joueur ?
		cin>> m;
		const Tile t = gb.move( m, pName );
		Player p = gb.getPlayer( pName );

		// si le joueur peut effectuer l’action
		if (p.canAct()) { //TODO: logic doesn't permit restaurant action if no food
			bool makeAction;
			// lui demander si il desire effectuer l’action
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
		cout << "Incorrect key pressed";
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
		if (!isPaused){                //THIS IS FROM THE INSTRUCTIONS... I THINK IT IS WRONG
			for ( auto pName : playerNames ) {
				do {
					cout<<getPlayer(pName);
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

