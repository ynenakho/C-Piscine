#include "Bullet.hpp"

void Bullet::draw() {
		mvaddch(this->yLoc, this->xLoc, '*');
}

int Bullet::getYLoc() {
  return this->yLoc;
}
int Bullet::getXLoc() {
  return this->xLoc;
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

Bullet::Bullet(int y, int x, bool direction) {
  this->visible = false;
  this->yLoc = y;
  this->xLoc = x;
  this->direction = direction;

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
