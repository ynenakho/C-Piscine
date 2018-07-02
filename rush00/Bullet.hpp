#ifndef BULLET_HPP
# define BULLET_HPP
# include "GameEntity.hpp"

class Bullet : public GameEntity{
  public:
    Bullet(int y, int x, bool direction);
	Bullet(Bullet const & src);
	~Bullet();
	Bullet &operator=(const Bullet &obj);

    void move(int y, int x);
    static Bullet *getNextBullet(Bullet **bullets, int size);
    void shoot(int y, int x, bool direction);
    void hide();
    bool getDisplay();
    void draw();
    void show();

  private:
    bool direction;
};
#endif
