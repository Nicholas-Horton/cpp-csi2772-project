#include "gameboard.h"

Gameboard::GameBoard(){

}

void Gameboard::add(const T& tile, int row, int col){

}

const T& Gameboard::getTile(int row, int col) const{

}

void Gameboard::getCoordinate(const T &tile, int *row, int *col) const{

}

void Gameboard::addPlayer(J player, int row, int col){

} // ajoute un joueur sur le plateau

void Gameboard::setPlayer(J player){

}

J Gameboard::getPlayer(const std::string& playerName){

}

const T& Gameboard::getTile(const std::string& playerName) const{

}

std::vector<J> Gameboard::getPlayers(const T& tile) const{

}

const T& Gameboard::move(Enum Move move, const std::string& playerName ){

}
