#include "Enemy.hpp"
#include "Game.hpp"

void Enemy::hide() {
	this->dead = false;
	this->boomNum = 0;
	this->visible = false;
	getmaxyx(stdscr, this->yMax, this->xMax);
	this->yLoc = 1;
	this->xLoc = 1 + rand() % (this->xMax - 2);
}

Enemy &Enemy::operator= (const Enemy &obj)
{
	this->xLoc = obj.xLoc;
	this->yLoc = obj.yLoc;
	this->yMax = obj.yMax;
	this->xMax = obj.xMax;
	this->character = obj.character;
	return (*this);
}

  int Enemy::getSlow() {
		if (this->slow > 10000)
			this->slow = 0;
		this->slow++;
		return this->slow;
	}

	void Enemy::boom() {
		if (this->boomNum == 0) {
			mvwaddch(stdscr, this->getYLoc(), this->getXLoc(), '#');
			this->boomNum++;
		}
		else if (this->boomNum == 1) {
			mvwaddch(stdscr, this->getYLoc() - 1, this->getXLoc() -1, '\\');
			mvwaddch(stdscr, this->getYLoc() - 1, this->getXLoc() +1, '/');
			mvwaddch(stdscr, this->getYLoc() + 1, this->getXLoc() -1, '\\');
			mvwaddch(stdscr, this->getYLoc() + 1, this->getXLoc() -1, '/');
			this->boomNum++;
		}
		else if (this->boomNum == 2) {
			mvwaddch(stdscr, this->getYLoc() - 2, this->getXLoc() -2, '\\');
			mvwaddch(stdscr, this->getYLoc() - 2, this->getXLoc() +2, '/');
			mvwaddch(stdscr, this->getYLoc() + 2, this->getXLoc() -2, '\\');
			mvwaddch(stdscr, this->getYLoc() + 2, this->getXLoc() -2, '/');
			this->boomNum++;
			this->hide();
		}
		else {
			mvwaddch(stdscr, this->getYLoc() - 3, this->getXLoc() -3, '*');
			mvwaddch(stdscr, this->getYLoc() - 3, this->getXLoc() +3, '*');
			mvwaddch(stdscr, this->getYLoc() + 3, this->getXLoc() -3, '*');
			mvwaddch(stdscr, this->getYLoc() + 3, this->getXLoc() -3, '*');
			this->boomNum = 0;
			this->hide();
		}
	}

Enemy::Enemy() {
	this->boomNum = 0;
	this->dead = false;
	this->visible = false;
	getmaxyx(stdscr, this->yMax, this->xMax);
	this->yLoc = 1;
	this->xLoc = 1 + rand() % (this->xMax - 2);
	this->character = 'X';
}


void Enemy::move(int y, int x) {
   this->yLoc = y;
   this->xLoc = x;
}

bool Enemy::getDisplay() {
  return this->visible;
}

bool Enemy::isDead() {
	return this->dead;
}

void Enemy::draw() {
	if (this->visible)
		mvwaddch(stdscr, this->yLoc, this->xLoc, this->character);
}

int Enemy::getXLoc() {
	return this->xLoc;
}

int Enemy::getYLoc() {
	return this->yLoc;
}

void Enemy::setDisplay() {
	this->visible = true;
}
void Enemy::kill() {
	this->dead = true;
}
