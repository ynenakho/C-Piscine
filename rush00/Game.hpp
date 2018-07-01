#ifndef GAME_HPP
# define GAME_HPP
# include <ncurses.h>
# include <iostream>
# include "Player.hpp"
//# include "Enemie.hpp"

class Game {
  private:
    bool  finished;
    Player player;
//    Enemie **enemies;
    int time;
    int spawnTimer;
    int fps;
    int yMax;
    int xMax;

  public:
    Game();
    void start();
    void draw();
    void handleKey(int c);
    void drawObjects();
    void moveObjects();
    bool checkBullet(Bullet &b);
};
#endif
