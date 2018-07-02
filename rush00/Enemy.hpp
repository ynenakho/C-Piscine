#ifndef ENEMY_HPP
# define ENEMY_HPP
# include "GameEntity.hpp"

class Enemy : public GameEntity{
  public:
    Enemy();
	  Enemy(Enemy const & src);
	  ~Enemy();
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

  private:
    int boomNum;
    bool dead;
    int slow;
};
#endif
