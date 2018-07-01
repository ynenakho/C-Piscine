#include "Game.hpp"
#include "Enemy.hpp"

void Game::reset() {
	getmaxyx(stdscr, this->yMax, this->xMax);
	this->finished = false;
	this->time = 0;
	this->spawnTimer = 0;
	this->enemies = new Enemy*[20];
	this->score = 0;
	this->lifes = 1;
	 for (int i = 0; i < 20; i++)
		 this->enemies[i] = new Enemy;
}

void Game::drawObjects() {
	this->player.drawBullets();
  for (int i = 0; i < 10; i++) {
    if (this->enemies[i]->getDisplay()) {
      if (this->enemies[i]->isDead()) {
        this->enemies[i]->boom();
      }
      else
        this->enemies[i]->draw();
    }
  }
}

Game::Game() {
  std::srand(std::time(0));
  getmaxyx(stdscr, this->yMax, this->xMax);
  this->finished = false;
	this->time = 0;
	this->spawnTimer = 0;
  this->enemies = new Enemy*[20];
  this->score = 0;
  this->lifes = 1;
   for (int i = 0; i < 20; i++)
     this->enemies[i] = new Enemy;
}

void Game::addScore() {
  this->score += 25;
}

void Game::checkBullet(Bullet &b) {
  if (b.getYLoc() == 0)
    b.hide();
  for (int i = 0; i < 20; i++) {
    if (this->enemies[i]->getDisplay()) {
      Bullet** bullets = this->player.getBullets();
      for (int j = 0; j < 20; j++) {
        if (bullets[j]->getXLoc() == this->enemies[i]->getXLoc()) {
          if (bullets[j]->getYLoc() == this->enemies[i]->getYLoc()) {
            this->enemies[i]->kill();
            bullets[j]->hide();
            addScore();
          }
        }
      }
    }
  }
}

void Game::checkEnemyCollision() {
  for (int i = 0; i < 20; i++) {
    if (this->enemies[i]->getDisplay() &&
    this->enemies[i]->getXLoc() == this->player.getXLoc()
    && this->enemies[i]->getYLoc() == this->player.getYLoc()) {
      this->enemies[i]->kill();
      this->player.newLoc();
      if (--this->lifes == 0) {
        this->finished = true;
				this->player.kill();
      }

    }
  }
}

void Game::checkEnemy(Enemy &e) {
  if (e.getYLoc() == this->yMax - 1)
    e.hide();
  else if (e.getYLoc() == this->player.getYLoc() && e.getXLoc() == this->player.getXLoc()) {
    e.boom();
    this->player.newLoc();
    if (--this->lifes == 0) {
      this->finished = true;
			this->player.kill();
    }
    e.hide();
  }
}

void    Game::moveObjects() {
	Bullet** b = this->player.getBullets();
	for (int j = 0; j < 20; j++) {
		if (b[j]->getDisplay()) {
			b[j]->move(b[j]->getYLoc() - 1, b[j]->getXLoc());
			this->checkBullet(*b[j]);

		}
	}
	for (int j = 0; j < 20; j++) {
		if (this->enemies[j]->getDisplay() && !this->enemies[j]->isDead()) {
			this->enemies[j]->move(this->enemies[j]->getYLoc() +
      ((((this->enemies[j]->getSlow()) % 8) == 0) ? 1 :0),
      this->enemies[j]->getXLoc());
        this->checkEnemy(*this->enemies[j]);
		}
  }
}

void Game::draw() {
  clear();
  box(stdscr, 0, 0);


	mvprintw(this->yMax - 1, 1, "TIME: %0.2d:%0.2d", this->time / 60, this->time%60);
	mvprintw(this->yMax - 1, 15, "SCORE: %d", this->score);
	mvprintw(this->yMax - 1, 28, "LIVES: %d", this->lifes);

  this->player.display();
  this->moveObjects();
  this->drawObjects();
  refresh();
  return;
}

void	Game::spawnEnemy() {
	int i = 0;

	if (this->spawnTime == this->spawnTimer) {
		this->spawnTimer = 0;
		this->spawnTime = rand() % 3;
		while (this->enemies[i]->getDisplay() && !this->enemies[i]->isDead())
			i++;
		this->enemies[i]->draw();
    this->enemies[i]->setDisplay();
	}
}

void Game::start()
{
	int c;
  this->spawnTime = rand() % 3;
	clock_t before = clock();
	clock_t now;
  keypad(stdscr, true);
	while (!this->player.isDead())
	{
		if ((c = getch()) != ERR)
			this->handleKey(c);
	 	this->draw();
    this->spawnEnemy();
	 	now = clock();
		if (((now - before) / CLOCKS_PER_SEC) == 1) // 1 second elapsed
		{
			this->time++;
			this->spawnTimer++;
			before = now;
    }
		if (this->player.isDead()) {
			nodelay(stdscr, false);
			clear();
			box(stdscr, 0, 0);
			mvprintw(this->yMax / 2 - 4, this->xMax / 2 - 7, "GAME OVER!!!!");
			mvprintw(this->yMax / 2 - 2, this->xMax / 2 - 10, "Your score is: %d", this->score);
			mvprintw(this->yMax / 2, this->xMax / 2 - 5, "New Game?", this->score);
			mvprintw(this->yMax / 2 + 2, this->xMax / 2 - 9, "[ Y ]  or  [ N ]");
			refresh();
			while ((c = getch()) != 'y' && (c != 'n')) {}
			if (c == 'y') {
				this->reset();
				this->player.reset();
				nodelay(stdscr, true);
			}
			else if (c == 'n' || c == '`')
				exit(0);

		}

	// 	// WAIT FOR REST OF 1/60th OF SECOND (or 1/fps'th of a second)
    while(clock() * 60 / CLOCKS_PER_SEC == now * 60 / CLOCKS_PER_SEC) {}
	  }
}

void    Game::handleKey(int c) {
	switch(c) {
		case KEY_LEFT:
				this->player.moveLeft();
				this->checkEnemyCollision();
				break;
		case KEY_RIGHT:
				this->player.moveRight();
				this->checkEnemyCollision();
			break;
		case KEY_UP:
				this->player.moveUp();
				this->checkEnemyCollision();
			break;
		case KEY_DOWN:
				this->player.moveDown();
				this->checkEnemyCollision();
			break;
		case ' ':
				this->player.shoot();
			break;
		case '`':
      exit(0);
			break;
	}
}
