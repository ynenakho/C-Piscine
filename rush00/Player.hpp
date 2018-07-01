#ifndef PLAYER_HPP
# define PLAYER_HPP
# include <ncurses.h>
# include "Bullet.hpp"
//# include "Game.hpp"

class Player {
  public:
    Player();
    void hide();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getmv();
    void display();
    int getYLoc();
    int getXLoc();
    Player &operator= (const Player &obj);
    void shoot();
    Bullet	**getBullets() const;
    void draw();
    void drawBullets();
    int getNumBullets();
    void setBulletsLess();

  private:
    bool visible;
    int sizeBullets;
    int maxBullets;
    int xLoc, yLoc, xMax, yMax;
    char character;
    Bullet **bullets;
};
#endif
