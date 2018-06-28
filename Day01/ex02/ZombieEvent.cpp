#include "ZombieEvent.hpp"

void ZombieEvent::setZombieType(std::string type) {
  this->zType = type;
  return;
}

  Zombie* ZombieEvent::newZombie(std::string name) {
    Zombie *zomb = new Zombie(name, this->zType);
    return zomb;
  }

  void ZombieEvent::randomChump() {
    srand(time(0));
    std::string NameArray[10] = {"budz" , "pain" , "konan","nagato", "itachi", "tobi", "madara", "naruto", "danzou", "kakashi"};
    Zombie zomb(NameArray[rand()%10], this->zType);
    zomb.announce();
    return;
  }

  ZombieEvent::ZombieEvent() {
    std::cout << "ZombieEvent created" << std::endl;
    return;
  }

  ZombieEvent::~ZombieEvent() {
    std::cout << "ZombieEvent destroyed" << std::endl;
    return;
  }
