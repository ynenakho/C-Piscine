#include "Enemy.hpp"
#include "Game.hpp"

/*
void Enemy::drawBullets()
{
	for (int i = 0; i < sizeBullets; i++)
		//if (bullets[i]->getDisplay())
		bullets[i]->draw();
}

// void Enemy::draw() {
//   if (this->visible) {
// 		int y = this->yLoc;
// 		int x = this->xLoc;
// 		//if (!this->dead) {
// 			// attron(COLOR_PAIR(color));
// 			mvwaddch(stdscr, y, x, 'A'); //show Entity character on the screen
// 			// attroff(COLOR_PAIR(color));
// 		//}
// }
// }

Bullet	**Enemy::getBullets() const {
  return this->bullets;
}
*/

void Enemy::hide()
{
	this->visible = false;
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

//Enemy::Enemy(int x, int y, int hp) : xLoc(x), yLoc(y), hp(hp), character('E')
Enemy::Enemy()
{
	this->visible = true;
	getmaxyx(stdscr, this->yMax, this->xMax);
	this->yLoc = 1;
	this->xLoc = 1 + rand() % (this->xMax - 1);
	this->hp = 100;
	this->character = 'E';
   //bullets = new Bullet*[20];
	//for (int i = 0; i < 20; i++)
		//bullets[i] = new Bullet(this->yLoc, this->xLoc, true);
    //std::cout << this->yLoc << this->xLoc << this->character << std::endl;
}

void Enemy::reset()
{
	this->visible = true;
	getmaxyx(stdscr, this->yMax, this->xMax);
	this->yLoc = 1;
	this->xLoc = 1 + rand() % (this->xMax - 1);
	this->hp = 100;
	this->character = 'E';
}

void Enemy::moveDown()
{
	mvwaddch(stdscr, this->yLoc, this->xLoc, ' ');
	if (this->yLoc == this->yMax - 2)
	{
		this->yLoc = this->yMax -2; // should be deleted at this point or hidden
		this->hp = 0;
		this->visible = false;
	}
	else
  	this->yLoc++;
}

/*
void Enemy::shoot() {
  Bullet *bullet = Bullet::getBullet(bullets, maxBullets);
	if (bullet) {
		bullet->shoot(this->yLoc, this->xLoc, true);
    this->sizeBullets++;
  }
  }
*/

void Enemy::display()
{
	if (this->visible)
		mvwaddch(stdscr, this->yLoc, this->xLoc, this->character);
}

int Enemy::getXLoc()
{
	return this->xLoc;
}

int Enemy::getYLoc()
{
	return this->yLoc;
}

int Enemy::gethp()
{
	return this->hp;
}

void Enemy::takeDamage(int dmg)
{
	if (dmg > 0)
	{
		this-> hp -= dmg;
		if (this->hp < 0)
		{
			this->hp = 0;
			this->visible = false;
		}
	}
}

