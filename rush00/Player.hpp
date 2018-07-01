#ifndef PLAYER_HPP
# define PLAYER_HPP
# include <ncurses.h>
# include "Bullet.hpp"

class Player {
  public:
    Player();
    void hide();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void display();
    void reset();


    Player &operator= (const Player &obj);
    void shoot();
    Bullet	**getBullets() const;
    void drawBullets();
    bool isDead();
    void kill();
    void newLoc();

    int getYLoc();
    int getXLoc();

  private:
    bool dead;
    bool visible;
    int xLoc, yLoc, xMax, yMax;
    char character;
    Bullet **bullets;
};
#endif
