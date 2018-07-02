#include "Bullet.hpp"

Bullet::Bullet(int y, int x, bool direction) : GameEntity('*'){
  this->visible = false;
  this->yLoc = y;
  this->xLoc = x;
  this->direction = direction;
}

Bullet::~Bullet() {
}

Bullet::Bullet(Bullet const & src) : GameEntity(src) {
	*this = src;
}

Bullet &Bullet::operator=(const Bullet &obj)
{
	this->visible = obj.visible;
	this->xLoc = obj.xLoc;
	this->yLoc = obj.yLoc;
	this->yMax = obj.yMax;
	this->xMax = obj.xMax;
	this->character = obj.character;
	this->direction = obj.direction;
	return (*this);
}

void Bullet::draw() {
		mvaddch(this->yLoc, this->xLoc, '*');
}

bool Bullet::getDisplay() {
  return this->visible;
}

void Bullet::show() {
  this->visible = true;
}

void Bullet::hide() {
	this->visible = false;
}


Bullet *Bullet::getNextBullet(Bullet **bullets, int size) {
  for(int i = 0; i < size; i++)
  {
    if (!bullets[i]->visible)
      return bullets[i];
  }
  return NULL;
}

void Bullet::shoot(int y, int x, bool direction) {
  if (direction)
    this->move(y - 1, x);
  else
    this->move(y + 1, x);
}

void Bullet::move(int y, int x) {
   this->yLoc = y;
   this->xLoc = x;
}
