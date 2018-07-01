#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <ncurses.h>

class Enemy {
  public:
    Enemy();
    Enemy &operator= (const Enemy &obj);
  	void hide();
    void move(int y, int x);

    void draw();
    bool getDisplay();
    bool isDead();
    void setDisplay();
    int getSlow();
    void kill();
    void boom();

    int getYLoc();
    int getXLoc();

  private:
    int boomNum;
    bool dead;
    bool visible;
    int slow;
    int xLoc, yLoc, xMax, yMax;
    char character;
};
#endif
