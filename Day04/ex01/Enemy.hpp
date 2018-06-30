#ifndef ENEMY_HPP
# define ENEMY_HPP
# include <iostream>

class Enemy {
protected:
    int hitPoints;
    std::string type;
public:
  Enemy();
  Enemy(int hp, std::string const & type);
  Enemy &operator= (const Enemy &obj);
  virtual ~Enemy();
  std::string const getType() const;
  int getHP() const;
  virtual void takeDamage(int);
};

#endif
