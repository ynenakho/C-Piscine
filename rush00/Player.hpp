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
    int getYLoc();
    int getXLoc();
    Player &operator= (const Player &obj);
    void shoot();
    Bullet	**getBullets() const;
    void drawBullets();

    void newLoc();

  private:
    bool visible;

    int xLoc, yLoc, xMax, yMax;
    char character;
    Bullet **bullets;
};
#endif
