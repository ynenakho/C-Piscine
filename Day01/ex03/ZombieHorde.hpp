#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP
# include <iostream>
# include "Zombie.hpp"

class ZombieHorde {
private:
  Zombie *zombies;
  int count;

public:
  ZombieHorde(int i);
  ~ZombieHorde();

  void announce();

};

#endif
