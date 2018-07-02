#ifndef PLAYER_HPP
# define PLAYER_HPP
# include "Bullet.hpp"
# include "GameEntity.hpp"

class Player : public GameEntity{
  public:
    Player();
	Player(Player const & src);
	~Player();
    Player &operator= (const Player &obj);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void display();
    void reset();

    void shoot();
    Bullet	**getBullets() const;
    void drawBullets();
    bool isDead();
    void kill();
    void newLoc();

  private:
    bool dead;
    Bullet **bullets;
};
#endif
