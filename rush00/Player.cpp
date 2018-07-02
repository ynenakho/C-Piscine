#include "Player.hpp"
#include "Game.hpp"

Player::Player() : GameEntity('A'){
  this->bullets = new Bullet*[20];
  for (int i = 0; i < 20; i++)
	 this->bullets[i] = new Bullet(this->yLoc, this->xLoc, true);
  this->visible = true;
}

Player::~Player() {
	delete [] this->bullets;
}

Player::Player(Player const & src) : GameEntity(src) {
	*this = src;
}

Player &Player::operator= (const Player &obj) {
  this->visible = obj.visible;
  this->xLoc = obj.xLoc;
  this->yLoc = obj.yLoc;
  this->yMax = obj.yMax;
  this->xMax = obj.xMax;
  this->character = obj.character;
  this->dead = obj.dead;
  this->bullets = obj.bullets;
  return (*this);
}

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

  void Player::newLoc() {
    getmaxyx(stdscr, this->yMax, this->xMax);
    this->xLoc = this->xMax / 2;
    this->yLoc = this->yMax - 3;
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



 attron(COLOR_PAIR(1));
  mvwaddch(stdscr, this->yLoc, this->xLoc, this->character);
	attroff(COLOR_PAIR(1));
}
