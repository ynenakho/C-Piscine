#ifndef GAME_HPP
# define GAME_HPP
# include <ncurses.h>
# include <iostream>
# include "Player.hpp"
# include "Enemy.hpp"

class Game {
  private:
    bool finished;
    Player player;
    Enemy **enemies;
    int time;
    int spawnTimer;
    int spawnTime;
    int yMax;
    int xMax;
    int score;
    int lifes;
  //  WINDOW *win;

  public:
    Game();
    void start();
    void draw();
    void handleKey(int c);
    void drawObjects();
    void moveObjects();
    void checkBullet(Bullet &b);
    void spawnEnemy();
    void checkEnemy(Enemy &e);
    void checkEnemyCollision();
    void addScore();
    void reset();

};
#endif
