#include "Game.hpp"


void Game::drawObjects() {
	this->player.drawBullets();
  //...
}

Game::Game() {

  this->finished = false;
	//this->restart = false;
	this->fps = 60;
	this->time = 0;
	this->spawnTimer = 0;
  std::srand(std::time(0));
  getmaxyx(stdscr, this->yMax, this->xMax);
  // this->enemies = new *Enemy[10];
  // for (int i = 0; i < 10; i++) {
  //   this->enemies[i] = new Enemy;
  // }
  this->player.display();
	// for (int i = 0; i < 10; i++) {
	// 	this->enemies[i]->hide();
	// }
	Bullet** b = this->player.getBullets();
	for (int i = 0; i < 20; i++) {
		b[i]->hide();
	}
}

bool Game::checkBullet(Bullet &b) {
  if (b.getYLoc() == 0) {
    b.hide();
    return true;
  }
  return false;
}

void    Game::moveObjects() {
	Bullet** b = this->player.getBullets();
	for (int j = 0; j < this->player.getNumBullets(); j++) {
		if (b[j]->getDisplay()) {
			b[j]->moveUp(b[j]->getYLoc() - 1, b[j]->getXLoc() );
			if (this->checkBullet(*b[j]))
        this->player.setBulletsLess();
		}
	}
}

void Game::draw() {
  clear();
  box(stdscr, 0, 0);
  this->player.display();
  this->moveObjects();
  this->drawObjects();
  refresh();
  return;
}

void Game::start()
{
  this->draw();

	int c;
	int frames = 0;
	clock_t before = clock();
	clock_t now;
	// this->spawnTime = rand() % 4 + 1;
  //
  keypad(stdscr, true);
	while (!this->finished)
	{
		// HANDLE KEYPRESS
		if ((c = getch()) != ERR)
			this->handleKey(c);

	// 	// ATTEMPT TO SPAWN ENEMY / RESPAWN PLAYER
	// 	if (this->player.getDeathCount() == DEATHCOUNTER2)
	//	this->player.display();
  //  this->drawObjects();
	// 	this->spawnEnemy();
	// 	this->chargeEnemies();
	// 	// UPDATE POSITIONS
	// 	this->moveEntities();
	// 	// DRAW
	 	this->draw();
  //
	// 	// CALCULATE TIME AND FPS
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
  //
	// 	// WAIT FOR REST OF 1/60th OF SECOND (or 1/fps'th of a second)

    while(clock() * 60 / CLOCKS_PER_SEC == now * 60 / CLOCKS_PER_SEC) {}
	  }
	// if (this->restart) {
	// 	this->init();
	// 	this->start();
	// }
}

void    Game::handleKey(int c) {
	switch(c) {
		case KEY_LEFT:
	//		if (!player.isDead()) {
				this->player.moveLeft();
          // this->player.display();
          // refresh();
	//			this->checkEnemyCollision();
	//	}
			break;
		case KEY_RIGHT:
	//		if (!player.isDead()) {
				this->player.moveRight();
          // this->player.display();
          // refresh();
	//			this->checkEnemyCollision();
	//		}
			break;
		case KEY_UP:
	//		if (!player.isDead()) {
				this->player.moveUp();
          // this->player.display();
          // refresh();
	//			this->checkEnemyCollision();
	//		}
			break;
		case KEY_DOWN:
	//		if (!player.isDead()) {
				this->player.moveDown();
          // this->player.display();
          // refresh();
	//			this->checkEnemyCollision();
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
