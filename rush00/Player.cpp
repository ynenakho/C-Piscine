#include "Player.hpp"
#include "Game.hpp"

void Player::kill() {
	this->dead = true;
}

void Player::reset() {
	this->newLoc();
	this->dead = false;
}

bool Player::isDead() {
	return this->dead;
}

void Player::drawBullets()
{
	for (int i = 0; i < 20; i++)
		if (bullets[i]->getDisplay())
			bullets[i]->draw();
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
  this->character = obj.character;
  return (*this);
}
  void Player::newLoc() {
    getmaxyx(stdscr, this->yMax, this->xMax);
    this->xLoc = this->xMax / 2;
    this->yLoc = this->yMax - 3;
  }

Player::Player() {
  getmaxyx(stdscr, this->yMax, this->xMax);
  this->xLoc = this->xMax / 2;
  this->yLoc = this->yMax - 3;
  this->character = 'A';
  this->bullets = new Bullet*[20];
  for (int i = 0; i < 20; i++)
	 this->bullets[i] = new Bullet(this->yLoc, this->xLoc, true);
}

void Player::moveUp() {
  this->yLoc = (this->yLoc == this->yMax / 2) ? this->yMax / 2 : this->yLoc - 1;
}

void Player::moveDown() {
  this->yLoc = (this->yLoc == this->yMax - 2) ? this->yMax - 2: this->yLoc + 1;
}

void Player::moveLeft() {
  this->xLoc = (this->xLoc == 1) ? 1 : this->xLoc - 1;
}

void Player::moveRight() {
  this->xLoc = (this->xLoc == this->xMax - 2) ? this->xMax - 2 : this->xLoc + 1;
}

void Player::shoot() {
  Bullet *bullet = Bullet::getNextBullet(this->bullets, 20);
	if (bullet) {
		bullet->shoot(this->yLoc, this->xLoc, true);
    bullet->show();
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
