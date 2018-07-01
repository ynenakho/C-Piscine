#include "Game.hpp"
#include "Enemy.hpp"

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
	this->fps = 60;
	this->time = 0;
	this->spawnTimer = 0;
  this->player.display();
  this->enemies = new Enemy*[20];
   for (int i = 0; i < 20; i++)
     this->enemies[i] = new Enemy;
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
    }
  }
}

void Game::checkEnemy(Enemy &e) {
  if (e.getYLoc() == this->yMax - 1)
    e.hide();
  else if (e.getYLoc() == this->player.getYLoc() && e.getXLoc() == this->player.getXLoc()) {
    e.boom();
    this->player.newLoc();
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

  // mvprintw(this->rows - 1, 5, "FPS: %d", this->fps);
	// mvprintw(this->rows - 1, 29, "TIME: %0.2d:%0.2d", this->time / 60, this->time%60);
	// mvprintw(this->rows - 1, 17, "NEXT: %d", this->spawnTime - this->spawnTimer);
	// mvprintw(this->rows - 1, 45, "SCORE: %d", this->score);
	// mvprintw(this->rows - 1, 60, "LIVES: %d", this->player.getLives());

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
  this->draw();
	int c;
	int frames = 0;
  this->spawnTime = rand() % 3;
	clock_t before = clock();
	clock_t now;
  keypad(stdscr, true);
	while (!this->finished)
	{
		if ((c = getch()) != ERR)
			this->handleKey(c);
	 	this->draw();
    this->spawnEnemy();
	 	now = clock();
		frames++;
		if (((now - before) / CLOCKS_PER_SEC) == 1) // 1 second elapsed
		{
			this->time++;
			this->spawnTimer++;
			before = now;
			this->fps = frames;
			frames = 0;
    }
	// 	// WAIT FOR REST OF 1/60th OF SECOND (or 1/fps'th of a second)
    while(clock() * 60 / CLOCKS_PER_SEC == now * 60 / CLOCKS_PER_SEC) {}
	  }
}



void    Game::handleKey(int c) {
	switch(c) {
		case KEY_LEFT:
	//		if (!player.isDead()) {
				this->player.moveLeft();

				this->checkEnemyCollision();
	//	}
			break;
		case KEY_RIGHT:
	//		if (!player.isDead()) {
				this->player.moveRight();
				this->checkEnemyCollision();
	//		}
			break;
		case KEY_UP:
	//		if (!player.isDead()) {
				this->player.moveUp();
				this->checkEnemyCollision();
	//		}
			break;
		case KEY_DOWN:
	//		if (!player.isDead()) {
				this->player.moveDown();
				this->checkEnemyCollision();
	//		}
			break;
		case ' ':
	//		if (!player.isDead())
				this->player.shoot();
			break;
		case '`':
      exit(0);
	//		this->gameOver();
			break;
	}
}
