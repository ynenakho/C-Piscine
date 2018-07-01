#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <ncurses.h>
//# include "Bullet.hpp"
//# include "Game.hpp"

class Enemy {
  public:
    Enemy();
    //Enemy(int x, int y, int hp);
    //Bullet **bullets;

  //  Enemy(int y, int x, char c);
  	void hide();
  	void reset(); // for reset of hidden to visible 
    //void moveUp();
    void moveDown();
    //void moveLeft();
    //void moveRight();
    int getmv();
    void display();
    int getYLoc();
    int getXLoc();
    int gethp();
    Enemy &operator= (const Enemy &obj);
    //void shoot();
    //Bullet	**getBullets() const;
    void draw();
    //void drawBullets();
	void takeDamage(int dmg);

  private:
    bool visible;
    //int sizeBullets;
    //int maxBullets;
    int xLoc, yLoc, xMax, yMax;
	int hp;
    char character;
//    WINDOW *curwin;
};
#endif
