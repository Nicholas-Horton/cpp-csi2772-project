#include <iostream>
#include <ctime>
#include <cstdlib>
#include "gameboard.h"
#include "tile.h"
#include "player.h"

bool isPaused;
bool playerHasWon;
GameBoard<Tile,Player,6,6> bg;


GameBoard<Tile,Player,6,6> setup(){
	GameBoard<Tile,Player,6,6> _bg( noPlayers );
	TileFactory *tf= TileFactory.get(6*6);
	for (int i=0;i<6; i++)
		for (int j=0; j<6; j++)
			_bg.add(*tf->next(),i,j);
	return _bg;
}

bool takeTurn( GameBoard<Tile,Player,6,6> &bg, const std::string &pName) {
	try {
			Move m;
		cin.exceptions(std::istream::failbit);

		// quel est le deplacement du joueur ?
		cin>> m;
		const Tile t = bg.move( m, pName );
		Player p = bg.getPlayer( pName );

		// si le joueur peut effectuer l’action
		if (p.canAct()) {
			bool makeAction;
			// lui demander si il desire effectuer l’action
			cin>>makeAction;
			if ( makeAction ) {
				std::vector<Player> opL = bg.getPlayers( t );

				if (p.getGold()>= opL.size()) {
					// consommer une nourriture
					p.eat();
					// payer les joueurs presents
					// sur la meme tuile
					for ( auto op : opL ) {
						p.pay( op );
						bg.setPlayer( op );
					}
					// effectuer l’action
					t.action( p );
					bg.setPlayer( p );
				}
			}
		}
		return true;
	} catch ( std::istream::failure e ) {
		cout<< "Incorrect key pressed"; cin.clear(); }
	} catch ( std::out_of_range e ) {
		cout<< e.what();
	}
	return false;
}

void runGame(){
	if (isPaused){
		isPaused = false;
	}else{
		bg = setup();
	}

	while (!playerHasWon){
		if (!isPaused){                //THIS IS FROM THE INSTRUCTIONS... I THINK IT IS WRONG
			for ( auto pName : playerNames ) {
				do {
					cout<<getPlayer(pName);
				} while (!takeTurn(bg,pName));
				if ( bg.win(pName) ) break;
			}
		}
	}
}

int main(){
	isPaused = false;
	playerHasWon = false;

	runGame();
}

