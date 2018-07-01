#include "Player.hpp"
#include "Game.hpp"

void Player::drawBullets()
{
	for (int i = 0; i < sizeBullets; i++)
		if (bullets[i]->getDisplay())
			bullets[i]->draw();
}

int Player::getNumBullets() {
  return this->sizeBullets;
}

Bullet	**Player::getBullets() const {
  return this->bullets;
}

void Player::hide() {
	this->visible = false;
}

Player &Player::operator= (const Player &obj) {
  this->xLoc = obj.xLoc;
  this->yLoc = obj.yLoc;
  this->yMax = obj.yMax;
  this->xMax = obj.xMax;
  this->maxBullets = obj.maxBullets;
  this->character = obj.character;
  return (*this);
}

Player::Player() {
  this->maxBullets = 20;
  this->sizeBullets = 0;
  getmaxyx(stdscr, this->yMax, this->xMax);
  this->xLoc = this->xMax / 2;
  this->yLoc = this->yMax - 3;
  this->character = 'A';
  bullets = new Bullet*[20];
  for (int i = 0; i < 20; i++)
	 bullets[i] = new Bullet(this->yLoc, this->xLoc, true);
}

void Player::moveUp() {
  this->yLoc = (this->yLoc == 20) ? 20 : this->yLoc- 1;
}

void Player::moveDown() {
  this->yLoc = (this->yLoc == this->yMax - 2) ? this->yMax - 2: this->yLoc+1;
}

void Player::moveLeft() {
  this->xLoc = (this->xLoc == 1) ? 1 : this->xLoc - 1;
}

void Player::moveRight() {
  this->xLoc = (this->xLoc == this->xMax - 2) ? this->xMax - 2 : this->xLoc+1;
}

void Player::setBulletsLess() {
  this->sizeBullets--;
}

void Player::shoot() {
  Bullet *bullet = Bullet::getBullet(bullets, maxBullets);
	if (bullet) {
		bullet->shoot(this->yLoc, this->xLoc, true);
    bullet->show();
    this->sizeBullets++;
  }
}

void Player::display() {
  mvwaddch(stdscr, this->yLoc, this->xLoc, this->character);
}

int Player::getXLoc() {
  return this->xLoc;
}

int Player::getYLoc() {
  return this->yLoc;
}
