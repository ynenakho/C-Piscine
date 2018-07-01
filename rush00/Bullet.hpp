#ifndef BULLET_HPP
# define BULLET_HPP
# include <ncurses.h>

class Bullet {
  public:
    Bullet(int y, int x, bool direction);
    void move(int y, int x);
    static Bullet *getNextBullet(Bullet **bullets, int size);
    void shoot(int y, int x, bool direction);
    void hide();
    bool getDisplay();
    void draw();
    void show();

    int getYLoc();
    int getXLoc();

  private:
    bool visible;
    bool direction;
    int yLoc;
    int xLoc;
};
#endif
