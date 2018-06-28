#include "ZombieHorde.hpp"

  ZombieHorde::ZombieHorde(int i) {
    this->zombies = new Zombie[i];
    this->count = i;
    return;
  }

  ZombieHorde::~ZombieHorde() {
    delete [] this->zombies;
    std::cout << "ZombieHorde destroyed" << std::endl;
    return;
  }

  void ZombieHorde::announce() {
    int i = 0;

    while (i < this->count)
      this->zombies[i++].announce();
    return;
  }
