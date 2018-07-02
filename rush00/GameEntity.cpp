#include "GameEntity.hpp"

GameEntity::GameEntity(char piece) : character(piece){
  getmaxyx(stdscr, this->yMax, this->xMax);
  this->xLoc = this->xMax / 2;
  this->yLoc = this->yMax - 3;
  this->visible = false;
}

GameEntity::~GameEntity() {
}

GameEntity::GameEntity(GameEntity const & src){
	*this = src;
}

GameEntity &GameEntity::operator= (const GameEntity &obj) {
  this->visible = obj.visible;
  this->xLoc = obj.xLoc;
  this->yLoc = obj.yLoc;
  this->yMax = obj.yMax;
  this->xMax = obj.xMax;
  this->character = obj.character;
  return (*this);
}

int GameEntity::getXLoc() {
  return this->xLoc;
}

int GameEntity::getYLoc() {
  return this->yLoc;
}
